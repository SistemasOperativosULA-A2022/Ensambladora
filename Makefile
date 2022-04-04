SRC_PATH=./src
HEADER_PATH=./headers
OUT_PATH=./bin
VPATH=${SRC_PATH}

FILES=carro cadena_traslado estacion1 estacion2 estacion3 estacion4 

SOURCES=$(FILES:%=$(SRC_PATH)/%.cpp)
HEADERS=$(FILES:%=$(HEADER_PATH)/%.hpp)
EXEC=main

CC=g++
CFLAGS=-Wall -std=c++14
LINKS=-lpthread

all:
	${CC} -o ${EXEC} ${CFLAGS} -I${HEADER_PATH} ${HEADERS} ${SOURCES} ${MAIN} ${EXEC}.cpp ${LINKS}
