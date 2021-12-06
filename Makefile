INCLUDE = -I ./include
LIB = ./lib
WARNINGS = -Wall -Werror -Wextra -ggdb3
MODULE = ./module
MODULES = $(MODULE)/calcul_trajectoire.o $(MODULE)/demande_lorenz.o $(MODULE)/demande_parametres.o $(MODULE)/fprintf_position.o $(MODULE)/lorenz_transform.o $(MODULE)/nouvelle_position.o $(MODULE)/nouvelle_trajectoire.o
SRC = ./sources
DEST = ./bin
TESTS = -DTESTS
DEBUG = -DDEBUG

# library compile

init: $(LIB)/libenigma.a

$(LIB)/libenigma.a: $(MODULES)
	ar rcs $@ $^

$(MODULES): 
	cd $(SRC)/tools && make init
	cd $(SRC) && make init
	
# program compile

start: $(DEST)/main
	$<

# TODO: faire marcher -L $(LIB)
# $(DEST)/main: $(SRC)/main.c $(LIB)/libenigma.a
# 	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $< -o $@

$(DEST)/main: $(SRC)/main.c $(LIB)/libenigma.a
	gcc $(INCLUDE) $(MODULES) $(WARNINGS) $< -o $@

# project cleanup

prune:
	rm -f $(MODULE)/*
	rm -f $(LIB)/*
	rm -f $(DEST)/*