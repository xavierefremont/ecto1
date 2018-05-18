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
EXEC = testCar

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(OBJ)

test: $(BINDIR)$(EXEC)

$(BINDIR)$(EXEC): $(OBJDIR)$(EXEC).o $(OBJDIR)car.o
	@$(CC) $^ -I $(ROOT)include/car -o $@ $(LDFLAGS)
	@echo  "\t$(CEXEC)$(EXEC)$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"


$(OBJDIR)$(EXEC).o: $(TESTSDIR)$(EXEC).c
	@$(CC) -o $@ -I $(ROOT)include/car -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"


$(OBJDIR)car.o: $(SRCDIR)car/car.c
	@$(CC) -o $@ -I $(ROOT)include/car -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

clean:
	@rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	@rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
