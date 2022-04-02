SRC_PATH=./src
HEADER_PATH=./headers
OUT_PATH=./bin
VPATH=${SRC_PATH}
FILES=cadena_traslado estacion1 carro
SOURCES=$(FILES:%=$(SRC_PATH)/%.cpp)
HEADERS=$(FILES:%=$(HEADER_PATH)/%.hpp)
EXEC=main

CC=g++
CFLAGS=-Wall
LINKS=-lpthread

all:
	${CC} -o ${EXEC} ${CFLAGS} -I${HEADER_PATH} ${HEADERS} ${SOURCES} ${MAIN} ${EXEC}.cpp ${LINKS}