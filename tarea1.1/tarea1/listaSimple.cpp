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

/*
string listaSimple::imprimir()
{
	string resultado = "";
	if (this->cab) {
		nodoS* aux = this->cab;
		while (aux) {
			resultado += "\n" + to_string(aux->getDato());// imprime una cadena de texto
			aux = aux->getSgte();
		}
	}
	else
		resultado = "\n lista vacia";
	return resultado;
}
*/

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

bool listaSimple::agregarAntesDe(int x, int referencia)
{
	bool agregado = false;
	if (getLargo() != 0) {
		if (getCab()->getDato() == referencia) {
			agregarInicio(x);
			agregado = true;
		}
		else {
			nodoS* ant = cab;
			while (ant->getSgte() != NULL && !agregado) {
				if (ant->getSgte()->getDato() == referencia) {
					nodoS* nuevo = new nodoS(x);
					nuevo->setSgte(ant->getSgte());
					ant->setSgte(nuevo);
					largo++;
					agregado = true;
				}
				else {
					ant = ant->getSgte();
				}
			}
		}
	}

	return agregado;
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

bool listaSimple::agregarDespuesDe(int x, int ref)
{
	nodoS* aux = cab;
	while (aux != NULL) {
		if (aux->getDato() == ref) {
			nodoS* nuevo = new nodoS(x);
			if (aux->getSgte() == NULL) {
				aux->setSgte(nuevo);
				return true;
			}
			else {
				nuevo->setSgte(aux->getSgte());
				aux->setSgte(nuevo);
				return true;
			}
		}aux = aux->getSgte();
	}
	return false;
}

void listaSimple::agregarFinal(int x)
{
	bool esvacia = esVacia();
	if (esvacia) {
		agregarInicio(x);
	}
	else {
		nodoS* nuevo = new nodoS(x);
		nodoS* aux = cab;
		while (aux->getSgte() != NULL) {
			aux = aux->getSgte();
		}
		aux->setSgte(nuevo);
		largo++;
	}
}
/*bool listaSimple::eliminar(int x)
{
	bool removido = true;
	nodoS* aux = NULL;
	if (!esVacia()) {
		if (getCab()->getDato() == x) {
			aux = getCab();
			setCab(aux->getSgte());  //Paso 2, Cabeza es ahora el segundo
			delete aux;
			largo--;
			removido = true;
		}
		else {
			nodoS* ant = dirAnterior(x);
			if (ant != NULL) {
				aux = ant->getSgte();        
				ant->setSgte(aux->getSgte());
				delete aux;
				largo--;
				removido = true;
			}
		}
	}
	return removido;
}
*/


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

//Devuleve la direccion del nodo en la posicion n, si no lo encuentra devuelve NULL

nodoS* listaSimple::dirNodoIndice(int n) {
	nodoS* aux = NULL;
	if (n < getLargo()) {
		aux = getCab();
		for (int i = 0; i <= n; i++) {
			aux = aux->getSgte();
		}
	}
	return aux;
}

//Devuelve el valor que se encuentra en la posicion n, sino devuelve 0

int listaSimple::valorIndice(int n) {
	nodoS* aux = NULL;
	aux = dirNodoIndice(n);
	if (aux != NULL)
		return aux->getDato();
	else
		return NULL;
}

//Agrega un dato en la posicion n, devuelve verdadero si lo agrega

bool listaSimple::agregarDatoPos(int x, int n) {
	bool agregado = false;
	if (n < getLargo()) {
		nodoS* nuevo = new nodoS(x);
		if (n == 0) {
			setCab(nuevo);
		}
		else {
			nodoS* aux = dirNodoIndice(n - 1);
			nuevo->setSgte(aux->getSgte());
			aux->setSgte(nuevo);
		}
		setLargo(getLargo() + 1);
		agregado = true;
	}
	return agregado;
}


//Elimina el indice en la posicion n, devuelve verdadero si lo elimina

bool listaSimple::eliminarPos(int n) {
	bool eliminado = false;
	if (n < getLargo()) {
		nodoS* aux;
		if (n == 0) {
			aux = getCab();
			setCab(getCab()->getSgte());
		}
		else {
			nodoS* ant = dirNodoIndice(n - 1);
			aux = ant->getSgte();
			ant->setSgte(aux->getSgte());
		}
		delete aux;
		largo--;
		eliminado = true;
	}
	return eliminado;
}



void listaSimple::eliminarL() {
	if (!this->cab)
	cout << "La lista esta vacia" << endl;
	else {

		if (!this->cab->getSgte()) {
			delete this->cab;
			this->cab = nullptr;
		}
		else {
			nodoS* ant = this->cab;
			nodoS* aux = this->cab;

			while (aux->getSgte()) {
				ant = aux;
				aux = aux->getSgte();
			}

			ant->setSgte(nullptr);
			delete aux;
		}
	}
}








