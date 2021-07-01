/*
 ============================================================================
 Name        : 2-parcial-Palmieri.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libro.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);

	int option;
    int flag=0;
	LinkedList *eLibros = ll_newLinkedList();
	do {
		if (utn_getInt(&option, "Menu\n"
				"1. Cargar Archivo\n"
				"2. Ordenar lista de Libros\n"
				"3. Imprimir listado de Libros\n"
				"4. Informes\n"
				"5. Guardar listado en archivo\n"
				"6. Salir\n"
				"Selecione una opcion:", "Error. Menu\n"
				"1. Cargar Archivo\n"
				"2. Ordenar lista de Libros\n"
				"3. Imprimir listado de Libros\n"
				"4. Informes\n"
				"5. Guardar listado en archivo\n"
				"6. Salir\n"
				"Selecione una opcion:", 1, 6, 2) == 0) {

			switch (option) {
			case 1:
				if (flag == 0) {
					if (controller_loadFromText("Datos.csv", eLibros) == 0) {
						flag = 1;
					}
				} else {
					printf("El archivo ya fue cargado\n");
				}
				break;
			case 2:
				if (flag == 1) {
					controller_sortLibro(eLibros);
				} else {
					printf("carge un archivo, opcion 1\n");
				}
				break;
			case 3:
				if (flag == 1) {
					controller_printLibro(eLibros);
				} else {
					printf("carge un archivo, opcion 1\n");
				}
				break;
			case 4:
				if (flag == 1) {
					controller_ponerDescuentoLibro(eLibros);
					if(utn_getConfirm()==0){
						controller_printLibro(eLibros);
					}
				} else {
					printf("carge un archivo, opcion 1\n");
				}
				break;
			case 5:
				if (flag == 1) {
					controller_saveAsText("mapeado.csv", eLibros);
					printf("Se guardo el nuevo archivo en mapeado.csv\n");
				}
				break;
			}
		}
	} while (option != 6);

	return EXIT_SUCCESS;
}
