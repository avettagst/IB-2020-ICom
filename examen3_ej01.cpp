#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream> //incluida para usar cout para probar funcionamiento del programa

using namespace std;


using Transaction = int;

struct Block_data
{
    static const unsigned N = 32;
    Block_data(unsigned pcrc) : prevCRC(pcrc) {}
    unsigned prevCRC;      // checksum del bloque previo, 0 si es el primer bloque
    Transaction transactions[N] = { 0 }; // transacciones del bloque
};

struct Block
{
    Block(unsigned crc) : data(crc), pNext(nullptr) {}
    Block_data data;			// bloque de datos
    Block* pNext;	      // siguiente bloque en la cadena

    ~Block()
    {
        if (pNext)        //si no es nulo
            delete pNext; //blockchain elimina al primero y luego se eliminan todos en cadena
    }

    bool checkRec();

};

unsigned genCRC(const Block_data* pBlockData);

bool Block::checkRec()
{
    if (!pNext)
        return true;                                //si llegué al final sin devolver false, gané

    if (genCRC(&this->data) != pNext->data.prevCRC) //si pNext no es nulo y los CRC no coinciden, cadena inválida
        return false;
    else
        return pNext->checkRec();                   //si pNext no es nulo y sigue valiendo, sigo investigando

}

class BlockChain
{
public:
    // Crea una nueva cadena de bloques y la inicializa como vacía
    BlockChain() // TODO
    : firstBlock(new Block(0)), currBlock(firstBlock), currTransacIdx(0){} //al construir el blockchain curr y first son el mismo
                                                                           //no es necesario constructor copia de Block porque
                                                                           //especificamente quiero que firstBlock y currBlock
                                                                           //apunten al mismo lugar

    // destruye una cadena de bloques liberando todos
    // los recursos asociados
    ~BlockChain() // TODO
    {
        delete firstBlock;      //esto llamará al destructor de firstBlock, que borrará al siguiente, así hasta el final
    }

    // Agrega una nueva transacción a la cadena
    void addTransaction(Transaction t)  // TODO
    {
        if(currTransacIdx != 0 && currTransacIdx % 32 == 0)        //no es 0 y es múltiplo de 32
        {
            Block* nuevo = new Block(genCRC(&currBlock->data));    //aloco un nuevo bloque cuyo prevCRC es el CRC del actual
            currBlock->pNext = nuevo;                              //y apunto desde currBlock al nuevo
            currBlock = nuevo;                                     //ahora el actual es mi currBlock
        }
        else
        {
            currBlock->data.transactions[currTransacIdx%32] = t;         //si no cambio de bloque, agrego la transacción en
                                                                         //mi currBlock en una posición entre 0 y 31
        }
        currTransacIdx++;
    }

    // función que devuelve verdadero o falso indicando la validez de la cadena
    bool chainValid()  // TODO
    {
        if(firstBlock->data.prevCRC != 0)
            return false;

        return firstBlock->checkRec();
    }

private:
    Block* firstBlock;		   // primer bloque de la cadena
    Block* currBlock;	       // bloque en generación
    unsigned currTransacIdx;   // índice de transacción dentro de currBlock
};


static unsigned crc32_for_byte(unsigned int  r)
{
    for (int j = 0; j < 8; ++j)
        r = (r & 1 ? 0 : (unsigned )0xEDB88320L) ^ r >> 1;
    return r ^ (unsigned )0xFF000000L;
}

static void crc32(const void* data, size_t n_bytes, unsigned * crc)
{
    static unsigned   table[0x100];
    if (!table[0])
        for (size_t i = 0; i < 0x100; ++i)
            table[i] = crc32_for_byte(i);
    for (size_t i = 0; i < n_bytes; ++i)
        *crc = table[(unsigned char)*crc ^ ((unsigned char*)data)[i]] ^ *crc >> 8;
}

unsigned  genCRC(const Block_data* pBlockData)
{
    unsigned  crc = 0;
    crc32(pBlockData, sizeof(Block_data), &crc);
    return crc;
}


int main()
{
    srand((unsigned ) time(NULL));
    BlockChain bc;
    int count = 10000;
    while (count--)
        bc.addTransaction(rand());

    assert(bc.chainValid());

    return 0;
}
