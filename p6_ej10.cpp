#include "icom_helpers.h"

struct StatWords {

    struct StatRecord{
        string word; // palabra en si
        unsigned int repCnt; // cantidad de repeticiones
    };

    vector<StatRecord> records;

    void addWord(const string &word){
        bool b = true;

        for (int i = 0; i < records.size(); i++){
            if (records[i].word == word){
                records[i].repCnt++;
                b = false;
                break;
            }
        }

        if (b)
            records.push_back({word,1});
    }

    void print(){
        for (int i = 0; i < records.size(); i++){
            cout << records[i].word << "\t" << records[i].repCnt << endl;
        }
    }
};

int main(){
    StatWords stats;
    string w;

    cout << "Ingrese Ctrl + Shift + Z cuando quiera cortar el conteo y ver las estadisticas finales" << endl;

    while (cin >> w)
        stats.addWord(w);

    stats.print();

    return 0;
}
