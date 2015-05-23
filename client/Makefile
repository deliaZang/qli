CFLAGS  += -g3 -Wall -I./include
LDFLAGS += -L./lib -lqli -lncursesw

ifeq ($(debug), true)
DEBUG = debug=true
CFLAGS += -D_MY_DEBUG
endif

SRC_DIR=.
BIN_DIR=./bin

BINS = \
    ${BIN_DIR}/web_browser

all: begin ${BINS}
clean:
	(cd lib && make clean)
	@rm -rf ${BINS}

begin:
	@mkdir -p ${BIN_DIR}
	(cd lib && make ${DEBUG})

${BIN_DIR}/%: %.c
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}
