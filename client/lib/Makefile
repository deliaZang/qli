CFLAGS  += -g3 -Wall -I../include/
LDFLAGS += -lcurses

LIBQLI=libqli.a
SRC=${wildcard *.c}
OBJ=${SRC:.c=.o}


all: ${LIBQLI} ${OBJ}
clean:
	@rm -f ${OBJ} ${LIBQLI}

${LIBQLI}: ${OBJ}
	${AR} rv $@ $^
%.o: %c
	${CC} ${CFLAGS} -o $@ -c $< $(LDFLAGS)
