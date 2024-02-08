#include "icom_helpers.h"

struct STM_image {
unsigned int width;
unsigned int height;
vector<unsigned short> pixels;

STM_image(int w, int h) : width(w), height(h), pixels({}) {}



unsigned int ij2index(int i, int j) {
assert(i >= 0 && i < (int) width && j >= 0 && j < (int) height);
unsigned int pixelIndex = i * width + j;
assert(pixelIndex < pixels.size());
return pixelIndex;
}
unsigned short getPixel(int i, int j) {
unsigned int pixelIndex = ij2index(i, j);
return pixels[pixelIndex];
}
void setPixel(int i, int j, unsigned short value) {
unsigned int pixelIndex = ij2index(i, j);
pixels[pixelIndex] = value;
}

void print()
{
 
  for(int i=0; i<height; i++)
  {
   for(int j = 0; j<width; j++)
      cout << getPixel(i,j) << " ";
   
   cout << endl;
 }
 

}


};


struct Punto2D {
int x, y;
};
struct IslaGrafeno {
vector<Punto2D> puntos;
};

void FloodFill(int X, int Y, IslaGrafeno &isla, STM_image &img,unsigned short barrera);
struct GrafenoAnalizer {

GrafenoAnalizer(unsigned short threshold_) {
threshold = threshold_;
}
vector<IslaGrafeno> analize(STM_image img){


unsigned int height = img.height;
unsigned int width = img.width;
unsigned short valor;
vector<IslaGrafeno> islas; 

for(int i = 0; i<height; i++)
for(int j = 0; j<width; j++)
{
   valor = img.getPixel(i,j);
   
   if(valor>threshold)
      {
        IslaGrafeno islita;
        FloodFill(i,j,islita,img,threshold);

        islas.push_back(islita);  
      }


}

return islas;
}

unsigned short threshold;
};


void FloodFill(int X, int Y, IslaGrafeno &isla, STM_image &img,unsigned short barrera)
{
 if(img.getPixel(X,Y)>barrera)
 {
 img.setPixel(X,Y,0);   
 isla.puntos.push_back({X,Y});
 }
 else return;
   if(X<img.height-1)
   FloodFill(X+1,Y,isla,img,barrera);
  
   if(Y<img.width-1)
   FloodFill(X,Y+1,isla,img,barrera);
  
   if(X>0)
   FloodFill(X-1,Y,isla,img,barrera);
   if(Y>0)
   FloodFill(X,Y-1,isla,img,barrera);
  
}

int main() {

    GrafenoAnalizer A(2);

    STM_image IMG(6,6);
    srand(time(0));
    for(int i=0; i<36; i++)
        IMG.pixels.push_back(rand()%10+1);

    cout <<"veamos img" <<endl;
    IMG.print();
   
  vector<IslaGrafeno> v= A.analize(IMG);

    cout <<"Se encontraron " <<(int)v.size() <<" islas de grafeno" <<endl;





    return 0;
}






/*Para encontrar las islas se puede recorrer la imagen pixel a pixel. Si el valor de un pixel [Fila, Columna] es
mayor que un nivel de disparo dado threshold, entonces se ha encontrado una isla: se procede a encontrar
todos sus puntos almacenándolos en una IslaGrafeno y se continúa recorriendo el vector de pixeles.
HINT: Una vez ubicada una isla piense en utilizar un algoritmo parecido al FloodFill visto en la práctica para ir
encontrando los puntos, pintándolos como para evitar que vuelva a ser encontrados y agregándolos al
vector que definirá la isla. */