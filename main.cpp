#include "Juego.h" 
#include <iostream>

using namespace STDP;


int main(int argc, char const* argv[])
{

    Juego juego;
    int tecla;
    bool mostrar_menu;
    mostrar_menu=false;

    tecla=0;
    while(true){
    	tecla = juego.leer_entrada();
    	// q 113 w 119 e 101 a 97 d 100 z 122 x 120
    	juego.actualizar(tecla);

    	//while(tecla!=113 || tecla!=119 || tecla!=101 || tecla!=97 || tecla!=100 || tecla!=122 || tecla!=120 )



    	//    	if(mostrar_menu)
    	//    		pantalla1.notifica("objetos/espada.pan");

    	//  	tecla=pantalla1.getKey();
    	//	    	if(tecla==KESCAPE) mostrar_menu = !mostrar_menu;


          usleep(1000);

    	//	case  97: if(this->posx>0)	 this->posx--; break;
    	//	case 100: if(this->posx<4)       this->posx++; break;
    	//	case 115: if(this->posy<9)	 this->posy++; break;
    	//	case 119: if(this->posy>0)	 this->posy--; break;


 
    }

}
