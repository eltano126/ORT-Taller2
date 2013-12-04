#ifndef _LISTA
#define _LISTA

typedef char str50 [51];

struct t_fec {
	int dia;
	int mes;
	int año;
};

struct t_agenda {
	str50 Ape;
	str50 Nom;
	t_fec fec;
};

struct t_nodo {
    t_agenda agenda;
    t_nodo * sig;
};

struct t_lista {
    int maximo;
    int cantidad;
    t_nodo * cabeza;
};

void crearLista(t_lista * &lista);
void crearListaLimitada(t_lista * &lista, int maximoPosible);
void inicializarLista(t_lista * &lista, int maxPosible);
bool listaVacia(t_lista * lista);
bool listaLlena(t_lista * lista);
void enlazar(t_lista * &lista, t_agenda agenda);
void desenlazar(t_lista * &lista, t_agenda &agenda);
void destruirLila(t_lista * &lista);


#endif