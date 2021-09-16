#include "listaSimple.h"

listaSimple::listaSimple()
{
	this->cab = NULL;
	this->largo = 0;
}

listaSimple::~listaSimple()
{

}

nodoS* listaSimple::getCab()
{
	return this->cab;
}

int listaSimple::getLargo()
{
	return this->largo;
}

void listaSimple::setCab(nodoS* ptr)
{
	this->cab = ptr;
}

void listaSimple::setLargo(int largo)
{
	this->largo = largo;
}

void listaSimple::desplegar()
{
	cout << "\nLa lista es:" << endl;
	nodoS* aux = getCab();
	while (aux != NULL) {
		cout << aux->getDato() << ",";
		aux = aux->getSgte();
	}
}



void listaSimple::agregarOrdenado(int numero)
{

	if (!this->cab)
		this->agregarInicio(numero);
	else {

		nodoS* nuevo = new nodoS(numero, nullptr);

		if (numero > this->cab->getDato()) {
			nuevo->setSgte(this->cab);
			this->cab = nuevo;
			this->largo++;
		}
		else {

			nodoS* aux = this->cab;

			while (aux->getSgte() && nuevo->getDato() < aux->getSgte()->getDato()) {
				aux = aux->getSgte();
			}

			nuevo->setSgte(aux->getSgte());
			aux->setSgte(nuevo);

			this->largo++;
		}
	}
}

void listaSimple::imprimir()
{
	if (this->cab) {
		nodoS* aux = this->cab;
		cout << "La lista es:" << endl;
		while (aux) {
			cout << aux->getDato()<<",";// imprime una cadena de texto
			aux = aux->getSgte();
		}
	}
	else
		cout << "\n lista vacia";
}
void listaSimple::agregarInicio(int x)
{
	nodoS* nuevo = new nodoS(x);  //Paso 1, crear el nodo
	nuevo->setSgte(getCab());     //Paso 2, enlazar el nuevo nodo a la lista
	setCab(nuevo);                //Paso 3, reacomodar la lista con el nuevo nodo  
	largo++;
}



//# esVacia():: Determina si la estructura esta vacia
bool listaSimple::esVacia() {
	bool esVacia = false;
	if (getLargo() == 0) {
		esVacia = true;
	}

	return esVacia;
}

//# dirNodo(int x):: Retorna la direccion del nodo cuyo dato sea x. Sino lo encuentra devuelve NULL
nodoS* listaSimple::dirNodo(int x) {
	nodoS* ant = cab;
	while (ant->getSgte() != NULL)
	{
		if (ant->getDato() == x) {
			return ant;
		}
		else {
			ant = ant->getSgte();
		}
	}
	return NULL;
}

//# dirAnterior(int x):: Retorna la direccion del nodo anterior al nodo cuyo dato sea x. Si no lo encuentra devuelve NULL
nodoS* listaSimple::dirAnterior(int x)
{
	nodoS* actual, * anterior;
	bool encontrado = false;
	actual = cab;
	anterior = NULL;
	// búsqueda del nodo y del anterior
	while ((actual != NULL) && !encontrado)
	{
		encontrado = (actual->getDato() == x);
		if (!encontrado)
		{
			anterior = actual;
			actual = actual->getSgte();
			
		}
		return actual;
	}

	
	cout << "Valor de anterior: " << anterior->getDato() << endl;
	cout << "Valor de actual: " << actual->getDato() << endl;
	return NULL;
}

//# dirUltimo(int x):: Retorna la direccion del ultimo nodo de la lista. Si la lista esta vacia devuelve NULL
nodoS* listaSimple::dirUltimo()
{
	nodoS* indice;
	indice = cab;
	for (int i = 1; (i < getLargo()) && (indice != NULL); i++) {
		indice = indice->getSgte();
	}
	return indice;
}




bool listaSimple::eliminar(int codigo)
{
	bool modificado = false;
	bool encontrado = false;
	nodoS* aux = NULL;
	nodoS* actual = cab;
	nodoS* ant = NULL;
	if (getLargo() > 0) {
		while (actual != NULL && !encontrado)
		{
			encontrado = (actual->getDato() == codigo);
			if (!encontrado)
			{
				ant = actual;
				actual = actual->getSgte();
			}
		}
		if (actual->getDato() != NULL) {
			nodoS* aux = NULL;
			if (ant != NULL) {
				aux = ant->getSgte();
				ant->setSgte(aux->getSgte());
				delete aux;
				largo--;
				modificado = true;
			}
		}
	}
	return modificado;
}












