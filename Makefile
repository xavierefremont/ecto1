.PHONY: clean mrpoper doc

#DIRECTORIES
SRCDIR = src/
SUBDIR = $(addprefix $(SRCDIR), util car gps driver)

#COLORS
CDIR = \033[0;36m
CNONE = \033[0m

all:
	@for dir in $(SUBDIR) ; do make -s -C $$dir ; done
	@make -s -C $(SRCDIR);
	@mv bin/ecto1 ../drivers/
	@echo "$(CDIR)ecto1$(CNONE) moved in $(CDIR)drivers$(CNONE)"

tests:
	@for dir in $(SUBDIR) ; do make test -s -C $$dir ; done

doc:
	@doxygen Doxyfile
	@echo "Documentation generated in $(CDIR)doc$(CNONE)"

clean:
	@for dir in $(SUBDIR) ; do make -s -C $$dir clean ; done
	@(cd $(SRCDIR)$(MAINDIR) && make -s clean)
	@rm -rf $(OBJDIR)*.o
	@echo "project cleaned"

mrproper: clean
	@(cd $(SRCDIR)$(MAINDIR) && make -s mrproper)
