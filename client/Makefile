CFLAGS  += -g -Wall -I./include
LDFLAGS += -L./lib -lqli

SRC_DIR=.
BIN_DIR=./bin

BINS = \
    ${BIN_DIR}/web_browser

all: ${BINS}
clean:
	(cd lib && make clean)
	@rm -rf ${BINS} ${BIN_DIR}

${BIN_DIR}/%: %.c
	@mkdir -p ${BIN_DIR}
	(cd lib && make)
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}
