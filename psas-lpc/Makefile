
NAME		= lpc2148
TYPE		= 2148

CC		= arm-elf-gcc
LD		= arm-elf-ld -v
AR		= arm-elf-ar rvs
AS		= arm-elf-as
CP		= arm-elf-objcopy
OD		= arm-elf-objdump

CFLAGS		= -I./ -c -Wall -fno-common -O0 -g
ASFLAGS		= -g -ahls -mapcs-32
LFLAGS		=  -Map poke.map -T${TYPE}_demo.cmd
CPFLAGS		= -O binary
HEXFLAGS	= -O ihex
ODFLAGS		= -x --syms

PREFIX		= ./src

#ASRCS		= ${PREFIX}/crt.s
SRCS		= ${PREFIX}/pll.c            \
                  ${PREFIX}/helpers.c        \
                  ${PREFIX}/mam.c            \
                  ${PREFIX}/lpc-serial.c     \
                  ${PREFIX}/lpc-rtc.c        \
                  ${PREFIX}/lpc-timer.c      \
                  ${PREFIX}/lpc-watchdog.c   \
                  ${PREFIX}/interrupts.c     \
                  ${PREFIX}/olimex.c

OBJS		= ${ASRCS:.s=.o} ${SRCS:.c=.o}
LIBS            = ./lib/libpsaslpc.a


.PHONY: clean


.SUFFIXES : .c .o .s .a

.c.o :
	${CC} ${CFLAGS} -c $<

.s.o :
	${AS} ${ASFLAGS} -o $@ $< > ./lib/$*.lst

all: libdir ${LIBS}

${LIBS}: ${OBJS}
	${AR} $@ ${OBJS}

${OBJS}: ${SRCS} ${ASRCS}
	cd src; ${MAKE} all
libdir:
	if test -d lib; then echo lib exists; else mkdir lib; fi

clean:
	-rm -f *~ ${LIBS}; cd ${PREFIX} ; ${MAKE} clean
