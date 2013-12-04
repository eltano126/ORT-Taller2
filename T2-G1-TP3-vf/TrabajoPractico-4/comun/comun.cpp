#include <windows.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include "comun.h"

using namespace std;

int random(int tope) {
	return rand() % tope;
}
void randomize() {
    srand ( time(NULL) );
}
void clrscr() {
	system("cls");
}
void gotoxy(int x, int y){
	COORD coord={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int wherex() {
	return getWhere('x');
}
int wherey() {
	return getWhere('y');
}
int getWhere(char axis) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi)) return -1;
	return (axis=='x') ? csbi.dwCursorPosition.X : csbi.dwCursorPosition.Y;
}
int maxx() {
	return getSize('x');
}
int maxy() {
	return getSize('y');
}
int getSize(char axis) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi)) return -1;
    return ((axis=='x') ? csbi.srWindow.Right : csbi.srWindow.Bottom) + 1;
}
void esperar() {
  cout << "Pulse una tecla para continuar...";
  int x = _getch();
  if (x == 0 || x == -32) _getch();

}
void esperar(int x, int y) {
  gotoxy(x,y);
  esperar();
}
int menu(char * titulo, char * opciones, char separador){
    if (!titulo) return -1;
    if (!opciones) return -1;
    clrscr();
    cout << titulo << "\n\n";
    int nUltima = 1;
    cout << nUltima << " - ";
    for (int n = 0; n < strlen(opciones); n++) {
        if (opciones[n] == separador) {
            nUltima ++;
            cout << '\n' << nUltima << " - ";
        } else {
            cout << opciones[n];
        }
    }
    cout << "\n\n";
    int nOpcion = 0;
    while ((nOpcion < 1) || (nOpcion > nUltima)) {
        cout << "Elija una opcion: ";
        cin >> nOpcion;
    }
    return nOpcion;
}
char opcionSN() {
    char tecla = _getch();
    while (tecla != 'S' && tecla != 's' && tecla != 'N' && tecla != 'n') {
        tecla = _getch();
    }
    return tecla;
}
bool confirmar() {
    char tecla = opcionSN();
    return (tecla == 'S' || tecla == 's');
}
void mostrarCentrado(int linea, char * texto) {
  if (linea==-1) linea = wherey() + 1;
  int col = (maxx() - strlen(texto)) / 2;
  if (col < 0) { col = 0; }
  gotoxy(col, linea);
  cout << texto;
}
long int FecANum(int AAAA, int MM, int DD) {
    return AAAA * 10000 + MM * 100 + DD;
}