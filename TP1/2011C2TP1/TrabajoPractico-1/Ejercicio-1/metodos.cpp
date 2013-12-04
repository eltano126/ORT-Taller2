#include "metodos.h"

void MaximosSucesivos(t_data &datos, int &comparaciones, int &intercambios) {
    int tope = datos.tope;
    comparaciones = 0;
    intercambios = 0;
    for (int a=0; a < tope; a++) {
        for (int b=a+1; b < tope; b++) {
            comparaciones++;
            if (datos.valores[a]>datos.valores[b]) {
                intercambios++;
                trasponer(datos.valores[a], datos.valores[b]);
            }
        }
    }
}
void Burbuja(t_data &datos, int &comparaciones, int &intercambios) {
    int tope = datos.tope - 1;
    comparaciones = 0;
    intercambios = 0;
    for (int a=0; a < tope; a++) {
        for (int b=0; b < tope-a; b++) {
           comparaciones++;
           if (datos.valores[b]>datos.valores[b+1]) {
                intercambios++;
                trasponer(datos.valores[b], datos.valores[b+1]);
            }
        }
    }
}
void BurbujaMejorado(t_data &datos, int &comparaciones, int &intercambios) {
    int tope = datos.tope - 1;
    int a = 0;
    bool sinCambios = true;
    comparaciones = 0;
    intercambios = 0;
    do {
        for (int b=0; b < tope-a; b++) {
            comparaciones++;
            if (datos.valores[b]>datos.valores[b+1]) {
                intercambios++;
                trasponer(datos.valores[b], datos.valores[b+1]);
                sinCambios = false;
            }
        }
        a++;
    } while ((a < tope) && (!sinCambios));
}
void ShellSort(t_data &datos, int &comparaciones, int &intercambios) {
    int tope = datos.tope;
    bool cambio = false;
    int d=tope;
    comparaciones = 0;
    intercambios = 0;
    while( (cambio) || (d > 1)) {
        cambio = false;
        d = (d+1) / 2;
        for (int i = 0; i < (tope - d); i++) {
            comparaciones++;
            if (datos.valores[i] > datos.valores[i + d]) {
                trasponer(datos.valores[i], datos.valores[i + d]);
                intercambios++;
                cambio = true;
            }
        }
    }
}
void trasponer(int &A, int &B) {
    int aux = A;
    A = B;
    B = aux;
}
void crearCopia(t_data &destino, const t_data origen) {
    destino.tope = origen.tope;
    for (int p=0; p<destino.tope; p++) {
        destino.valores[p] = origen.valores[p];
    }
}