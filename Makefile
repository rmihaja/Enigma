INCLUDE = -I ./include
LIB = ./lib
WARNINGS = -Wall -Werror -Wextra -ggdb3
MODULE = ./module
MODULES = $(MODULE)/calcul_trajectoire.o $(MODULE)/demande_lorenz.o $(MODULE)/demande_hugo.o $(MODULE)/demande_mihaja.o $(MODULE)/demande_parametres.o $(MODULE)/lorenz_transform.o $(MODULE)/hugo_transform.o $(MODULE)/mihaja_transform.o $(MODULE)/nouvelle_trajectoire.o $(MODULE)/demande_vitesse.o $(MODULE)/custom_transform.o
TOOLS = $(MODULE)/nouvelle_position.o $(MODULE)/fprintf_position.o $(MODULE)/get_position.o $(MODULE)/nouvelle_liste.o $(MODULE)/ajouter_liste.o  $(MODULE)/supprimer_liste.o $(MODULE)/evaluer_operation.o $(MODULE)/is_entree_valide.o  
SRC = ./sources
DEST = ./bin
TESTS = -DTESTS
DEBUG = -DDEBUG

# program compile

start: $(DEST)/main
	$<

# TODO: faire marcher -L $(LIB)
# $(DEST)/main: $(SRC)/main.c $(LIB)/libenigma.a
# 	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $< -o $@

$(DEST)/main: $(SRC)/main.c $(LIB)/libenigma.a
	gcc $(INCLUDE) $(MODULES) $(TOOLS) $(WARNINGS) $< -o $@

plot: ./lorenz.dat
	$^ > echo | gnuplot

# library compile

init: $(LIB)/libenigma.a

$(LIB)/libenigma.a: $(MODULES) $(TOOLS)
	ar rcs $@ $^

$(MODULES): 
	cd $(SRC) && make init

$(TOOLS):
	cd $(SRC)/tools/liste && make init
	cd $(SRC)/tools/position && make init
	cd $(SRC)/tools/entree && make init

# dependencies unit tests

test/%: %.c $(TOOLS)
	gcc $(INCLUDE) $(TOOLS) $(WARNINGS) $(TESTS) $< -o $* 
	./$* 
	rm $*

# project cleanup

prune:
	rm -f $(MODULE)/*
	rm -f $(LIB)/*
	rm -f $(DEST)/*