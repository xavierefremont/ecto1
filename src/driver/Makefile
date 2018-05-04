.PHONY: clean

CC = gcc
CFLAGS = -W -Wall -pedantic
LDFLAGS = -lm

#DIRECTORIES
ROOT = ../../
BINDIR = $(ROOT)bin/
SRCDIR = $(ROOT)src/
OBJDIR = $(ROOT)obj/
TESTSDIR = $(ROOT)src/tests/

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

all: $(OBJ)

test: $(BINDIR)$(EXEC)

$(BINDIR)$(EXEC): $(OBJDIR)$(EXEC).o $(OBJDIR)driver.o $(OBJDIR)car.o $(OBJDIR)map.o $(OBJDIR)gps.o
	@$(CC) $^ -I $(ROOT)include/driver -o $@ $(LDFLAGS)
	@echo  "\t$(CEXEC)$(EXEC)$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"
	@mv $(BINDIR)$(EXEC) $(ROOT)/../drivers;


$(OBJDIR)$(EXEC).o: $(TESTSDIR)$(EXEC).c
	@$(CC) -o $@ -I $(ROOT)include/driver -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"


$(OBJDIR)driver.o: $(SRCDIR)driver/driver.c
	@$(CC) -o $@ -I $(ROOT)include/driver -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(OBJDIR)car.o:
	@(cd ../car/; make ../../obj/car.o;)

$(OBJDIR)map.o:
	@(cd ../gps/; make ../../obj/map.o;)

$(OBJDIR)gps.o:
	@(cd ../gps/; make ../../obj/gps.o;)

clean:
	@rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	@rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
