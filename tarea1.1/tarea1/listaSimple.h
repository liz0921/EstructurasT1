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
	//TODO HACER EL AGREGAR ORDENADO.
	listaSimple();
	~listaSimple();
	nodoS* getCab();
	int getLargo();
	void setCab(nodoS*);
	void setLargo(int);
	void desplegar();
	//string imprimir();
	void agregarOrdenado(int);
	void imprimir();
	void agregarInicio(int x);
	bool agregarAntesDe(int nuevo, int referencia);
	bool agregarDespuesDe(int x, int ref);
	bool agregarDatoPos(int x, int n);
	void agregarFinal(int x);

	bool esVacia();
	nodoS* dirNodo(int x);
	nodoS* dirAnterior(int x);
	nodoS* dirUltimo();
	bool eliminar(int x);
	void eliminarL();
	nodoS* dirNodoIndice(int n);
	int valorIndice(int n);
	bool eliminarPos(int n);

	

};

