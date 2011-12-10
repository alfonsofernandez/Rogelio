#include "Pantalla.h"
// Incluimos cabeceras para números aleatorios y retardos
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <string>                    
using namespace STDP;
Pantalla::Pantalla(){

    this->pijo.init();
    this->pijo.clearScreen();
    this->pijo.setGlobalEscapeDelay(0); 


   // this->actualizar();
    sleep(1);
}

int Pantalla::leer_entrada(){
    return this->pijo.getKey();
}


void Pantalla::actualizar(){
    this->pijo.clearScreen();

    for(int y =0;y <KALTOTOTAL;y++){
      for(int x =0;x<KANCHOTOTAL;x++){
	  this->pijo.setCursor(x,y );
          this->pijo.writeChar(this->coor[x][y]);
      }
    }
    this->pijo.refreshScr();
}


void Pantalla::mostrar_cuadro_texto(string mensaje){
     this->pijo.setCursor(0,20);       
     this->pijo.writeStr("________________________________________________________________________________");
     this->pijo.setCursor(0,21);       
     this->pijo.writeStr("|                                                                              |");
     this->pijo.setCursor(0,22);       
     this->pijo.writeStr("|                 ROUGE                                                        |");
     this->pijo.setCursor(0,23);       
     this->pijo.writeStr("|______________________________________________________________________________|");

}

void Pantalla::ver_menu(){
	int pos_y=5;
	int pos_x=20;

  	this->pijo.setCursor(pos_x,pos_y++ );
        this->pijo.writeStr("MENU PRINCIPAL");
        this->pijo.setCursor(pos_x,pos_y++ );
        this->pijo.writeStr("----------------");

        this->pijo.setCursor(pos_x,pos_y++);
        this->pijo.writeStr("1 CONTINUAR");

        this->pijo.setCursor(pos_x,pos_y++ );
        this->pijo.writeStr("2 SALIR");
 	this->pijo.setCursor(pos_x,pos_y++ );
        this->pijo.writeStr("----------------");
}

/**
* Devuelve el array de coordenadas con el contenido de un fichero
* copiado caracter a caracter
*/
void Pantalla::deFichero(string nomFich){
	ifstream fichero;                               //Gestionar fichero
	string cadena;                                  //Cadena para mostrar por pantalla	
	
	fichero.open(nomFich.c_str(),ios::in);               //Abrir fichero   //Leer primera linea    

 	for(int y=0;y<KALTOTOTAL;y++){
		//Leer una linea del fichero
		getline(fichero,cadena); 
		//Meterla caracter a caracter en el array de pantalla
		for(int x=0;x<KANCHOTOTAL;x++)
			this->coor[x][y] = cadena.at(x);
	}
}

/**
 * Crea una notificacion en pantalla de 25 por 25
 */
void Pantalla::notifica(string nomFich){
	ifstream fichero;                               //Gestionar fichero
	string cadena;                                  //Cadena para mostrar por pantalla

	fichero.open(nomFich.c_str(),ios::in);               //Abrir fichero   //Leer primera linea

 	for(int y=0;y<25;y++){
		//Leer una linea del fichero
		getline(fichero,cadena);
		//Meterla caracter a caracter en el array de pantalla
		for(int x=0;x<25;x++)
			this->coor[x][y] = cadena.at(x);
	}
}


void Pantalla::Test(){
 
    // Esperamos hasta que el usuario pulse Escape, escribiendo
    // caracteres en pantalla mientras.
        // Ponemos el cursor en posición aleatoria encima del mensaje
        unsigned int x = rand() % 60 + 1;
        unsigned int y = rand() % 15 + 1; 
        this->pijo.setCursor(x, y);

        // Y escribimos un asterisco
        this->pijo.writeChar('*');

        // Pequeño retardo
        usleep(1000);

        // Borramos el asterisco el 90% de las veces
        if (rand() % 100 < 90) {
            this->pijo.setCursor(x, y);
            this->pijo.writeChar(' ');
        }

        // Refrescamos la pantalla para asegurarnos de que
        // se ven los últimos cambios
        this->pijo.refreshScr();
    

    // Restauramos el estado original del terminal
 //   this->pijo.end();
}
