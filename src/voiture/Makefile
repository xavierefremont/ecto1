.PHONY: clean

CC = gcc
CFLAGS = -W -Wall -pedantic
LDFLAGS = -lm

#DIRECTORIES
ROOT = ../../
BINDIR = $(ROOT)bin/
SRCDIR = $(ROOT)src/
OBJDIR = $(ROOT)obj/

#SOURCES & BINARIES
SRC  = $(wildcard *.c)
OBJ  = $(SRC:%.c=$(OBJDIR)%.o)
OTHOBJ = $(wildcard $(OBJDIR)*.o)

#MAIN'S SOURCES
EXEC =

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all:

$(EXEC): $(OBJDIR)$(EXEC).o $(OTHOBJ)
	@if [ ! -d $(ROOT)bin ]; then mkdir $(ROOT)bin;fi
	@$(CC) $^ -I $(ROOT)include/image -o $(BINDIR)$@.out $(LIBS) $(LDFLAGS)
	@echo  "\t$(CEXEC)$(EXEC).out$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"


$(OBJDIR)%.o: %.c
	@$(CC) -o $@ -I $(ROOT)include/ -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

clean:
	@rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	@rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
