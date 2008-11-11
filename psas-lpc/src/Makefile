

# Makefile for psas lpc library

NAME		= lpc2148
TYPE		= 2148

CC		= arm-elf-gcc
LD		= arm-elf-ld -v
AR		= arm-elf-ar rvs
AS		= arm-elf-as
CP		= arm-elf-objcopy
OD		= arm-elf-objdump


CFLAGS		= -I./include -c -Wall -fno-common -finline-functions -O0 -g
ASFLAGS		= -g -ahls -mapcs-32

#ASRCS		= crt.s
SRCS		= pll.c                 \
                  helpers.c             \
                  mam.c                 \
                  interrupts.c          \
                  olimex.c              \
                  lpc-serial.c          \
                  lpc-timer.c           \
                  lpc-watchdog.c        \
                  lpc-rtc.c

OBJS		= ${ASRCS:.s=.o} ${SRCS:.c=.o} 


.SUFFIXES : .c .o .s 

.c.o :
	$(CC) $(CFLAGS) -c $<

.s.o :
	$(AS) $(ASFLAGS) -o $@ $< > $*.lst


all:  ${OBJS}

${OBJS}: ${SRCS} ${ASRCS}


clean:
	rm -f ${OBJS} *.lst *~ ./include/*~



