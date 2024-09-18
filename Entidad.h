#pragma once
#include "iostream"
using namespace std;
class Entidad
{
public:
	Entidad(char, int, int);
	void borrar();
	virtual void dibujar() = 0;
	int getX() { return x; }
	int getY() { return y; }
	void setX(int x) { this->x = x; }
	static int RandInt(int min, int max);
protected:
	char caracter;
	int x, y;
};
