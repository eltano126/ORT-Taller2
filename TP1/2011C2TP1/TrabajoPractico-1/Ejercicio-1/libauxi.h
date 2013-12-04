#include <stdio.h>
#define NOMBREARCH "estadistica.csv"

void PrepararEstadistica(FILE * &fDatos);
void GuardarEstadistica(FILE * &fDatos, const char * metodo, const int cantElem, const int cantComp, const int cantMov);
void CerrarEstadística(FILE * &fDatos);