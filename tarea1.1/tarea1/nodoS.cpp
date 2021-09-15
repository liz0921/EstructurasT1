#include "nodoS.h"


nodoS::nodoS()
{
	this->dato = 0;
	this->sgte = NULL;
}


nodoS::nodoS(int dato)
{
	this->dato = dato;
	this->sgte = NULL;

}
nodoS::nodoS(int numero, nodoS* siguiente)
{
	this->dato = numero;
	this->sgte = siguiente;
}

nodoS::~nodoS()
{
}

int nodoS::getDato()
{
	return this->dato;
}

nodoS* nodoS::getSgte()
{
	return this->sgte;
}

void nodoS::setDato(int dato)
{
	this->dato = dato;
}

void nodoS::setSgte(nodoS* ptr)
{
	this->sgte = ptr;
}
