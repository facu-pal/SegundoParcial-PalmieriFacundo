/*
 * utn.h
 *
 *  Created on: 9 jun. 2021
 *      Author: facun
 */

#ifndef UTN_H_
#define UTN_H_

int myGets(char* cadena, int longitud);

int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);

int getInt(int* pResultado);

int esNumerica(char* cadena, int longitud);

int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

int getFloat(float* pResultado);

int esFlotante(char* cadena, int longitud);

int utn_getFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

void getChar(char* mensaje, char* rta);

int utn_getConfirm(void);



#endif /* UTN_H_ */
