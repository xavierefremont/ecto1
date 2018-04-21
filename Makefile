.PHONY: clean mrpoper doc

#DIRECTORIES
SRCDIR = src/
SUBDIR = $(addprefix $(SRCDIR), car gps driver)

#COLORS
CDIR = \033[0;36m
CNONE = \033[0m

all:
	@for dir in $(SUBDIR) ; do make -s -C $$dir ; done
	@mv bin/driver.out ../drivers/
	@echo "$(CDIR)driver.out$(CNONE) moved in $(CDIR)doc$(CNONE)"

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
