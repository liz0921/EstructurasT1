#include "Pila.h"

pila::pila()
{
	largo = 0;
	cima = NULL;
}

void pila::push(int pinfo)
{
	nodoS* nuevoNodo = new nodoS(pinfo);
	nuevoNodo->setDato(pinfo);
	nuevoNodo->setSgte(cima);
	setCima(nuevoNodo);
	setLargo(largo + 1);
}

int pila::pop()
{
	if (empty()) {
		return NULL;
	}
	else {
		nodoS* aux = getCima();
		int info = aux->getDato();
		setCima(aux->getSgte());

		delete aux;
		setLargo(getLargo() - 1);

		return info;
	}
}
bool pila::empty() {
	return getCima() == NULL;
}

void pila::show()
{
	if (getCima() == NULL) {
		cout << "pila vacia" << endl;
	}
	else {
		nodoS* aux = cima;
		cout <<  "Los elementos de la pila son:"<<endl;
		while (aux != NULL) {
			cout << aux->getDato() << ",";
			aux = aux->getSgte();
		}

	}
}



void pila::setLargo(int plargo)
{
	this->largo = plargo;
}

int pila::getLargo()
{
	return this->largo;
}

nodoS* pila::getCima()
{
	return this->cima;
}

void pila::setCima(nodoS* pCima)
{
	this->cima = pCima;

}
