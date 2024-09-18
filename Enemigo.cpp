#include "Enemigo.h"

Enemigo::Enemigo(int x, int y) : Entidad('X', x, y), visible(false) {}

void Enemigo::dibujar() {
    if (visible) {
        System::Console::ForegroundColor = System::ConsoleColor::Red;
        System::Console::SetCursorPosition(x, y); cout << caracter << caracter;
        System::Console::SetCursorPosition(x, y+1); cout << caracter << caracter;
        System::Console::ResetColor();
    }
}