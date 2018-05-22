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
EXEC = testDriver

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(BINDIR)$(EXEC)

$(BINDIR)$(EXEC): $(OBJDIR)$(EXEC).o $(OBJDIR)gps.o $(OBJDIR)map.o $(OBJDIR)car.o $(OBJDIR)driver.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)
	echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(OBJDIR)$(EXEC).o: $(SRCDIR)tests/testDriver.c
	$(CC) -o $@ -I $(ROOT)include/gps -c $< $(CFLAGS) $(LDFLAGS)
	echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(OBJDIR)gps.o:
	(cd ../gps/; make ../../obj/gps.o;)

$(OBJDIR)map.o:
	(cd ../gps/; make ../../obj/map.o;)

$(OBJDIR)driver.o:
	(cd ../driver/; make ../../obj/driver.o;)

$(OBJDIR)car.o:
	(cd ../car/; make ../../obj/car.o;)

clean:
	rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
