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
LDFLAGS = -L$(LIBDIR) -lCCollection -lm

#SOURCES & BINARIES
SRC  = $(wildcard $(UTILDIR)*.c)
OBJ  = $(SRC:$(UTILDIR)%.c=$(OBJDIR)%.o)

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(OBJ) $(LIBDIR)libCCollection.a

test: $(OBJ) $(LIBDIR)libCCollection.a

$(OBJDIR)%.o: $(UTILDIR)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIR)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(LIBDIR)libCCollection.a:
	ar rcs $@ $(OBJDIR)ArrayList.o $(OBJDIR)LinkedList.o $(OBJDIR)PriorityQueue.o $(OBJDIR)Stack.o $(OBJDIR)Queue.o $(OBJDIR)CompareTo.o

clean:
	rm -rf $(OBJDIR)/*.o *~
