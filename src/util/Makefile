.PHONY: clean

#DIRECTORIES
ROOT = ../../
BINDIR = $(ROOT)bin/
SRCDIR = $(ROOT)src/
OBJDIR = $(ROOT)obj/
LIBDIR = $(ROOT)lib/
UTILDIR = $(SRCDIR)util/

#COMPILERS MACRO
CC = gcc
CFLAGS = -W -Wall -pedantic
LDFLAGS = -L$(LIBDIR) -lEcto1 -lm

#SOURCES & BINARIES
SRC  = $(wildcard $(UTILDIR)*.c)
OBJ  = $(SRC:$(UTILDIR)%.c=$(OBJDIR)%.o)

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(OBJ) $(LIBDIR)libEcto1.a

test: $(OBJ) $(LIBDIR)libEcto1.a

$(OBJDIR)%.o: $(UTILDIR)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIR)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(LIBDIR)libEcto1.a:
	ar rcs $@  $(OBJDIR)structs.o $(OBJDIR)ArrayList.o $(OBJDIR)LinkedList.o $(OBJDIR)PriorityQueue.o $(OBJDIR)Stack.o $(OBJDIR)Queue.o $(OBJDIR)CompareTo.o

clean:
	rm -rf $(OBJDIR)/*.o *~
