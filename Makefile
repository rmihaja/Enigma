INCLUDE = -I ./include
LIB = ./lib
LIBS = $(LIB)/calcul_trajectoire.a $(LIB)/entrees.a $(LIB)/equations.a
LIBTOOLS = $(LIB)/lecture.a $(LIB)/liste.a $(LIB)/position.a
LDEPENDENCY = -lcalcul_trajectoire -lentrees -lequations
LTOOLSDEPENDENCY = -llecture -lliste -lposition
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

# ! build on .o files if .a compile fail (case study on WSL)
$(DEST)/main: $(SRC)/main.c $(LIBS) $(LIBTOOLS) 
	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $< -o $@ $(LDEPENDENCY) $(LTOOLSDEPENDENCY) || gcc $(INCLUDE) $(MODULES) $(TOOLS) $(WARNINGS) $< -o $@

# library compile

init: $(LIBS) $(LIBTOOLS)

# ? using pattern rules to automatically compile .o files from MODULES source list
# https://www.gnu.org/software/make/manual/html_node/Static-Usage.html#Static-Usage
$(LIBS): $(LIB)/%.a: $(SRC)/%
	cd $< && make init

$(LIBTOOLS): $(LIB)/%.a: $(SRC)/tools/%
	cd $< && make init

# dependencies unit tests

# ! build on .o files if .a compile fail (case study on WSL)
test/%: %.c $(LIBTOOLS)
	gcc $(INCLUDE) -L $(LIB) $(WARNINGS) $(DEBUG) $(TESTS) $< -o $* $(LTOOLSDEPENDENCY) || gcc $(INCLUDE) $(TOOLS) $(WARNINGS) $< -o $@
	./$* 
	rm $*

# project cleanup

prune:
	rm -f $(MODULE)/*
	rm -f $(LIB)/*
	rm -f $(DEST)/*