#include "Semillas.h"

Semillas::Semillas(int x, int y) : Entidad('*', x, y), regada(false) {}

void Semillas::dibujar() {
    if (!regada) System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
    else System::Console::ForegroundColor = System::ConsoleColor::Green;
    System::Console::SetCursorPosition(x, y); cout << caracter << caracter;
    System::Console::SetCursorPosition(x, y + 1); cout << caracter << caracter;
    System::Console::ResetColor();
}