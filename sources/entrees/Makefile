LIB = entrees.a
DEST = ../../lib
MODULE = ../../module
MODULES = $(MODULE)/demande_hugo.o $(MODULE)/demande_lorenz.o $(MODULE)/demande_mihaja.o $(MODULE)/demande_parametres.o $(MODULE)/demande_vitesse.o
INCLUDE = -I ../../include
WARNINGS = -Wall -Werror -Wextra -ggdb3

# * dependencies compile 

init: $(LIB)

$(LIB): $(MODULES)
	ar rcs $(DEST)/lib$@ $^

# ? using pattern rules to automatically compile .o files from MODULES source list
# https://www.gnu.org/software/make/manual/html_node/Static-Usage.html#Static-Usage
$(MODULES): $(MODULE)/%.o: %.c 
	gcc $(INCLUDE) $(WARNINGS) -c -o $@ $<

