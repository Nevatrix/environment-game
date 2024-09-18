#include "Reciclables.h"

Reciclables::Reciclables(int x, int y) : Entidad('#', x, y) {}

void Reciclables::dibujar() {
    System::Console::ForegroundColor = System::ConsoleColor::DarkGray;
    System::Console::SetCursorPosition(x, y); cout << caracter << caracter;
    System::Console::SetCursorPosition(x, y+1); cout << caracter << caracter;
    System::Console::ResetColor();
}