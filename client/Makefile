CFLAGS  += -g3 -Wall -I./include
LDFLAGS += -L./lib -lqli

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
	(cd lib && make)

${BIN_DIR}/%: %.c
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}
