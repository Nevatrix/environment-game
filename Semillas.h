#pragma once
#include "Entidad.h"
class Semillas : public Entidad
{
public:
	Semillas(int x, int y);
	void dibujar() override;
	bool getRegada() { return regada; }
	void setRegada(bool regada) { this->regada = regada; }
private:
	bool regada;
};
