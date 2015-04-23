CC=gcc
CFLAGS=-g -Wall
LIBS=

SRC_DIR=.
BIN_DIR=./bin

BINS = \
    ${BIN_DIR}/config_tools_test	\
    ${BIN_DIR}/sscanf_test


all: ${BIN_DIR} ${BINS}
clean:
	@rm -rf ${BINS} ${BIN_DIR}

${BIN_DIR}:
	@mkdir -p ${BIN_DIR}
${BIN_DIR}/%: %.c
	${CC} ${CFLAGS} -o $@ $< ${LIBS}
