LIB = equations.a
DEST = ../../lib
MODULE = ../../module
MODULES = $(MODULE)/custom_transform.o $(MODULE)/hugo_transform.o $(MODULE)/lorenz_transform.o $(MODULE)/mihaja_transform.o
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

