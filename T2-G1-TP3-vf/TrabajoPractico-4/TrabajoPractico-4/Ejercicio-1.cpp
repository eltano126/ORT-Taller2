/* Ejercicio 1
En una nueva soluci�n (TrabajoPractico-4) agregar el proyecto Ejercicio-1. 
Escribir la funci�n EsPalindromo() que devolver� un valor l�gico que indique si 
una palabra o frase pasada como par�metro puede leerse por igual al derecho y al rev�s 
(por ejemplo, �salas�). Para ello deber� utilizar una pila y resolverse en forma iterativa. 
La rutina debe ignorar la diferencia entre may�sculas y min�sculas y los acentos en las vocales 
(como en el caso de �Neuqu�n�, que se puede leer con el mismo resultado de derecha a izquierda 
y de izquierda a derecha, pero siempre y cuando ignoremos la �� cambi�ndola por �e� y pasando
a min�scula la �N� inicial). Probar tambi�n con un texto que no cumpla esta condici�n 
(por ejemplo �Esto no es pal�ndromo�). La mayor�a de las rutinas ya est�n escritas dentro de 
la librer�a de rutinas pilaletra, en la que deben implementarse las rutinas apilar() y desapilar().
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
			//strcpy (sFrase, "nada, yo soy ad�n");
			//strcpy (sFrase, "d�bale arroz a la zorra el abad");
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
	// modifico las letras con acento y �
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
			case '�': 
				palabra [i] = 'A'; 
				break;
			case '�': 
				palabra [i] = 'E'; 
				break;
			case '�': 
				palabra [i] = 'I'; 
				break;
			case '�': 
				palabra [i] = 'O'; 
				break;
			case '�': 
				palabra [i] = 'U'; 
				break;
			case '�': 
				palabra [i] = 'U'; 
				break;
			case '�': 
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