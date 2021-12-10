MODULES = calcul_trajectoire.o demande_lorenz.o demande_hugo.o demande_mihaja.o demande_parametres.o lorenz_transform.o hugo_transform.o mihaja_transform.o nouvelle_trajectoire.o demande_vitesse.o custom_transform.o
INCLUDE = -I ../include
WARNINGS = -Wall -Werror -Wextra -ggdb3
DEST = ../module
TESTS = -DTESTS -DUSECOLORS

# * dependencies compile 

init: $(MODULES)

# ? using pattern rules to automatically compile .o files from MODULES source list
# https://www.gnu.org/software/make/manual/html_node/Static-Usage.html#Static-Usage
$(MODULES): %.o: %.c 
	gcc $(INCLUDE) $(WARNINGS) -c -o $(DEST)/$@ $<

# single module compile

%.o: %.c 
	gcc $(INCLUDE) $(WARNINGS) -c -o $(MODULES)/$@ $<
