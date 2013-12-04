#include "pilaLetra.h"
#include <string.h>

void crearPila(t_pila * &pila) {
    pila = new t_pila;
    inicializarPila(pila, -1);
}
void crearPilaLimitada(t_pila * &pila, int maximoPosible) {
    pila = new t_pila;
    inicializarPila(pila, maximoPosible);
}
void inicializarPila(t_pila * &pila, int maxPosible) {
    if (pila) {
        pila->maximo = maxPosible;
        pila->cantidad = 0;
        pila->cabeza = NULL;
    }
}
bool pilaVacia(t_pila * pila) {
	if (!pila) {
		return true;
	} else {
		return pila->cabeza == NULL;
	}
}
bool pilaLlena(t_pila* pila) {
// implementación especial que contempla tanto la posibilidad de quedarse sin memoria disponible
// como la de alcanzar un límite determinado por el programador.
t_nodo * aux = new t_nodo;
	if (!aux) {
		return false;	// No hay mas memoria disponible
	} else {
		delete aux;
		if (pila->maximo!=-1) {
			return pila->cantidad == pila->maximo;
		} else {
			return false;
		}
	}
}

void apilar(t_pila * &pila, const char valor) {
	
	if (!pilaLlena (pila)) {
		t_nodo * nodo = new t_nodo;
		nodo->valor = valor;
		nodo->sig = pila->cabeza;
		pila ->cabeza = nodo;
		pila ->cantidad ++;
	}

}
void desapilar(t_pila * &pila, char &valor){

	t_nodo * pEliminar;

	if (!pilaVacia (pila)) {
		pEliminar = pila->cabeza;//Aca pongo en el auxiliar el nodo a eliminar
		valor = pEliminar->valor; //Aca se lleva el valor del primer nodo que apunta la cabeza
		pila->cabeza = pEliminar->sig;//cambio el puntero y lo apunto al elemento "anterior" de la pila (que seria el pSig)
		delete pEliminar;
	}

}

void destruirPila(t_pila * &pila) {
    while(!pilaVacia(pila)) {
        t_nodo * aux = pila->cabeza;
        pila->cabeza = aux->sig;
        delete aux;
    }
    delete pila;
    pila = NULL;
}