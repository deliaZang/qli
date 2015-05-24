CFLAGS  += -g3 -Wall -I../include/

ifeq ($(debug), true)
CFLAGS += -D_MY_DEBUG
endif

LIBQLI=libqli.a
SRC=${wildcard *.c}
OBJ=${SRC:.c=.o}


all: ${LIBQLI} ${OBJ}
clean:
	@rm -f ${OBJ} ${LIBQLI}

${LIBQLI}: ${OBJ}
	${AR} rv $@ $^
%.o: %c
	${CC} ${CFLAGS} -o $@ -c $<
