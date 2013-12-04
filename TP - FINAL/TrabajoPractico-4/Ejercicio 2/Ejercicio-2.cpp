/*Ejercicio 2
Crear el proyecto Ejercicio-2.
1) En un archivo de cabecera (.H) agregar las estructuras necesarias y
suficientes que puedan soportar una lista dinámica de datos con elementos
que contengan la siguiente información (la parte de datos es la misma que se
utilizó en el último ejercicio del práctico anterior):
1. Apellido.
2. Nombre.
3. FechaNac (fecha de nacimiento, es una estructura que contiene tres
números enteros: año, mes, día).

2) A partir de lo generado en el punto anterior, escribir un programa que lea los
datos de la agenda (el archivo agenda.dat se generó en el último ejercicio
del Trabajo Práctico 3) y los cargue en una lista, la que estará ordenada
alfabéticamente por apellido y luego por nombre.

3) El programa deberá listar los datos de la agenda por pantalla.

4) Antes de salir, hacer una copia del archivo (backup) y guardarlo nuevamente,
ordenado tal cual quedan los elementos en la lista.
*/

#include <iostream>
#include <string.h>
#include <conio.h>
#include "Libreria.h"
using namespace std; 

void main (){

	FILE * fAgenda;
	ty_reg rReg;
	ty_nodo * pLista;
	str50 sRutaDest;
	str50 sRutaDestBack;


	crearLista (pLista);
	limpiarLista (pLista);

	cout<<"Escriba la ubicacion y el nombre del archivo de Agenda\n";
	cin>> sRutaDest;
	getchar();
	system("cls");
	//No es necesario verificar si existe el archivo, ya que fue generado en el TP anterior.

	//Copio la direccion de la agenda para crear la del archivo de Backup
	strcpy(sRutaDestBack,sRutaDest);
	strcat(sRutaDestBack,"_backup.dat");

	//Concateno la extension dada al nombre y ruta.
	strcat( sRutaDest, ".dat");


	AbrirArch (fAgenda, sRutaDest, "rb");

	if (fAgenda != NULL){
		LeerRegPersona (rReg, fAgenda);

		while (!feof(fAgenda)){
			cargarEnLista (pLista, rReg);
			LeerRegPersona (rReg, fAgenda);
		}
	}

	listarDatos (pLista);
	crearCopia (pLista, sRutaDestBack);
	getchar ();

}


void obtenerNodo (ty_nodo * &nodo, ty_reg dato){
	nodo = new ty_nodo;
	nodo-> reg = dato;	
	nodo->sig = NULL;
}

void cargarEnLista (ty_nodo * &pLista, ty_reg rReg){

	ty_nodo * nodo;
	obtenerNodo (nodo, rReg);

	if (pLista == NULL){
		pLista = nodo;
	}else{ 
		if (rReg.Apellido[0] < pLista->reg.Apellido[0]){
			nodo ->sig = pLista ;
			pLista = nodo;
		}else{
			ty_nodo * pAux;
			pAux = pLista;

			while ((pAux->sig != NULL) && (rReg.Apellido[0] > pAux->sig->reg.Apellido[0])){
				pAux = pAux ->sig;
			}

			if (pAux != NULL){
				nodo ->sig = pAux ->sig;
				pAux ->sig = nodo;			
			}
		}
	}
}

void crearLista (ty_nodo * &pLista){
	pLista = new ty_nodo;
	pLista = NULL;
}

void limpiarLista (ty_nodo * &pLista){

	ty_nodo * pElim;

	while (pLista != NULL){
		pElim = pLista;

		if (pElim ->sig !=NULL){
			pLista = pElim ->sig;
		}

		delete pElim;
	}

	pLista = NULL;
}

void listarDatos (ty_nodo * pLista){

	while (pLista != NULL){
		cout << "Apellido: " << pLista ->reg.Apellido << endl;
		cout << "Nombre: " << pLista ->reg.Nombre << endl;
		cout << "Fecha de nacimiento: " << pLista ->reg.FechaNac.dia << "/" << pLista ->reg.FechaNac.mes << "/" << pLista ->reg.FechaNac.ano << endl;
		cout << " " << endl;
		pLista = pLista ->sig;
	}
}

void crearCopia (ty_nodo * pLista, str50 sRutaDestBack){

	FILE * copia;
	AbrirArch (copia, sRutaDestBack, "wb");

	if (copia != NULL){
		while (pLista != NULL){
			GrabarRegPersona (pLista -> reg, copia);
			pLista = pLista ->sig;
		}

		cout << "Se cre\242 una copia del archivo en: " << sRutaDestBack << endl;
		CerrarArch (copia);
	}
}

bool ArchExiste(const char * rutaynombre){

	FILE * Archivo;
	bool bPude = false;
	Archivo = fopen (rutaynombre, "rb");

	if (Archivo == NULL){
		return false;
	}else{
		return true;
	}

	fclose (Archivo);
}

void AbrirArch(FILE * &archivo, const char * rutaynombre, const char * modo){

	archivo = NULL;
	char Resp;

	if (ArchExiste (rutaynombre)){ // VERIFICACION DE EXISTENCIA DEL ARCHIVO
		if (modo[0] == 'w'){ // SI ES MODO ESCRITURA

			if(Sobreescribir()){// PREGUNTA SI LO SOBREESCRIBE
				archivo = fopen (rutaynombre, modo); // CASO "SI SOBREESCRIBIR"
			}else{
				cout << "< < < CREACION CANCELADA > > >" << endl; // CASO "NO SOBREESCRIBIR"
			}

		}else{ //ELSE SI ES MODO ESCRITURA
			archivo = fopen (rutaynombre, modo);
		}
		//FIN SI ELSE MODO ESCRITURA
	}else{ // ELSE ARCHIVO EXISTE
		if (modo[0] == 'w'){ // if modo escritura
			archivo = fopen (rutaynombre,modo);
		 // FIN IF MODO ESCRITURA
		}else{ // ELSE IF MODO ESCRITURA
			cout << "< < < ARCHIVO INEXISTENTE > > >" << endl;
			getchar ();
		}//  FIN ELSE IF MODO ESCRITURA
	}
}	

void CerrarArch (FILE * Archivo){
	fclose (Archivo);
}

bool Sobreescribir(){
	char cResp;

	do{
		cout << "< < < ARCHIVO EXISTENTE > > >" << endl << "Desea sobreescribirlo? Ingrese S o N" << endl;
		cin >> cResp;
		cResp = toupper(cResp);
		getchar();
		cout << endl;
	} while ((cResp != 'S') && (cResp != 'N'));

	if(cResp == 'S'){
		return true;
	}else{
		return false;
	}

}

void mostrar (str40 rutaynombre){

	FILE * archivo;
	ty_reg reg;
	AbrirArch (archivo, rutaynombre, "rb");
	LeerRegPersona (reg, archivo);

	system ("cls");
	printf ("\nARCHIVO\n------\n");

	while (!feof(archivo)){
		printf ("\nNombre: %s\nApellido: %s\nFecha de nacimiento: %d/%d/%d\n", reg.Nombre, reg.Apellido, reg.FechaNac.dia, reg.FechaNac.mes, reg.FechaNac.ano); 
		LeerRegPersona (reg, archivo);
	}

	CerrarArch (archivo);
}

void LeerRegPersona (ty_reg &reg, FILE * &archivo){
	fread (&reg, sizeof (reg), 1, archivo);
}

void GrabarRegPersona (ty_reg reg, FILE * &archivo){
	fwrite (&reg, sizeof (reg), 1, archivo);
}