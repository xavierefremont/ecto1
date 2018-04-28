.PHONY: clean

CC = gcc
CFLAGS = -W -Wall -pedantic
LDFLAGS = -lm

#DIRECTORIES
ROOT = ../
BINDIR = $(ROOT)bin/
SRCDIR = $(ROOT)src/
OBJDIR = $(ROOT)obj/

#SOURCES & BINARIES
SRC  = $(wildcard *.c)
OBJ  = $(SRC:%.c=$(OBJDIR)%.o)
OTHOBJ = $(wildcard $(OBJDIR)*.o)

#MAIN'S SOURCES
EXEC = ecto1

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(BINDIR)$(EXEC)

$(BINDIR)$(EXEC): $(OBJDIR)$(EXEC).o $(OBJDIR)driver.o $(OBJDIR)car.o $(OBJDIR)map.o $(OBJDIR)gps.o
	@$(CC) $^ -o $@ $(LDFLAGS)
	@echo  "\t$(CEXEC)$(EXEC)$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"


$(OBJDIR)$(EXEC).o: $(SRCDIR)$(EXEC).c
	@$(CC) -o $@ -I $(ROOT)include/driver -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"


$(OBJDIR)driver.o:
	@make -s -C $(SRCDIR)/driver;

$(OBJDIR)car.o:
	@make -s -C $(SRCDIR)/car;

$(OBJDIR)map.o:
	@make -s -C $(SRCDIR)/gps;

$(OBJDIR)gps.o:
	@make -s -C $(SRCDIR)/gps;

clean:
	@rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	@rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
