typedef char str40[41];
typedef char str50 [51]; 

struct ty_fecnac {
	int ano;
	int mes;
	int dia;
};

struct ty_reg {
	str50 Apellido;
	str50 Nombre;
	ty_fecnac FechaNac;
};

struct ty_nodo  {
		ty_reg reg;
		ty_nodo * sig;

};

void cargarEnLista (ty_nodo * &pLista, ty_reg rReg);
void crearLista (ty_nodo * &pLista);
void limpiarLista (ty_nodo * &pLista);
void listarDatos (ty_nodo * pLista);
void crearCopia (ty_nodo * pLista, str50 sRutaDestBack);
void obtenerNodo (ty_nodo * &nodo, ty_reg dato);
bool ArchExiste(const char * rutaynombre);
void AbrirArch(FILE * &archivo, const char * rutaynombre, const char * modo);
void CerrarArch (FILE * Archivo);
bool Sobreescribir();
void mostrar (str40 rutaynombre);
void LeerRegPersona (ty_reg &reg, FILE * &archivo);
void GrabarRegPersona (ty_reg reg, FILE * &Archivo);