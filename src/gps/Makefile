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

#MAIN'S SOURCES

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(OBJ)

$(OBJDIR)gps.o: $(SRCDIR)gps/gps.c
	$(CC) -o $@ -I $(ROOT)include/gps -c $< $(CFLAGS) $(LDFLAGS)
	echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"


$(OBJDIR)map.o: $(SRCDIR)gps/map.c
	$(CC) -o $@ -I $(ROOT)include/gps -c $< $(CFLAGS) $(LDFLAGS)
	echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"


$(OBJDIR)driver.o:
	(cd ../driver/; make ../../obj/driver.o;)


$(OBJDIR)car.o:
	(cd ../car/; make ../../obj/car.o;)

clean:
	rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
