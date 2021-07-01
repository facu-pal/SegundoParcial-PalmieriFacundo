#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"
#include "UTN.h"

void libro_delete(eLibro* this)
{
	free(this);
}
eLibro* libro_new()
{
	eLibro* pAux=NULL;
	pAux=(eLibro*)malloc(sizeof(eLibro));
	if(pAux!=NULL)
	{
		pAux->id=0;
		strcpy(pAux->titulo,"");
		strcpy(pAux->autor,"");
		pAux->precio=0;
		pAux->editorialId=0;

	}
	return pAux;
}
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIdStr)
{
	eLibro* pAuxLibro = libro_new();
	int auxId;
	if(pAuxLibro!=NULL && idStr!=NULL && tituloStr!=NULL && autorStr!=NULL && precioStr!=NULL && editorialIdStr!=NULL)
	{
		if((libro_setId(pAuxLibro,atoi(idStr))!=0) ||
		(libro_setTitulo(pAuxLibro,tituloStr)!=0) ||
		(libro_setAutor(pAuxLibro,autorStr)!=0) ||
		(libro_setPrecio(pAuxLibro,atoi(precioStr))!=0) ||
		(libro_EditorialToId(&auxId, editorialIdStr)!=0) ||
		(libro_setEditorialId(pAuxLibro, auxId)!=0))
		{
			free(pAuxLibro);
			pAuxLibro=NULL;
		}
	}
	return pAuxLibro;
}
int libro_setId(eLibro* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}
int libro_getId(eLibro* this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}
int libro_setTitulo(eLibro* this,char* titulo)
{
	int retorno=-1;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(this->titulo,titulo);
		retorno=0;
 	}
	return retorno;
}
int libro_getTitulo(eLibro* this,char* titulo)
{
	int retorno=-1;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo,this->titulo);
		retorno=0;
	}
	return retorno;
}
int libro_setPrecio(eLibro* this,int precio)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->precio=precio;
		retorno=0;
	}
	return retorno;
}
int libro_getPrecio(eLibro* this,int* precio)
{
	int retorno=-1;
	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		retorno=0;
	}
	return retorno;
}
int libro_setAutor(eLibro* this,char* autor)
{
	int retorno=-1;
	if(this!=NULL && autor!=NULL)
	{
		strcpy(this->autor,autor);
		retorno=0;
	}
	return retorno;
}
int libro_getAutor(eLibro* this,char* autor)
{
	int retorno=-1;
	if(this!=NULL && autor!=NULL)
	{
		strcpy(autor,this->autor);
		retorno=0;
	}
	return retorno;
}
int libro_setEditorialId(eLibro* this,int editorialId)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->editorialId=editorialId;
		retorno=0;
	}
	return retorno;
}
int libro_getEditorialId(eLibro* this,int* editorialId)
{
	int retorno=-1;
	if(this!=NULL && editorialId!=NULL)
	{
		*editorialId=this->editorialId;
		retorno=0;
	}
	return retorno;
}
int libro_EditorialToId(int* id, char* editorialIdStr)
{
	int retorno=-1;
	if(editorialIdStr!=NULL && id!=NULL)
	{
		retorno=0;
		if(stricmp(editorialIdStr,"planeta")==0)
		{
			*id=1;
		}
		if(stricmp(editorialIdStr,"siglo xxi editores")==0)
		{
			*id=2;
		}
		if(stricmp(editorialIdStr,"pearson")==0)
		{
			*id=3;
		}
		if(stricmp(editorialIdStr,"minotauro")==0)
		{
			*id=4;
		}
		if(stricmp(editorialIdStr,"salamandra")==0)
		{
			*id=5;
		}
		if(stricmp(editorialIdStr,"penguin books")==0)
		{
			*id=6;
		}
	}
	return retorno;
}

int libro_IdToEditorial(int id, char* editorialIdStr)
{
	int retorno=-1;
	if(editorialIdStr!=NULL && id>0 && id<7)
	{
		retorno=0;
		switch(id)
		{
		case 1:
			strcpy(editorialIdStr,"PLANETA");
			break;
		case 2:
			strcpy(editorialIdStr,"SIGLO XXI EDITORES");
			break;
		case 3:
			strcpy(editorialIdStr,"PEARSON");
			break;
		case 4:
			strcpy(editorialIdStr,"MINOTAURO");
			break;
		case 5:
			strcpy(editorialIdStr,"SALAMANDRA");
			break;
		case 6:
			strcpy(editorialIdStr,"PENGUIN BOOKS");
			break;
		}
	}
	return retorno;
}

void libro_print(eLibro* this)
{
	int auxId, auxPrecio, auxEditorialId;
	char auxTitulo[128], auxAutor[128], auxEditorial[128];
	if(libro_getId(this, &auxId)==0 && libro_getTitulo(this, auxTitulo)==0 &&
	   libro_getAutor(this, auxAutor)==0 && libro_getPrecio(this, &auxPrecio)==0 &&
	   libro_getEditorialId(this, &auxEditorialId)==0 &&
	   libro_IdToEditorial(auxEditorialId, auxEditorial)==0) //&& utn_putDay(auxPrecio, auxEditorialId)==0)
	{
		printf("Id: %d - Titulo: %s  - Autor: %s - Precio: %d - Editorial: %s\n",auxId,auxTitulo,auxAutor,auxPrecio,auxEditorial);
	}
}

int libro_sortAutor(void *thisOne, void *thisTwo) {
	int retorno = 0;
	char auxAutor1[128], auxAutor2[128];
	if (thisOne != NULL && thisTwo != NULL) {
		if (libro_getAutor((eLibro*) thisOne, auxAutor1) == 0
				&& libro_getAutor((eLibro*) thisTwo, auxAutor2) == 0) {
			if (strcmp(auxAutor1, auxAutor2) > 0) {
				retorno = 1;
			}
			if (strcmp(auxAutor1, auxAutor2) < 0) {
				retorno = -1;
			}
		}
	}
	return retorno;
}

void libro_putDescuento(void* this)
{
	int auxId, auxPrecio;
	if( libro_getEditorialId((eLibro*)this, &auxId)==0 && libro_getPrecio((eLibro*)this, &auxPrecio)==0 )
	{
		switch(auxId)
		{
		case 1: //  planeta
			if(auxPrecio>=300)
			{
				auxPrecio=auxPrecio-(auxPrecio*20/100);
				libro_setPrecio(this, auxPrecio);
			}
			break;
		case 2: //  siglo xxi
			if(auxPrecio<=200)
			{
				auxPrecio=auxPrecio-(auxPrecio*10/100);
				libro_setPrecio(this, auxPrecio);
			}
			break;
		case 3: //person
			break;
		case 4: // minotauro
			break;
		case 5: // salamandra
			break;
		case 6: // pinguns
			break;
		}
	}
}

