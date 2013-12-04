#include "Lista.h"
#include "comun.h"
#include <iostream>
#include <string.h>
using namespace std;

void crearLista(t_lista * &lista) 
{
    lista = new t_lista();
    inicializarLista(lista, -1);
}

void crearListaLimitada(t_lista * &lista, int maximoPosible) 
{
    lista = new t_lista();
    inicializarLista(lista, maximoPosible);
}

void inicializarLista(t_lista * &lista, int maxPosible) 
{
    if (lista) {
        lista->maximo = maxPosible;
        lista->cantidad = 0;
        lista->cabeza = NULL;
    }
}

bool listaVacia(t_lista * lista) 
{
	if (!lista) {
		return true;
	} else {
		return lista->cabeza == NULL;
	}
}

bool listaLlena(t_lista * lista) 
{
// implementación especial que contempla tanto la posibilidad de quedarse sin memoria disponible
// como la de alcanzar un límite determinado por el programador.
t_nodo * aux = new t_nodo();
bool bFull = true;

	if (!aux) {
		bFull = false;	// No hay mas memoria disponible
	} else {
		delete aux;
		if (lista->maximo!=-1) {
			bFull = lista->cantidad == lista->maximo;
		} else {
			bFull = false;
		}
	}
	return bFull;
}

int ValidarNomApe(t_agenda agenda, t_agenda list)
{
	int a;
	if(stricmp(agenda.Ape,list.Ape) == 0)
	{	//Si los apellidos son iguales, verifico los nombres
		if ((stricmp(agenda.Nom,list.Nom)) == 0)
		{
			a = 0;
		}
		else
		{
			a = stricmp(agenda.Nom,list.Nom);
		}
	}
	else
	{
		a = stricmp(agenda.Ape,list.Ape);
	}
	return a;
}

void enlazar(t_lista * &lista, t_agenda agenda) 
{
	t_nodo * nodo = new t_nodo();
	t_nodo * aux = new t_nodo();
	int a;
	nodo->agenda = agenda;
	nodo->sig = NULL;
	if (!listaLlena(lista))
	{	//Si la lista esta vacia, asigno el nodo a la cabeza de la lista
		if (lista->cabeza == NULL)
		{
			lista->cabeza = nodo;
		}
		else if(ValidarNomApe(agenda, lista->cabeza->agenda) < 0)
			{	//Si el Apellido y Nombre son menores al 1º elemento de la lista, intercalo el nodo
				nodo->sig = lista->cabeza;
				lista->cabeza = nodo;
			}
		else
		{
		aux = lista->cabeza;
		//Si no, busco la posicion en la lista
		while ((aux->sig != NULL) && (a = ValidarNomApe(agenda, aux->agenda) > 0))
		{
			aux = aux->sig;
		}
		nodo->sig = aux->sig;
		aux->sig = nodo;
		}
		lista->cantidad++;
	}
}


void desenlazar(t_lista * &lista, t_agenda &agenda) 
{
	if (!listaVacia(lista)){
		t_nodo * nodo = lista->cabeza;
        lista->cabeza = nodo->sig;
		agenda = nodo->agenda;
        delete nodo;
		lista->cantidad --;
	}
}

void destruirLista(t_lista * &lista) 
{
    while(!listaVacia(lista)) 
	{
        t_nodo * nodo = lista->cabeza;
        lista->cabeza = nodo->sig;
        delete nodo;
    }
    delete lista;
    lista = NULL;
}

