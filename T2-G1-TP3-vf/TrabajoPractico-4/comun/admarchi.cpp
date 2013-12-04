#include <iostream>
#include <string.h>
#include "admarchi.h"
#include "comun.h"
using namespace std;



bool ArchExiste(const char * rutaynombre){
/*Su objetivo es determinar la existencia de un archivo. Recibirá como parámetro el nombre del archivo (incluyendo, si es necesario, la ruta hasta el mismo). 
Devolverá verdadero cuando el archivo existe, y falso cuando no exista. Para esto, observar el resultado de la función fopen() en modo “rb”, tratando de 
abrir un archivo existente y uno no existente.
*/
FILE * Arch;
Arch = fopen(rutaynombre, "rb");//Abro el archivo
if (Arch == NULL){
	 return false;
}
else{
	fclose(Arch);//Cierro el archivo
	return true;
}

}

void AbrirArch(FILE * &archivo, const char * rutaynombre, const char * modo){
/*
Recibirá como parámetros una variable de tipo FILE * (devolverá el archivo o NULL si el mismo no existe o si no se pudo crear, según corresponda), el nombre 
del archivo (incluyendo la ruta hasta el mismo, de ser necesario) y el modo de apertura (lectura o escritura, binario o texto, etc.).
Debe utilizar la función ArchExiste() (cuando sea necesario).
*/
	if (strcmp(modo,"wt") == 0 || strcmp(modo,"wb") == 0){
		if (ArchExiste(rutaynombre)){
			cout << "ATENCION! El archivo " << rutaynombre << " ya existe!" << endl << "Desea sobreescribirlo? S/N:";
			if (NoContinuar()){
				archivo = NULL;
				fflush (stdin);
				cout << endl << endl << "No se actualizo el archivo " << rutaynombre << endl;
				getchar();
			}else{
				archivo = fopen (rutaynombre, modo);
			}
		}else{
			archivo = fopen (rutaynombre, modo);
		}
	}else{
		archivo = fopen (rutaynombre, modo);
		if (archivo == NULL){
			cout << "No se encontro el archivo " << rutaynombre << endl;
		    getchar();
		}
	}
	clrscr();
}

bool NoContinuar (){
	char SN;
	bool a = false;
	SN = opcionSN();
	if (SN == 'N' || SN == 'n'){
		a=  true;
	}
	return a;
}