#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[5000];
	if(cadena!=NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString))<=longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos){

		int retorno = -1;
		char bufferString[40];

		if(aux != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
		{
			do
			{
				printf("%s", mensaje);
				if(myGets(bufferString,40)==0)
				{
					strcpy(aux, bufferString);
					retorno=0;
					break;
				}
				else
				{
					printf("%s", mensajeError);
					reintentos--;
				}
			}while(reintentos>=0);
		}
		return retorno;
	}

int esNumerica(char* cadena, int longitud)
{
	int retorno= 1;
	int i;
	if(cadena!=NULL)
	{

		for(i=0; i<longitud && cadena[i]!='\0'; i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i]>'9')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}


int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];
	if(pResultado!=NULL)
	{
		if(myGets(bufferString, sizeof(bufferString))==0 && esNumerica(bufferString, sizeof(bufferString))==1)
		{
			*pResultado=atoi(bufferString);
			retorno=0;
		}
	}

	return retorno;
}


int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

				printf("%s", mensaje);
		do
		{
			if(getInt(&bufferInterno)==0 && bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}


int esFlotante(char* cadena, int longitud)
{
	int retorno= 1;
	int i;
	int contadorPunto=0;
	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0; i<longitud && cadena[i]!='\0'; i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i]>'9')
			{
				if(cadena[i]=='.' && contadorPunto==0)
				{
					contadorPunto++;
				}
				else
				{
				retorno=0;
				break;
				}
			}
		}
	}
	return retorno;
}

int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[64];
	if(pResultado!=NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esFlotante(buffer, sizeof(buffer))==1)
		{
			*pResultado=atof(buffer);
			retorno=0;
		}
	}
	return retorno;
}

int utn_getFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferInterno)==0 && bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
void getChar(char* mensaje, char* rta)
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", rta);
}
int utn_getConfirm(void)
{
	int retorno = -1;
	char c;

	getChar("\n Ingrese 's' para si o 'n' para no \n", &c);

	while(c!='s' && c!='n')
	{
		puts("Error.Ingrese 's' para si o 'n' para no\n");
		getChar("Ingrese Si 's' o No 'n'\n", &c);

	}
		if(c=='s')
		{
			retorno = 0;
		}
	return retorno;
}

