/*
TRABAJO PRACTICO NUMERO 1
*/

#include "..\..\comun\comun.h"
#include "metodos.h"
#include "libauxi.h"
#include <iostream>
using namespace std;

// DATOS PARA LOS MENUES
#define SEPARADOR '|'
#define TITULO_MAIN "Manipulacion de Arreglos"
#define OPCIONES_MAIN "Llenar arreglo con valores sucesivos|Invertir orden de valores|Llenar con valores al azar|Mostrar valores|Ordenar|Mostrar cuadro comparativo|Exportar Estadistica|Salir"
#define SALIR_MAIN 8
#define TITULO_SORT "Ordenar"
#define OPCIONES_SORT "Maximos Sucesivos|Burbuja|Burbuja Mejorado|Shell|Volver al menu principal"
#define SALIR_SORT 5

enum e_orden { SIN_DATOS =-1, ASCENDENTE=0, DESCENDENTE, AL_AZAR };
enum e_metodo { MAX_SUCESIVOS=0, BURBUJA, BURBUJA_MEJORADO, SHELL_SORT };
struct t_estadistica {
    int comparaciones;
    int intercambios;
};
typedef t_estadistica t_resultados[SHELL_SORT+1][AL_AZAR+1];

// Prototipos de métodos que deben implementarse

void LlenarSucesivos(t_data &datos);
/*
LlenarSucesivos
===============
Objetivo: Completar el vector datos.valores desde la posición 0 (cero) hasta datos.tope - 1
	con valores que irán desde 1 a datos.tope.
Argumentos:
	datos: estructura tipo t_data. Necesita que el campo tope esté cargado con un valor entre 1 y MAXELEMENTOS
*/
void InvertirOrden(t_data &datos);
/*
InvertirOrden
=============
Objetivo: Invertir el orden de los datos cargados en el vector desde la posición 0 hasta datos.tope - 1.
	Por ejemplo, si tope vale 5 y los primeros valores ingresan como 1,2,3,4,5, deben salir como 5,4,3,2,1.
Argumentos:
	datos: estructura tipo t_data. Necesita que el campo tope esté cargado con un valor entre 1 y MAXELEMENTOS
*/
void LlenarAlAzar(t_data &datos);
/*
LlenarAlAzar
============
Objetivo: Completar el vector datos.valores desde la posición 0 (cero) hasta datos.tope - 1 con valores cargados al azar.
Argumentos:
	datos: estructura tipo t_data. Necesita que el campo tope esté cargado con un valor entre 1 y MAXELEMENTOS
*/
void MostrarValores(t_data datos);
/*
MostrarValores
==============
Objetivo: Mostrar los valores contenidos en el vector datos.valores desde la posición 0 (cero) hasta datos.tope - 1.
Argumentos:
	datos: estructura tipo t_data. Necesita que el campo tope esté cargado con un valor entre 1 y MAXELEMENTOS
*/
void MenuOrdenar(const int modo, const t_data valores, t_resultados resultados, bool &ordenados);
/*
MenuOrdenar
===========
Objetivo: Mostrar una segunda pantalla del menú con las opciones que figuran en OPCIONES_SORT
Argumentos:
	modo: entero que indica cómo están los datos (debe pasarse ordenActual con
		ASCENDENTE, DESCENDENTE o AL_AZAR (son constantes).
	valores: estructura tipo t_data. Necesita que el campo tope esté cargado con un valor
		entre 1 y MAXELEMENTOS.
	resultados: matriz donde se guardarán los datos estadísticos para un modo (ver primer argumento)
		y un método de ordenamiento.
*/
void limpiarEstadistica(t_resultados resultados);
/*
LimpiarEstadistica
==================
Objetivo: Inicializar la matriz donde se uardarán los resultados de la estadística.
Argumentos:
	resultados: matriz donde se guardarán los resultados estadísticos por cada prueba de los métodos de ordenamiento.
*/
void MostrarEstadistica(t_resultados resultados);
/*
MostrarEstadistica
==================
Objetivo: Mostrar en pantalla el resultado de la prueba de los métodos de ordenamiento.
Argumentos:
	resultados: matriz donde se deberían haber guardado los datos estadísticos de cada combinación método-modo
		de ordenamiento. Ya está implementada.
*/
void ExportarEstadistica();
/*
ExportarEstadística
===================
Objetivo: Generar un archivo CSV para abrir desde Excel y estudiar los resultados de un test masivo
	sobre los métodos de ordenamiento con vectores de distinto tamaño. . Ya está implementada.
Argumentos: No tiene.
*/

