#include "libauxi.h"

void PrepararEstadistica(FILE * &fDatos) {
    fDatos = fopen(NOMBREARCH, "wt");
    fprintf(fDatos, "%s;%s;%s;%s\n", "Metodo", "Elementos", "Comparaciones", "Movimientos");
}
void GuardarEstadistica(FILE * &fDatos, const char * metodo, const int cantElem, const int cantComp, const int cantMov) {
    fprintf(fDatos, "%s;%d;%d;%d\n", metodo, cantElem, cantComp, cantMov);
}
void CerrarEstadística(FILE * &fDatos) {
    fclose(fDatos);
}