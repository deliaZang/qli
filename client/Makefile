CC=gcc
CFLAGS=-g -Wall
LIBS=

SRC_DIR=.
BIN_DIR=./bin

BINS = \
    ${BIN_DIR}/web_browser


all: ${BIN_DIR} ${BINS}
clean:
	@rm -f ${BINS}

${BIN_DIR}:
	@mkdir -p ${BIN_DIR}
${BIN_DIR}/%: %.c socket_tools.o file_tools.o error.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}
%.o: %c
	${CC} ${CFLAGS} -o $@ -c $< ${LIBS}
