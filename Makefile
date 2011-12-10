# Nick del usuario
NICK=phantomas
# Nombre del programa
NOMBRE_PROGRAMA=rogelio
# Listado de fuentes del programa
FUENTES=main.cpp Pantalla.h Pantalla.cc StdPijo.h StdPijo.cpp Juego.cc Juego.h Objeto.cc Objeto.h 
# -lrt      
# Otros archivos a incluir en el paquete, si quieres
# ¡Ojo!, el README, Makefile y COPYING son obligatorios
# Aquí se pueden poner los .h que utilices
OTROS=README Makefile COPYING definitions.h
# Comentar para depurar
CXXFLAGS=-g
# Librerias a usar
LIBS= -lncurses

# Reglas del Makefile
.PHONY=all, clean, dist

all: ${NOMBRE_PROGRAMA}

clean:
	rm -f ${NOMBRE_PROGRAMA}

dist:
	@tar cvzf ${NICK}-${NOMBRE_PROGRAMA}.tar.gz ${FUENTES} ${OTROS}

${NOMBRE_PROGRAMA}: ${FUENTES}
	${CXX} ${CXXFLAGS} $^ -o $@ ${LIBS}
