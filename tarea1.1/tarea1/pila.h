#pragma once
#include <iostream>
#include "nodoS.h"
#include <stdlib.h>
#include <string>
using namespace std;

class pila
{
private:
	nodoS* cima;
	int largo;

public:
	pila();
	void push(int pinfo); // Agregar un elemento a la pila
	int pop(); // Eliminar un elemento
	void show(); // ver la pila
	bool empty();
	void setLargo(int plargo);
	void setCima(nodoS* pCima);
	string imprimir();
	nodoS* getCima();
	int getLargo();

};
