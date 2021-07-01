/*
 * Libro.h
 *
 *  Created on: 1 jul. 2021
 *      Author: facun
 */

#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct
{
    int id;
    char titulo[128];
	char autor[128];
	int precio;
	int editorialId;
}eLibro;

eLibro* libro_new();
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIdStr);
void libro_delete();

int libro_setId(eLibro* this,int id);
int libro_getId(eLibro* this,int* id);

int libro_setTitulo(eLibro* this,char* titulo);
int libro_getTitulo(eLibro* this,char* titulo);

int libro_setPrecio(eLibro* this,int precio);
int libro_getPrecio(eLibro* this,int* precio);

int libro_setAutor(eLibro* this,char* autor);
int libro_getAutor(eLibro* this,char* autor);

int libro_setEditorialId(eLibro* this,int editorialId);
int libro_getEditorialId(eLibro* this,int* editorialId);

int libro_EditorialToId(int* id, char* editorialIdStr);
int libro_IdToEditorial(int id, char* editorialIdStr);

void libro_print(eLibro* this);

int libro_sortAutor(void* thisOne, void* thisTwo);
void libro_ponerDescuento(void* this);

#endif /* LIBRO_H_ */
