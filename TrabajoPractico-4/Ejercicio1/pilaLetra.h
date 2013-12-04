#ifndef _PILA_LETRA
#define _PILA_LETRA

struct t_nodo {
    char valor;
    t_nodo * sig;
};

struct t_pila {
    int maximo;
    int cantidad;
    t_nodo * cabeza;
};

void crearPila(t_pila * &pila);
void crearPilaLimitada(t_pila * &pila, int maximoPosible);
void inicializarPila(t_pila * &pila, int maxPosible);
bool pilaVacia(t_pila * pila);
bool pilaLlena(t_pila * pila);
void apilar(t_pila * &pila, const char valor);
void desapilar(t_pila * &pila, char &valor);
void destruirPila(t_pila * &pila);

#endif