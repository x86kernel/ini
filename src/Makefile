TARGET=../build/ini
CC=clang
CFLAGS=-I../include
LDFLAGS=
SRCS=list.c ini.c misc.c main.c
OBJS=list.o ini.o misc.o main.o

${TARGET}: ${OBJS}
	mkdir ../build
	${CC} -o ${TARGET} ${CFLAGS} ${OBJS}

clean:
	rm -rf ../build
	rm -f ${TARGET} *.o
