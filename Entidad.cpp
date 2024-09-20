#include "Entidad.h"

Entidad::Entidad(char caracter, int x, int y) : caracter(caracter), x(x), y(y) {}

int Entidad::RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Entidad::borrar() {
	System::Console::SetCursorPosition(x, y);
	cout << "  ";
	System::Console::SetCursorPosition(x, y + 1);
	cout << "  ";
}