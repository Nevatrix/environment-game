#pragma once
#include "Entidad.h"

class Agua : public Entidad
{
private:

public:
	Agua(int x, int y);
	void dibujar() override;
};