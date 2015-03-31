PREFIX = /usr/local
INCS   = -I. -I/usr/include -I./include
CFLAGS = -std=c99 -pedantic -Wall -O0 -fPIC -DSHARED -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_SOURCE
SRCS   = $(wildcard src/*.c) $(wildcard src/**/*.c)
LOBJS  = ${SRCS:.c=.lo}
SHLIB  = lib/librfi.so
HDRS   = $(wildcard include/*.h)

all: options pre ${SHLIB}

options:
	@echo librfi build options:
	@echo "SRCS  = ${SRCS}"
	@echo "LOBJS = ${LOBJS}"
	@echo "HDRS  = ${HDRS}"

pre:
	@mkdir -p lib

clean:
	@echo cleaning
	@rm -f ${LOBJS}
	@rm -rf lib

%.lo: %.c
	cc ${CFLAGS} ${INCS} -c -o $@ $<

${SHLIB}: ${LOBJS}
	cc ${CFLAGS} ${INCS} -shared -o $@ ${LOBJS}

install: all
	@echo installing
	@install -D -m 644 ${HDRS} ${PREFIX}/include
	@install -d ${PREFIX}/lib
	@install -D -m 755 ${SHLIB} ${PREFIX}/lib

uninstall:
	@echo uninstalling
	@rm -f ${PREFIX}/${SHLIB}
	@rm -rf ${PREFIX}/${HDRS}

.PHONY: all pre clean install uninstall
