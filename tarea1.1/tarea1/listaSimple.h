#pragma once
#include "nodoS.h"
#include <stdlib.h>
#include <iostream>
#include <string>


using namespace std;


class listaSimple
{
private:
	nodoS* cab; //cabeza de lista
	int largo;  //cantidad de elementos (nodos) que tiene la lista 

public:
	listaSimple();
	~listaSimple();
	nodoS* getCab();
	int getLargo();
	void setCab(nodoS*);
	void setLargo(int);
	void desplegar();
	
	void agregarOrdenado(int);
	void imprimir();
	void agregarInicio(int x);

	bool esVacia();
	nodoS* dirNodo(int x);
	nodoS* dirAnterior(int x);
	nodoS* dirUltimo();
	bool eliminar(int x);


	

};

