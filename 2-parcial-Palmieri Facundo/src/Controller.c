#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"
#include "LinkedList.h"
#include "parser.h"
#include "UTN.h"

int controller_loadFromText(char *path, LinkedList *pArrayListLibro) {
	int retorno = -1;
	int auxParser;
	FILE *pArchivoTexto;
	pArchivoTexto = fopen(path, "r");
	if (pArchivoTexto == NULL) {
		printf("Este archivo no existe");
	} else {
		auxParser = parser_LibroFromText(pArchivoTexto,pArrayListLibro);
		if (auxParser == 0) {
			fclose(pArchivoTexto);
			printf("Se lleyo correctamenta el archivo, y se cerro\n");
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListLibro) {
	int retorno = -1;
	int auxParser;

	if (path != NULL && pArrayListLibro != NULL) {
		FILE *pFile = fopen(path, "rb");
		auxParser = parser_LibroFromBinary(pFile, pArrayListLibro);
		if (auxParser == 0) {
			printf("Archivo bien leido. Cerrado correctamente\n");
			retorno = 0;
			fclose(pFile);
		} else {
			printf("No se pudo leer el archivo\n");
			retorno = -1;
		}
	}
	return retorno;
}

/** \brief Busca Id Maximo
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_getMaxId(LinkedList *pArrayListLibro) {
	int retorno = -1;
	int cantidadLinkedList;
	int id;
	eLibro *pAuxLibro = NULL;

	if (pArrayListLibro != NULL && ll_isEmpty(pArrayListLibro) == 0) {
		cantidadLinkedList = ll_len(pArrayListLibro);
		for (int i = 0; i < cantidadLinkedList; i++) {
			pAuxLibro = (eLibro*) ll_get(pArrayListLibro, i);
			libro_getId(pAuxLibro, &id);
			if (id > retorno) {
				retorno = id;
			}
		}
	}
	return retorno;
}



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_printLibro(LinkedList *pArrayListLibro) {
	int retorno = -1;
	int auxId;
	int auxPrecio;
	int auxEditorialId;
	char auxTitulo[128];
	char auxAutor[128];
	char auxEditorialStr[128];
	eLibro *pAuxLibro = NULL;
	int cantidadLinkedList;
	if (pArrayListLibro != NULL) {
		if (ll_isEmpty(pArrayListLibro) == 0) {
			cantidadLinkedList = ll_len(pArrayListLibro);
			printf("Id		Titutlo		   	  	    	  Autor  	        Precio	  Editorial\n");
			for (int i = 0; i < cantidadLinkedList; i++) {
				pAuxLibro = (eLibro*) ll_get(pArrayListLibro, i);
				if (libro_getId(pAuxLibro, &auxId) != 0
						|| libro_getTitulo(pAuxLibro, auxTitulo) != 0
						|| libro_getAutor(pAuxLibro, auxAutor) != 0
						|| libro_getPrecio(pAuxLibro, &auxPrecio) != 0
						|| libro_getEditorialId(pAuxLibro, &auxEditorialId) != 0
						|| libro_IdToEditorial(auxEditorialId, auxEditorialStr)
								!= 0) {
					retorno = -1;
					printf("Error, al imprimir lista\n");
					break;
				} else {
					printf("%-4d %-50s	%-15s 	%5d  	  %-20s\n", auxId,
							auxTitulo, auxAutor, auxPrecio, auxEditorialStr);
					retorno = 0;
				}
			}
		} else {
			printf("No hay lista para imprimir\n");
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_sortLibro(LinkedList *pArrayListLibro) {
	int retorno = -1;

	if (pArrayListLibro != NULL) {
		ll_sort(pArrayListLibro, libro_sortAutor, 1);
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListLibro) {
	int retorno = -1;
	int auxCantLink, auxId, auxPrecio, auxEditorialId;
	char auxTitulo[128], auxAutor[128], auxEditorial[128];
	FILE *pFile;
	eLibro *pAuxLibro = NULL;
	if (path != NULL && pArrayListLibro != NULL) {
		if ((pFile = fopen(path, "w")) == NULL) {
			printf("No se pudo escribir el archivo\n");
		} else {
			auxCantLink = ll_len(pArrayListLibro);
			fprintf(pFile, "id,titulo,autor,precio,editorialId\n");
			for (int i = 0; i < auxCantLink; i++) {
				pAuxLibro = (eLibro*) ll_get(pArrayListLibro, i);
				if (libro_getId(pAuxLibro, &auxId) == 0
						&& libro_getTitulo(pAuxLibro, auxTitulo) == 0
						&& libro_getAutor(pAuxLibro, auxAutor) == 0
						&& libro_getPrecio(pAuxLibro, &auxPrecio) == 0
						&& libro_getEditorialId(pAuxLibro, &auxEditorialId) == 0
						&& libro_IdToEditorial(auxEditorialId, auxEditorial)
								== 0) {
					fprintf(pFile, "%d,%s,%s,%d,%s\n", auxId, auxTitulo,
							auxAutor, auxPrecio, auxEditorial);
					retorno = 0;
				}
			}
			printf("Archivo bien escrito. Guardado correctamente\n");
		}
		fclose(pFile);
	}
	return retorno;
}

int controller_ponerDescuentoLibro(LinkedList *pArrayListLibro) {
	int retorno = -1;
	void (*pFunc)(void *element);
	if (pArrayListLibro != NULL) {
		pFunc = libro_ponerDescuento;
		ll_map(pArrayListLibro, pFunc);
	}
	return retorno;
}
