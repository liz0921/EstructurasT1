#include "gestor.h"

gestor::gestor()
{
	this->lista = NULL; 
	this->cola1 = NULL; 
	this->pila1 = NULL;

}

gestor::~gestor()
{
}

listaSimple* gestor::getLista()
{
	return this->lista;
}

void gestor::setLista(listaSimple* plista)
{
	plista = new listaSimple();
	this->lista = plista;
}

void gestor::setCola(cola* pcola)
{
	pcola = new cola();
	this->cola1 = pcola;
}

void gestor::setPila(pila* ppila)
{
	ppila = new pila();
	this->pila1 = ppila;
}

void gestor::agregarLista(int pnumero)
{
	this->lista->agregarOrdenado(pnumero);
}

void gestor::agregarCola(int pnumero)
{
	this->cola1->poner(pnumero);
}

void gestor::agregarPila(int pnumero)
{
	this->pila1->push(pnumero);
}

void gestor::imprimirLista()
{
	lista->imprimir();
}

void gestor::imprimirCola()
{
	return this->cola1->showCola();

}

void gestor::imprimirPila()
{
	return this->pila1->show();
}

void gestor::pasarListaCola() {
	if (this->lista->esVacia()) {
		cout << "La lista esta vacia" <<endl;
	}
	else{
		int num = this->lista->dirUltimo()->getDato();
		this->lista->eliminar(num);
		this->cola1->poner(num);
	
	}
	
}
//TODO: lista cuanto tiene un elemento no se vacia.
void gestor::pasarListaPila()
{
	if (this->lista->esVacia()) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		int num = this->lista->dirUltimo()->getDato();
		this->lista->eliminar(num);
		this->pila1->push(num);

	}

}

void gestor::pasarPilaLista()
{
	if (this->pila1->getLargo()==0) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		int num = this->pila1->getCima()->getDato();
		this->pila1->pop();
		this->lista->agregarOrdenado(num);

	}

}
