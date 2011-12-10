#include <stdlib.h>
#include "definitions.h"   
#include "StdPijo.h"   
#include <string>   
  
using namespace STDP;
const int KANCHOTOTAL = 80;
const int KALTOTOTAL  = 24;
const int KNUMOBJETOS = 5;
                                 
typedef   int    Coor[KANCHOTOTAL][KALTOTOTAL]; //cordenadas                          
typedef   int    Pos[2]; //Posicion con poscion[0] == x pos[1]==y

class Pantalla : StdPijo{

    public:
        Pantalla();
        void Test();
        StdPijo pijo;
    	int width;
    	int height;
        Coor coor;
        int leer_entrada();
    	void deFichero(string);
    	void actualizar();
    	void notifica(string nomFich);
    private:
	void mostrar_cuadro_texto(string mensaje);    
	void ver_menu();

};
	
