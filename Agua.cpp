#include "Agua.h"

Agua::Agua(int x, int y) : Entidad('~', x, y) {}

void Agua::dibujar() {
    System::Console::ForegroundColor = System::ConsoleColor::Blue;
    System::Console::SetCursorPosition(x, y); cout << caracter << caracter;
    System::Console::SetCursorPosition(x, y+1); cout << caracter << caracter;
    System::Console::ResetColor();
}