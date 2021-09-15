#pragma once
#include "listaSimple.h"
#include "cola.h"
#include "pila.h"
#include "nodoS.h"
#include <iostream>
class gestor
{
private:
	listaSimple* lista;
		cola* cola1; 
		pila* pila1; 

public: 
	gestor();
	~gestor();

	listaSimple* getLista(); 
	void setLista(listaSimple*);


	void setCola(cola*);
	void setPila(pila*);

	void agregarLista(int);
	void agregarCola(int);
	void agregarPila(int);


	void imprimirLista();
	void imprimirCola();
	void imprimirPila();


	void pasarListaCola();
	void pasarListaPila();
	void pasarPilaLista();
	void pasarPilaCola();
	void pasarColaLista();
	void pasarColaPila();




};

