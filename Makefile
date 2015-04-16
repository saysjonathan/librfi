KERNEL := $(shell uname -s | tr 'A-Z' 'a-z')
include mk/${KERNEL}.mk

PREFIX  = /usr/local
INCS    = -I. -I./src -I/usr/include -I./include
CFLAGS  = -std=c99 -pedantic -Wall -O0 ${DYNFLAG} -DSHARED -D_DEFAULT_SOURCE -D_BSD_SOURCE
ENABLED = load mem swap
BSRCS   = $(wildcard src/*.c) $(wildcard src/**/*.c)
ESRCS   = $(addprefix %/,${ENABLED:=.c})
SRCS    = $(filter %/rfi.c %/${KERNEL:=.c} ${ESRCS},$(BSRCS))
LOBJS   = ${SRCS:.c=.lo}
HDRS    = $(wildcard include/*.h)

all: options pre ${SHLIB}

options:
	@echo librfi build options:
	@echo "Enabled modules: ${ENABLED}"

pre:
	@mkdir -p lib

clean:
	@echo cleaning
	@rm -f $(wildcard src/*.lo) $(wildcard src/**/*.lo)
	@rm -rf lib

%.lo: %.c
	cc ${CFLAGS} ${INCS} -c -o $@ $<

${SHLIB}: ${LOBJS}
	cc ${CFLAGS} ${INCS} -shared -o lib/$@ ${LOBJS}

install: all
	@echo installing
	@install -d ${PREFIX}/include
	@install -m 644 ${HDRS} ${PREFIX}/include
	@install -d ${PREFIX}/lib
	@install -m 755 lib/${SHLIB} ${PREFIX}/lib

uninstall:
	@echo uninstalling
	@rm -f ${PREFIX}/lib/${SHLIB}
	@rm -rf ${PREFIX}/include/${HDRS}

.PHONY: all pre clean install uninstall
