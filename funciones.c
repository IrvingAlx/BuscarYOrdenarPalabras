#include "defTipos.h"

void guardarDato(char dato[]);

extern nodo *insertarNodoArbol(nodo *pt, char pal[]) {
	nodo *nuevo, *aux;

	aux = pt;
	int salir = 1;
	nuevo = (nodo *)malloc(sizeof(nodo));
	if (nuevo == NULL) {
		printf("\nNo hay memoria disponible.\n\n");
		exit(1);
	}
	strcpy(nuevo->pal, pal);
	nuevo->izq = NULL;
	nuevo->der = NULL;

	if (aux == NULL)
		pt = nuevo;
	while ((aux != NULL) && (salir != 0)) {
		if (strcmp(pal, aux->pal) > 0) // Mover a la derecha
		{
			if (aux->der != NULL)
				aux = aux->der;
			else {
				aux->der = nuevo;
				salir = 0;
			}
		}
		if (strcmp(pal, aux->pal) <= 0) // Mover a la izquierda
		{
			if (aux->izq != NULL)
				aux = aux->izq;
			else {
				// aux->rep=aux->rep+1;
				aux->izq = nuevo;
				salir = 0;
			}
		}
	}
	return pt;
}

extern int
recorrer(nodo *aux, char userData[], int numero) // En orden ascendente
{
	if (aux != NULL) {
		numero = recorrer(aux->izq, userData, numero);
		if (strcmp(aux->pal, userData) == 0) {
			numero = numero + 1;
		}
		guardarDato(aux->pal);
		numero = recorrer(aux->der, userData, numero);
	}
	return numero;
}

extern void guardarDato(char dato[]) {
	FILE *fp;

	fp = fopen("palabrasOrdenadas.txt", "a");

	if (fp == NULL) {
		printf("\nArchivo no encontrado.");
		exit(1);
	}
	fprintf(fp, "%s\n", dato);
	fclose(fp);

	return;
}

extern int buscDirect(nodo *pt, char userData[]) {
	int encontrado = 0;
	int niveles = 0;

	while ((pt != NULL) && (encontrado == 0)) {
		if (strcmp(pt->pal, userData) == 0) {
			encontrado = 1;
			printf("\nPalabra %s sí existe en el árbol. \n", pt->pal);
		} else {
			if (strcmp(pt->pal, userData) != 0) {
				pt = pt->der;
			} else {
				pt = pt->izq;
			}
			encontrado = 0;
		}
	}

	return encontrado;
}