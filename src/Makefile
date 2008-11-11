

# Makefile for example project bob4
# Calls two env vars 
# 1) LPC_PROJ - location of projects
# 2) LPC_DEV - location of PSAS Dev tree

LPC_PROJ        = ${HOME}/PSASGIT

PROJECT		= bob4
TYPE		= 2148

CC		= arm-elf-gcc
LD		= arm-elf-ld -v
AR		= arm-elf-ar rvs
AS		= arm-elf-as
CP		= arm-elf-objcopy
OD		= arm-elf-objdump

LD_LIB1         = ${LPC_DEV}/LPC/2148/arm-elf/lib
LD_LIB2         = ${LPC_DEV}/LPC/2148/lib/gcc/arm-elf/4.2.3
INCLUDE-SYS     = ${LPC_DEV}/LPC/2148/arm-elf/include

INCLUDE-LPC	= ${LPC_PROJ}/bob4/psas-lpc/src/include
CFLAGS		= -I./include -I${INCLUDE-LPC} -I{INCLUDE-SYS} -c -O0 -Wall -fno-common -g
AFLAGS		= -g  -ahls
ASFLAGS		= -S -c -g -I./ -I${INCLUDE-LPC}
LSTFLAGS	= -c -g -I./ -I${INCLUDE-LPC} -Wa,-a,-ad
#LFLAGS		= -L${LD_LIB1} -lc -L${LD_LIB2} -lgcc -Map ${PROJECT}.map -T${TYPE}_demo.cmd
#LFLAGS		=  -Map ${PROJECT}.map -T${TYPE}_demo.cmd
LFLAGS		=  -Map ${PROJECT}.map -Tlpc${TYPE}-rom.ld

CPFLAGS		= -O binary
HEXFLAGS	= -O ihex
ODFLAGS		= -x --syms



PREFIX		= .

ASRCS		= ${PREFIX}/crt.s
SRCS		= ${PREFIX}/${PROJECT}.c
OBJS		=  ${ASRCS:.s=.o} ${SRCS:.c=.o}
# Why doesn't -L flag work (-L${LD_LIB1} -lc}? 
LIBS            = ${LPC_PROJ}/bob4/psas-lpc/lib/libpsaslpc.a ${LD_LIB1}/libc.a ${LD_LIB2}/libgcc.a

MAKE		= /usr/bin/gmake

.PHONY: clean

.SUFFIXES : .c .o .s .a

.c.o :
	${CC} ${CFLAGS} -c $<

.s.o :
	${AS} ${AFLAGS} -o $@ $< > $*.lst

all: lpc${TYPE}-rom.ld ${PROJECT}.out ${PROJECT}.bin ${PROJECT}.hex

debug: lpc${TYPE}-rom.ld ${PROJECT}.out ${PROJECT}.lst ${PROJECT}.s


${LPC_PROJ}/bob4/psas-lpc/lib/libpsaslpc.a:
	pushd ${LPC_PROJ}/bob4/psas-lpc; make ; popd

${PROJECT}.out: ${LIBS} ${OBJS} lpc${TYPE}-rom.ld 
	@echo "...making lib"
	pushd ${LPC_PROJ}/bob4/psas-lpc; make ; popd
	@echo "...linking"
	${LD}   -o $@ ${OBJS} ${LIBS} ${LFLAGS}


${PROJECT}.bin: ${PROJECT}.out
	@echo "...binary file"
	$(CP) $(CPFLAGS) ${PROJECT}.out ${PROJECT}.bin
	$(OD) $(ODFLAGS) ${PROJECT}.out > ${PROJECT}.dmp


${PROJECT}.hex: ${PROJECT}.out
	@echo "...hex file"
	$(CP) $(HEXFLAGS) ${PROJECT}.out ${PROJECT}.hex


# This will create combined C and Assy listing....
${PROJECT}.lst: ${PROJECT}.c
	@echo "...${PROJECT}.s"
	${CC} ${LSTFLAGS} ${PROJECT}.c > $@

${PROJECT}.s: ${PROJECT}.c
	@echo "...${PROJECT}.s"
	${CC} ${ASFLAGS} -o $@ ${PROJECT}.c 

lpc${TYPE}-rom.ld:
	@echo "...lpc${TYPE}-rom.ld"
	ln -s ${LPC_DEV}/Config/${TYPE}/lpc${TYPE}-rom.ld .

${OBJS}: ${SRCS}


clean:
	-rm -f *.o *.out *.hex *.bin *.dmp *.map ${PROJECT}.s ${PROJECT}.lst crt.lst *~



