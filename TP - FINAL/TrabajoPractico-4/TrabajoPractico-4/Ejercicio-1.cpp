/* Ejercicio 1
En una nueva solución (TrabajoPractico-4) agregar el proyecto Ejercicio-1. 
Escribir la función EsPalindromo() que devolverá un valor lógico que indique si 
una palabra o frase pasada como parámetro puede leerse por igual al derecho y al revés 
(por ejemplo, “salas”). Para ello deberá utilizar una pila y resolverse en forma iterativa. 
La rutina debe ignorar la diferencia entre mayúsculas y minúsculas y los acentos en las vocales 
(como en el caso de “Neuquén”, que se puede leer con el mismo resultado de derecha a izquierda 
y de izquierda a derecha, pero siempre y cuando ignoremos la “é” cambiándola por “e” y pasando
a minúscula la “N” inicial). Probar también con un texto que no cumpla esta condición 
(por ejemplo “Esto no es palíndromo”). La mayoría de las rutinas ya están escritas dentro de 
la librería de rutinas pilaletra, en la que deben implementarse las rutinas apilar() y desapilar().
*/

#include<iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pilaLetra.h"

using namespace std;


typedef char str70[71];

bool EsPalindromo(str70 palabra);
void NormalizarLetras(str70 &palabra);


void main (){

	// DECLARACION DE VARIABLES
	str70 sFrase;
	
	//Ingreso de la Palabra o Frase
		//Frases de Prueba:
			//strcpy (sFrase, "nada, yo soy adán");
			//strcpy (sFrase, "dábale arroz a la zorra el abad");
	printf("Ingrese una Palabra o Frase:\n"); 
	gets(sFrase);

	// En este modulo se verifica si la palaabra o 
	// frase ingresada es palindroma
	EsPalindromo (sFrase);

	if (EsPalindromo(sFrase)){
		cout << "\nES UN PAL\241NDROMO\n";
		getchar();
	}else{
		cout << "\nNO ES UN PAL\241NDROMA\n";
		getchar();
	}

}


bool EsPalindromo(str70 sFrase){

	//Declaracion de Variables Internas al Modulo
	str70 palabraInvertida = "";
	str70 sFraseNorm = "";
	int cant;
	t_pila * pila;

	crearPila (pila);

	strcpy (sFraseNorm, sFrase);

	// En este modulo, convierto las letras a mayuscula, 
	// borro los espacios entre las palabras y
	// modifico las letras con acento y ñ
	NormalizarLetras(sFraseNorm);

	//Cuento la cantidad de caracteres de la Palabra o Frase ingresada
	cant = strlen(sFraseNorm);

	for (int i = 0; i < cant; i++){ //Apila las letras ingresadas en una Pila
		apilar (pila, sFraseNorm[i]);
	}

	for (int i = 0; i<= cant; i++){ //Pasa las letras ingresadas de una Pila a una Pila Auxiliar
		desapilar (pila, palabraInvertida[i]);
	}

	return (strcmp (sFraseNorm, palabraInvertida)==0);

}

void NormalizarLetras(str70 &palabra){

	//Declaracion de Variables Internas al Modulo
	int cant;
	str70 palabraux = "";
	int j = 0;

	//Cuento la cantidad de caracteres que tiene la palabra o frase ingresada
	cant = strlen (palabra);
	
	for(int i=0; i< cant; i++){
		//Si la frase tiene caracteres especiales, modifico las letras
		switch (palabra[i]){
			case 'á': 
				palabra [i] = 'A'; 
				break;
			case 'é': 
				palabra [i] = 'E'; 
				break;
			case 'í': 
				palabra [i] = 'I'; 
				break;
			case 'ó': 
				palabra [i] = 'O'; 
				break;
			case 'ú': 
				palabra [i] = 'U'; 
				break;
			case 'ü': 
				palabra [i] = 'U'; 
				break;
			case 'ñ': 
				palabra [i] = 'N'; 
				break;
			default : 
				palabra[i] = (char) toupper(palabra[i]);
				break;
		}

		//Si la frase tiene espacios, comas o puntos, los elimino
		if (palabra [i] != ' ' && palabra [i] != ',' && palabra [i] != '.'){
			palabraux [j] = palabra [i];
			palabraux[j] = (char) toupper(palabraux[j]);
			j++;
		}
	}

	strcpy (palabra, palabraux);

}