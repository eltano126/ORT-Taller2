#include "pilaLetra.h"
#include "comun.h"
#include <iostream>
#include <string.h>
using namespace std;

void crearPila(t_pila * &pila) {
    pila = new t_pila();
    inicializarPila(pila, -1);
}

void crearPilaLimitada(t_pila * &pila, int maximoPosible) {
    pila = new t_pila();
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
t_nodo * aux = new t_nodo();
bool bFull = true;

	if (!aux) {
		bFull = false;	// No hay mas memoria disponible
	} else {
		delete aux;
		if (pila->maximo!=-1) {
			bFull = pila->cantidad == pila->maximo;
		} else {
			bFull = false;
		}
	}
	return bFull;
}

void apilar(t_pila * &pila, const char valor) {
/*
1. nodo->siguiente apunte a NULL.
2. Pila apunte a nodo.
---------------------------------
1. Hacemos que nodo->siguiente apunte a Pila.
2. Hacemos que Pila apunte a nodo.
*/
	if (!pilaLlena(pila)){
		t_nodo * nodo = new t_nodo();
		nodo->valor = valor;
		if (pila->cabeza == NULL){
			pila->cabeza = nodo;
			nodo->sig = NULL;
		}else{
			nodo->sig = pila->cabeza;
			pila->cabeza = nodo;
		}
		pila->cantidad ++;
	}else{	
		cout << "La pila esta llena!" << endl;
		esperar();
	}
}

void desapilar(t_pila * &pila, char &valor) {
/*
1. Hacemos que nodo apunte al primer elemento de la pila, es decir a Pila.
2. Asignamos a Pila la dirección del segundo nodo de la pila: Pila->siguiente.
3. Guardamos el contenido del nodo para devolverlo como retorno, recuerda que la operación pop equivale a devolver y borrar.
4. Liberamos la memoria asignada al primer nodo, el que queremos eliminar.

	if (pila != NULL){
		t_nodo * nodo = new t_nodo();
		nodo->sig = pila->cabeza;
		valor= nodo->sig->valor;
		pila->cabeza = pila->cabeza->sig;
		pila->cantidad --;
		delete nodo;
	}*/

	if (pila != NULL){
		t_nodo * nodo = new t_nodo();
		nodo = pila->cabeza;
		valor= nodo->valor;
		pila->cabeza = nodo->sig;
		pila->cantidad --;
		delete nodo;
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