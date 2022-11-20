#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento {
	char pal[40];
	struct elemento *izq, *der;
};
typedef struct elemento nodo;