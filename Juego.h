#include "Pantalla.h"
#include "Objeto.h"
class Juego
{

  public:
    Juego();
    Pantalla p;
    Objeto objs [10];
    char tablero[40][40];
    bool ha_terminado();
    int  leer_entrada();
    void actualizar(int tecla);

    Pos pos_j1;
    Pos pos_es;

  private:
    bool terminado;
    void mover(int tecla);
    
};
