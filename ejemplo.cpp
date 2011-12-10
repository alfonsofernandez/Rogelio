/**
 *   Copyright 2011 (c) Francisco José Gallego Durán <fgallego@byterealms.com>
 *   Copyright 2011 (c) ByteRealms <info@byterealms.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; version 3 of the License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 */

//////////////////////////////////////////////////
// Ejemplo de uso de la versión básica de StdPijo
//////////////////////////////////////////////////

// Incluimos la cabecera principal de StdPijo
#include "StdPijo.h"

// Incluimos cabeceras para números aleatorios y retardos
#include <ctime>
#include <cstdlib>
#include <unistd.h>

// Usamos globalmente el espacio de nombres de stdpijo (STDP)
using namespace STDP;

int
main (void)
{
    // Obtenemos referencia de acceso a StdPijo
    StdPijo& stdp = StdPijo::p();

    // Inicializamos la pantalla
    stdp.init();

    // Borramos la pantalla
    stdp.clearScreen();
	
    // 0 Segundos de retardo de espera desde que se recibe un
    // caracter de escape por la entrada estándar. Esto sirve para
    // que no tengamos que esperar cuando pulsamos la tecla escape
    // a que verifique que no es un código de escape.
    stdp.setGlobalEscapeDelay(0);

    // Cambiamos a color azul negrita, sobre fondo amarillo cantoso :)
    stdp.setColor(ABOLD, CBLUE, CYELLOW);

    // Posicionamos el cursor en fila 16, columna 10
    stdp.setCursor(10, 16);

    // Escribimos una frase cantosa
    stdp.writeStr("Esto es un mensaje cantoso. Pulsa ESCAPE.");

    // Ahora ponemos color rojo parpadeante
    stdp.setColor(ABLINK, CRED, CBLACK);

    // Establecemos semilla para números aleatorios
    srand(time(NULL));

    // Esperamos hasta que el usuario pulse Escape, escribiendo
    // caracteres en pantalla mientras.
    while (stdp.getKey() != KESCAPE) {
        // Ponemos el cursor en posición aleatoria encima del mensaje
        unsigned int x = rand() % 60 + 1;
        unsigned int y = rand() % 15 + 1;
        stdp.setCursor(x, y);

        // Y escribimos un asterisco
        stdp.writeChar('*');

        // Pequeño retardo
        usleep(1000);

        // Borramos el asterisco el 90% de las veces
        if (rand() % 100 < 90) {
            stdp.setCursor(x, y);
            stdp.writeChar(' ');
        }

        // Refrescamos la pantalla para asegurarnos de que
        // se ven los últimos cambios
        stdp.refreshScr();
    }

    // Restauramos el estado original del terminal
    stdp.end();

    // Salimos sin errores
    return 0;
}

