#include "cola.h"
#include <iostream>
using namespace std;

cola::cola()
{
	this->tam = 0;
	this->pFrente = NULL;
	this->pFinal = NULL;
}


int cola::getTam()
{
	return this->tam;
}

nodoS* cola::getpFrente()
{
	return this->pFrente;
}

nodoS* cola::getpFinal()
{
	return this->pFinal;
}

void cola::setTam(int tam_)
{
	this->tam = tam_;
}

void cola::setPFrente(nodoS* pfrente)
{
	this->pFrente = pfrente;
}

void cola::setPFinal(nodoS* pFinal)
{
	this->pFinal = pFinal;
}

bool cola::esVacia()
{
	bool esVacia = false;
	if (getTam() == 0) {
		esVacia = true;
	}

	return esVacia;
}


int cola::largo()
{
	return tam;
}

void cola::poner(int dato)
{
	nodoS* n = new nodoS(dato);
	n->setDato(dato);
	if (esVacia()) {

		pFrente = n;
	}

	else
		pFinal->setSgte(n);

	pFinal = n;
	setTam(getTam() + 1);
}

int cola::quitar() {
	int dato = 0;
	if (!esVacia()) {
		dato = getpFrente()->getDato();
		nodoS* aux = getpFrente();
		setPFrente(aux->getSgte());
		if (getpFrente() == NULL)
			setPFinal(NULL);
		delete aux;
		setTam(getTam() - 1);
	}
	return dato;
}


void cola::showCola()
{
	cout  << "Los elementos de la cola son:";
	nodoS* aux = pFrente;
	for (int i = 0; i < tam; i++) {
		cout << aux->getDato() <<",";
		aux = aux->getSgte();
	}
}


string cola::imprimir() {
	string resultado;
	if (!this->pFrente)
		resultado = " Cola vacia";
	else {
		nodoS* aux = this->pFrente;
		while (aux) {
			resultado += "\n" + to_string(aux->getDato());
			aux = aux->getSgte();
		}
	}
	return resultado;
}



