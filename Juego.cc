#include "Juego.h"
Juego::Juego(){

  this->terminado=false;

  this->p.deFichero("pantallas/pantalla1.pan");
  this->p.actualizar();


  //Espada

   this->objs[0].setForma('@');
   this->objs[0].pos(33,4);

   this->objs[1].setForma('!');
   this->objs[1].pos(33,6);

   this->objs[2].setForma('g');
   this->objs[2].energia=3;
   this->objs[2].pos(33,8);

   this->objs[3].setForma('$');
   this->objs[3].pos(30,9);

   this->objs[4].setForma('$');
   this->objs[4].pos(36,9);


   this->objs[5].setForma('<');
   this->objs[5].pos(30,9);
}


bool Juego::ha_terminado(){ 	
  return false;
}

int Juego::leer_entrada(){
	return this->p.leer_entrada();
}

void Juego::actualizar(int tecla){
	int x_back,y_back;
	//guardamos la posición por si atacas a un goblin moviendote sobre el que te eche para atras
	x_back=this->objs[0].x ;
	y_back=this->objs[0].y ;
	//Cargar mapa de fichero
	this->p.deFichero("pantallas/pantalla1.pan");
	//Segun tecla mover personaje principal (objs[0])
	this->mover(tecla);
	//poner los objetos sobre el mapa , el último el 0 que es el jugador
	for(int i=KNUMOBJETOS;i>=0;i--)
		this->p.coor[  this->objs[i].x ][ this->objs[i].y ]=this->objs[i].forma;

	//Por cada objeto
	for(int i=0;i<=KNUMOBJETOS;i++){
		//Si el jugador esta en las mismas coordenadas que el objeto ...
		if( this->objs[0].x ==this->objs[i].x && this->objs[0].y ==this->objs[i].y ){
			//si es la espada ...
			if(this->objs[i].forma=='!'){
				this->p.notifica("objetos/espada.pan");
				this->p.actualizar();
				sleep(1);
				this->objs[i].forma=' ';
			//Si es un cofre
			}else if(this->objs[i].forma=='$'){
				this->p.notifica("objetos/tesoro.pan");
				this->p.actualizar();
				sleep(1);
				this->objs[i].forma=' ';
			//Si es un goblin
			}else if(this->objs[i].forma=='g'){
				this->p.notifica("objetos/goblin.pan");
				this->p.actualizar();
				sleep(1);
				if(this->objs[i].energia==0){
					this->objs[i].forma=' ';
				}else{
					this->objs[i].energia--;
					this->objs[0].x=x_back;
					this->objs[0].y=y_back;
				}
			}
		}
	}

    this->p.actualizar();
}

// q 113 w 119 e 101 a 97 d 100 z 122 x 120
void Juego::mover(int tecla){
	int posx, posy;


	switch(tecla){
		case 97:
			if(this->p.coor[(this->objs[0].x-1)][this->objs[0].y]!='#'){
				this->objs[0].x--;
			}
		break;
		case 100:
			if(this->p.coor[(this->objs[0].x+1)][this->objs[0].y]!='#'){
				this->objs[0].x++;
			}
		break;
		case  119:
			if(this->p.coor[(this->objs[0].x)][this->objs[0].y-1]!='#'){
				this->objs[0].y--;
			}
		break;
		case 120:
			if(this->p.coor[(this->objs[0].x)][this->objs[0].y+1]!='#'){
							this->objs[0].y++;
			}
		break;

	}
}
