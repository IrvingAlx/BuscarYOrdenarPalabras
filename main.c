#include "defTipos.h"

nodo *insertarNodoArbol(nodo *pt, char pal[]);
int recorrer(nodo *pt, char userData[], int numero);
int buscDirect(nodo *pt, char userData[]);

int main(int argc, char *argv[]) {
	int juan = 0;
	int notjuan = 0;
	nodo *raiz;
	char palabra[40];
	FILE *fp;
	char userData[40];
	raiz = NULL;
	remove("palabrasOrdenadas.txt");

	printf("\nQue palabra desea buscar\n");
	scanf(" %s", userData);

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("\nArchivo no disponible.\n");
		exit(1);
	}
	while (fscanf(fp, "%s", palabra) == 1) {
		raiz = insertarNodoArbol(raiz, palabra);
	}
	fclose(fp);
	notjuan = buscDirect(raiz, userData);

	juan = recorrer(raiz, userData, juan); // Es para revisar el árbol creado
	if (notjuan == 1) {
		printf("%s se ha repetido: %i veces\n", userData, juan - 1);
	} else {
		printf("Palabra %s no existe en el arbol\n", userData);
	}

	return 0;
}