// Implementacion

void main() {
    t_data datos;							// contiene los valores a ordenar
    t_resultados resultados;				// contendrá la estadística de comparación entre los métodos de ordenamiento
	// Sirven para saber si existen datos para ordenar, y si los mismos fueron procesados al menos una vez.
    int ordenActual = SIN_DATOS;
	bool ordenados = false;
	datos.tope = 10;  // Para que se puedan testear comodamente los métodos implementados.

	limpiarEstadistica(resultados);
    int opcion = menu(TITULO_MAIN, OPCIONES_MAIN, SEPARADOR);
    while (opcion != SALIR_MAIN) {
        switch(opcion) {
			//...
			//...
			//...
        }
        opcion = menu(TITULO_MAIN, OPCIONES_MAIN, SEPARADOR);
    }
}

// rutinas ya implementadas
void MostrarEstadistica(t_resultados resultados) {
    typedef char t_str[20];
    const t_str nombresMetodos[] = {"Mayores Sucesivos", "Burbuja", "Burbuja Mejorado", "Shell Sort"};
    const t_str nombresOrden[] = {"Ascendente", "Descendente", "Al azar"};
    int topeMetodo = SHELL_SORT;
    int topeOrden = AL_AZAR;
    int fila;
    clrscr();
    cout << "RESULTADOS ESTADISTICOS";
    gotoxy(0, 3); cout << "METODO";
    gotoxy(20, 3); cout << "ORDEN";
    gotoxy(40, 3); cout << "COMPARACIONES";
    gotoxy(60, 3); cout << "INTERCAMBIOS";
    for (int m = 0; m <= topeMetodo; m++) {
        for (int o = 0; o <= topeOrden; o++) {
            fila = (m+1)*4+o;
            if (o==0)  { gotoxy(0, fila); cout << nombresMetodos[m]; }
            gotoxy(20, fila); cout << nombresOrden[o];
			if (resultados[m][o].comparaciones==-1) {
				gotoxy(40, fila); cout << "No calculado";
				gotoxy(60, fila); cout << "No calculado";
			} else {
				gotoxy(40, fila); cout << resultados[m][o].comparaciones;
				gotoxy(60, fila); cout << resultados[m][o].intercambios;
			}
        }
    }
    cout << endl;
    esperar();
}
void ExportarEstadistica() {
    t_data datos, datosaux;
    int comparaciones, intercambios;
    FILE * salida;
    clrscr();
    randomize();
    PrepararEstadistica(salida);
	datos.tope = 1;
    for (int t=0; t < 3; t++) {
        datos.tope = datos.tope * 10;
        for (int v=0; v < 1000; v++) {
            LlenarAlAzar(datos);
            crearCopia(datosaux, datos);
            MaximosSucesivos(datosaux, comparaciones, intercambios);
            GuardarEstadistica(salida, "Maximos Sucesivos", datos.tope, comparaciones, intercambios);
            crearCopia(datosaux, datos);
            Burbuja(datosaux, comparaciones, intercambios);
            GuardarEstadistica(salida, "Burbuja", datos.tope, comparaciones, intercambios);
            crearCopia(datosaux, datos);
            BurbujaMejorado(datosaux, comparaciones, intercambios);
            GuardarEstadistica(salida, "Burbuja Mejorado", datos.tope, comparaciones, intercambios);
            ShellSort(datos, comparaciones, intercambios);
            GuardarEstadistica(salida, "Shell Sort", datos.tope, comparaciones, intercambios);
            gotoxy(1,1);cout << "Generada estadistica para " << datos.tope << " elementos (vuelta " << v + 1 << ")   ";
        }
    }
    CerrarEstadística(salida);
    esperar(1,3);
}