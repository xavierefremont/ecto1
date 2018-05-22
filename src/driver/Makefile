.PHONY: clean

#DIRECTORIES
ROOT = ../../
BINDIR = $(ROOT)bin/
SRCDIR = $(ROOT)src/
OBJDIR = $(ROOT)obj/
LIBDIR = $(ROOT)lib/
TESTSDIR = $(ROOT)src/tests/

#COMPILERS MACRO
CC = gcc
CFLAGS = -W -Wall -pedantic
LDFLAGS = -L$(LIBDIR) -lCCollection -lm

#SOURCES & BINARIES
SRC  = $(wildcard *.c)
OBJ  = $(SRC:%.c=$(OBJDIR)%.o)
OTHOBJ = $(wildcard $(OBJDIR)*.o)

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(OBJ)


$(OBJDIR)driver.o: $(SRCDIR)driver/driver.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
	echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(OBJDIR)car.o:
	(cd ../car/; make ../../obj/car.o;)

$(OBJDIR)map.o:
	(cd ../gps/; make ../../obj/map.o;)

$(OBJDIR)gps.o:
	(cd ../gps/; make ../../obj/gps.o;)

clean:
	rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
