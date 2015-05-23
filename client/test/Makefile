CFLAGS  += -g3 -Wall -I../include
LDFLAGS += -L../lib -lqli -lncursesw

ifeq ($(debug), true)
DEBUG = debug=true
endif

SRC_DIR=.
BIN_DIR=./bin

BINS = \
    ${BIN_DIR}/config_tools_test	\
    ${BIN_DIR}/sscanf_test			\
	${BIN_DIR}/list_test			\
	${BIN_DIR}/html_test			\
	${BIN_DIR}/sunday_test			\
	${BIN_DIR}/pad_test				\
	${BIN_DIR}/map_test


all: begin ${BINS}
clean:
	(cd ../lib && make clean)
	@rm -rf ${BINS} ${BIN_DIR}

begin:
	@mkdir -p ${BIN_DIR}
	(cd ../lib && make ${DEBUG})

${BIN_DIR}/%: %.c
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}