INCLUDE = -I ./include
LIB = ./lib
LIBS = $(LIB)/calcul_trajectoire.a $(LIB)/entrees.a $(LIB)/equations.a
LIBTOOLS = $(LIB)/lecture.a $(LIB)/liste.a $(LIB)/position.a
LDEPENDENCY = -lcalcultrajectoire -lentrees -lequations
LTOOLSDEPENDENCY = -llecture -lliste -lposition
WARNINGS = -Wall -Werror -Wextra -ggdb3
MODULE = ./module
SRC = ./sources
DEST = ./bin
TESTS = -DTESTS
DEBUG = -DDEBUG

# program compile

start: $(DEST)/main
	$<

$(DEST)/main: $(SRC)/main.c $(LIBS) $(LIBTOOLS) 
	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $< -o $@ $(LDEPENDENCY) $(LTOOLSDEPENDENCY)

# library compile

init: $(LIBS) $(LIBTOOLS)

# ? using pattern rules to automatically compile .o files from MODULES source list
# https://www.gnu.org/software/make/manual/html_node/Static-Usage.html#Static-Usage
$(LIBS): $(LIB)/%.a: $(SRC)/%
	cd $< && make init

$(LIBTOOLS): $(LIB)/%.a: $(SRC)/tools/%
	cd $< && make init

# dependencies unit tests

test/%: %.c $(TOOLS)
	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $(TESTS) $< -o $* $(LTOOLSDEPENDENCY) 
	./$* 
	rm $*

# project cleanup

prune:
	rm -f $(MODULE)/*
	rm -f $(LIB)/*
	rm -f $(DEST)/*