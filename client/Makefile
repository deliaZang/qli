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
${BIN_DIR}/%: %.c
	${CC} ${CFLAGS} -o $@ $< ${LIBS}
