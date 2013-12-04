#define MAXELEMENTOS 1000
typedef int t_vecint[MAXELEMENTOS];

struct t_data {
    int tope; // define el tamaño lógico del arreglo
    t_vecint valores;
};

void MaximosSucesivos(t_data &datos, int &comparaciones, int &intercambios);
void Burbuja(t_data &datos, int &comparaciones, int &intercambios);
void BurbujaMejorado(t_data &datos, int &comparaciones, int &intercambios);
void ShellSort(t_data &datos, int &comparaciones, int &intercambios);

void trasponer(int &A, int &B);
void crearCopia(t_data &destino, const t_data origen);