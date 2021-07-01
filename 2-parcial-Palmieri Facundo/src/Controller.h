/*
 * Controller.h
 *
 *  Created on: 1 jul. 2021
 *      Author: facun
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListLibro);
int controller_printLibro(LinkedList* pArrayListLibro);
int controller_sortLibro(LinkedList* pArrayListLibro);
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);
int controller_getMaxId(LinkedList* pArrayListLibro);
int controller_ponerDescuentoLibro(LinkedList* pArrayListLibro);


#endif /* CONTROLLER_H_ */
