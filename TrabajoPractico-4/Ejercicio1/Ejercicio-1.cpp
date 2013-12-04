#include<iostream>
#include <string>
#include "pilaLetra.h"


using namespace std;

typedef char str30[31];

void EsPalindromo (str30 &cPalabra, str30 &cPalabraInv);

void main (){

	int i;
	str30 cPalabra;
	str30 cPalabraInv = "";

	t_pila * pila;
	
	cout << "Ingrese una palabra" << endl; 
	cin >> cPalabra;

	for(i = 0; cPalabra[i]; i++) {
		cPalabra[i] = toupper(cPalabra[i]); 
	}
	
	//cout << "Palabra: " << cPalabra << endl; 
	//getchar();

	EsPalindromo(cPalabra,cPalabraInv);
	
}

void EsPalindromo (str30 &cPalabra, str30 &cPalabraInv){

	int cant;
	cant = strlen(cPalabra);

	cout << "La cantidad de letras de la palabra es: " << cant << endl;
	
	t_pila * pila;

	crearPila (pila);
	
	for (int i = 0; i < cant; i++){
		apilar (pila, cPalabra[i]);
	}

	//cout << "Termino de APILAR" << endl;

	for (int i = 0; i<= cant; i++){
		desapilar (pila, cPalabraInv[i]);
	}
	
	//cout << "Termino de DESAPILAR" << endl;

	if(strcmp(cPalabra, cPalabraInv)==0){
		cout << "ES PALINDROMO" << endl;
	}else{
		cout << "NO ES PALINDROMO" << endl;
	}

	getchar();
	
}

void LimpiarPalabra(str30 &cPalabra){


}