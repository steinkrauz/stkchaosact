CFLAGS+=-c -Wall
#LDADD+= 
LDFLAGS=
EXEC=stkChaosAct

PREFIX?= /usr/local
BINDIR?= $(PREFIX)/bin

CC=gcc

#all: $(EXEC)

stkChaosAct: stkChaosAct.o stkLibChaos.o
	$(CC) $(LDFLAGS) -Os -o $@ $+ 

stkChaosAct.o : stkChaosAct.c
	$(CC) $(CFLAGS) stkChaosAct.c

stkLibChaos.o : stkLibChaos.c
	$(CC) $(CFLAGS) stkLibChaos.c

install: all
	install -Dm 755 stkChaosAct $(DESTDIR)$(BINDIR)/stkChaosAct

clean: 
	rm -f strChaosAct *.o
