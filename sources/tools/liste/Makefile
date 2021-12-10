MODULES = nouvelle_liste.o ajouter_liste.o supprimer_liste.o
INCLUDE = -I ../../../include
WARNINGS = -Wall -Werror -Wextra -ggdb3
DEST = ../../../module

# * dependencies compile 

init: $(MODULES)

# ? using pattern rules to automatically compile .o files from MODULES source list
# https://www.gnu.org/software/make/manual/html_node/Static-Usage.html#Static-Usage
$(MODULES): %.o: %.c 
	gcc $(INCLUDE) $(WARNINGS) -c -o $(DEST)/$@ $<