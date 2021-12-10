Enigma
======

This is the source code of our computer science science project for the 3rd semester of CUPGE. 
For more information and a user guide, head over to our [documentation](docs/README.md).

# Getting started

> **Note**
> You **must** have a working copy of gnuplot installed on your operating system in order to run the program correctly

To start the project, just open your terminal and type :

```bash
make
```

This will automatically compile all the files needed by the program then executes it.

However if you want a more detailed step, this command first compile all the librairies with :

```bash
make init
```

Then compile and run the `main` program with :

```bash
make start
```

If you want to remove all the clutter the script did and start from fresh, type :

```bash
make prune
```


# Debugging

Most of the functions do have unit tests. To check them, type :

```bash
make test/{the path of the file without the extension}
```

>Example : `make test/entrees/demande_vitesse` to run demande_vitesse.c unit tests

# About

© 2021 Hugo AVRIL - Mihaja RAZAFIMAHEFA