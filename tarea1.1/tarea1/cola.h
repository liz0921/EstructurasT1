#pragma once
#include "nodoS.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
class cola
{

private:
	int tam;
	nodoS* pFrente;
	nodoS* pFinal;

public:
	cola();
	int getTam();
	nodoS* getpFrente();
	nodoS* getpFinal();
	void setTam(int tam_);
	void setPFrente(nodoS* pfrente);
	void setPFinal(nodoS* pFinal);
	bool esVacia();
	int largo();
	void poner(int);
	int quitar();
	void showCola();


};

