#pragma once
#include <stdlib.h>

class nodoS
{
private:
	int dato;
	nodoS* sgte;

public:
	nodoS(int, nodoS*);

	nodoS();
	nodoS(int);
	~nodoS();

	int getDato();
	nodoS* getSgte();

	void setDato(int);
	void setSgte(nodoS*);
};


