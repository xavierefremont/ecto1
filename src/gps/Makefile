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
LDFLAGS = -L$(LIBDIR) -lEcto1 -lm

#SOURCES & BINARIES
SRC  = $(wildcard *.c)
OBJ  = $(SRC:%.c=$(OBJDIR)%.o)
OTHOBJ = $(wildcard $(OBJDIR)*.o)

#MAIN'S SOURCES
TESTGPS = testGPS
TESTMAP = testMap

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(OBJ)

test: $(BINDIR)$(TESTMAP) $(BINDIR)$(TESTGPS)

$(BINDIR)$(TESTMAP): $(OBJDIR)$(TESTMAP).o $(OBJDIR)driver.o $(OBJDIR)car.o $(OBJDIR)map.o $(OBJDIR)gps.o
	@$(CC) $^ -I $(ROOT)include/gps -o $@ $(LDFLAGS)
	@echo  "\t$(CEXEC)$(TESTMAP)$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"

$(BINDIR)$(TESTGPS): $(OBJDIR)$(TESTGPS).o $(OBJDIR)driver.o $(OBJDIR)car.o $(OBJDIR)map.o $(OBJDIR)gps.o
	@$(CC) $^ -I $(ROOT)include/gps -o $@ $(LDFLAGS)
	@echo  "\t$(CEXEC)$(TESTGPS)$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"
	@mv $(BINDIR)$(TESTGPS) $(ROOT)/../drivers;

$(OBJDIR)$(TESTMAP).o: $(TESTSDIR)$(TESTMAP).c
	@$(CC) -o $@ -I $(ROOT)include/gps -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(OBJDIR)$(TESTGPS).o: $(TESTSDIR)$(TESTGPS).c
	@$(CC) -o $@ -I $(ROOT)include/gps -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(OBJDIR)gps.o: $(SRCDIR)gps/gps.c
	@$(CC) -o $@ -I $(ROOT)include/gps -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"


$(OBJDIR)map.o: $(SRCDIR)gps/map.c
	@$(CC) -o $@ -I $(ROOT)include/gps -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(OBJDIR)driver.o:
	@(cd ../driver/; make ../../obj/driver.o;)

$(OBJDIR)car.o:
	@(cd ../car/; make ../../obj/car.o;)

clean:
	@rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	@rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
