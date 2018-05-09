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
TESTGPS = testGPS
TESTMAP = testMap

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(OBJ)

test: $(BINDIR)$(TESTMAP) $(BINDIR)$(TESTGPS)

$(BINDIR)$(TESTMAP): $(OBJDIR)$(TESTMAP).o
	@$(CC) $^ -I $(ROOT)include/gps -o $@ $(LIBS) $(LDFLAGS)
	@echo  "\t$(CEXEC)$(EXEC)$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"

$(BINDIR)$(TESTGPS): $(OBJDIR)$(TESTGPS).o
	@$(CC) $^ -I $(ROOT)include/gps -o $@ $(LIBS) $(LDFLAGS)
	@echo  "\t$(CEXEC)$(EXEC)$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"

$(OBJDIR)$(TESTMAP).o: $(TESTSDIR)$(TESTMAP).c
	@$(CC) -o $@ -I $(ROOT)include/gps -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(OBJDIR)$(TESTGPS).o: $(TESTSDIR)$(TESTGPS).c
	@$(CC) -o $@ -I $(ROOT)include/gps -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(OBJDIR)gps.o: $(SRCDIR)gps/gps.c
	@$(CC) -o $@ -I $(ROOT)include/ -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"


$(OBJDIR)map.o: $(SRCDIR)gps/map.c
	@$(CC) -o $@ -I $(ROOT)include/ -c $< $(CFLAGS) $(LDFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

clean:
	@rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	@rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
