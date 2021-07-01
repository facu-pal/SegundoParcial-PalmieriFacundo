#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libro.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int */
int parser_LibroFromText(FILE *pFile, LinkedList *pArrayListLibro) {

	int retorno = -1;
	int cantLeido;
	char buffer[5][128];
	eLibro *pAuxLibro = NULL;

	if (pFile != NULL && pArrayListLibro != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],
				buffer[2], buffer[3], buffer[4]);
		do {
			cantLeido = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
			if (cantLeido < 5) {
				libro_delete(pAuxLibro);
				retorno = -1;
				break;
			} else {
				pAuxLibro = libro_newParametros(buffer[0], buffer[1], buffer[2],
						buffer[3], buffer[4]);
				if (pAuxLibro != NULL) {
					ll_add(pArrayListLibro, pAuxLibro);
					retorno = 0;
				}
			}
		} while (!feof(pFile));
	}

	return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int */
int parser_LibroFromBinary(FILE *pFile, LinkedList *pArrayListLibro) {
	int retorno = -1;
	int retornoLeido;
	eLibro *pAuxLibro = NULL;

	if (pFile != NULL && pArrayListLibro != NULL) {
		do {
			pAuxLibro = libro_new();
			if (pAuxLibro != NULL) {
				retornoLeido = fread(pAuxLibro, sizeof(eLibro), 1, pFile);
				if (retornoLeido != 1) {
					libro_delete(pAuxLibro);
					break;
				} else {
					ll_add(pArrayListLibro, pAuxLibro);
					retorno = 0;
				}
			}
		} while (!feof(pFile));
	}
	return retorno;
}
