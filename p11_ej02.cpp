#include "icom_helpers.h"

struct STM_image {
    unsigned int width;
    unsigned int height;
    vector<unsigned short> pixels;

    STM_image (unsigned int a, unsigned int b, vector<unsigned short> p){
        width = a;
        height = b;
        pixels = p;
    }

    unsigned int ij2index(int i, int j) const {
        assert(i >= 0 && i < (int) width && j >= 0 && j < (int) height);
        unsigned int pixelIndex = i * width + j;
        assert(pixelIndex < pixels.size());
        return pixelIndex;
    }

    unsigned short getPixel(int i, int j) const {
        //cout << "getPixel\ti = " << i << "\tj = " << j << '\n';
        unsigned int pixelIndex = ij2index(i, j);
        return pixels[pixelIndex];
    }

    void setPixel(int i, int j, unsigned short value) {
        unsigned int pixelIndex = ij2index(i, j);
        pixels[pixelIndex] = value;
    }
};

struct Punto2D {
    int x, y;
    Punto2D (int a, int b){
        x = a;
        y = b;
    }

    bool operator==(Punto2D p){
        if (x == p.x && y == p.y)
            return true;

        return false;
    }
};

struct IslaGrafeno {
    vector<Punto2D> puntos;

//    IslaGrafeno (Punto2D p){
//        puntos.push_back(p);
//    }
};


struct GrafenoAnalizer {
    GrafenoAnalizer(unsigned short threshold_) { //constructor
        threshold = threshold_;
    }

    vector<IslaGrafeno> analize(STM_image img){
        vector<IslaGrafeno> resultado;
        for (unsigned short i = 1; i < img.width; i++){
            for (unsigned short j = 1; j < img.height; j++){
                //cout << "if en analize\n";
                if (img.getPixel(i,j) > threshold){
                    IslaGrafeno isla;
                    FindIsla(isla, img, i, j);
                    resultado.push_back(isla);
                }
            }
        }

        return resultado;
    }
  private:
    void FindIsla (IslaGrafeno &isla, STM_image &img, int i, int j){
            //cout << "en analize\n\n";
            if(img.getPixel(i,j) > threshold){
                img.setPixel(i,j,0);
                isla.puntos.push_back(Punto2D(i,j)); //agrego el punto a la isla

                if (j+1 < (int)img.height )
                    FindIsla(isla, img, i, j+1);     //y analizo los de alrededor con recursion
                if (i+1 < (int)img.width)
                    FindIsla(isla, img, i+1, j);
                if (j-1 > 0)
                    FindIsla(isla, img, i, j-1);
                if (i-1 > 0)
                    FindIsla(isla, img, i-1, j);
            }

    }



    unsigned short threshold;
};

int main(){
    srand(time(0));

    unsigned short a=20, b=20;
    vector<unsigned short> p;
    for (int i = 0; i < a*b-10; i++) //para meter 10 puntos de grafeno
        p.push_back(rand()% 100);

    p.at(45)=110;
    p.at(46)=160;
    p.at(60)=203;
    p.at(61)=900;
    p.at(64)=102;
    p.at(65)=115;
    p.at(69)=130;
    p.at(70)=350;
    p.at(71)=193;
    p.at(84)=721;           //armo mi imagen con 10 puntos de grafeno (en 2 islas)

    STM_image im(a, b, p);

    GrafenoAnalizer grAn(100); //estructura con th = 100

    vector<IslaGrafeno> mostrar = grAn.analize(im);

    for (IslaGrafeno ig : mostrar){
        for (Punto2D p : ig.puntos)
            cout << p.x << '\t' << p.y << '\n';
        cout << "\n\n\n";
    }

    return 0;
}
