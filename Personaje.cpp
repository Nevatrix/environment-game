#include "Personaje.h"

Personaje::Personaje(int x, int y, int vidas) : Entidad('@', x, y), vidas(vidas) {}

void Personaje::mover() {
    char tecla;
    if (_kbhit()) {
        tecla = _getch();
        switch (tecla)
        {
        case 72:
            if (y > 16)
            {
                y--;
            }
            break;
        case 75:
            if (x > 6)
            {
                x--;
            }
            break;
        case 77:
            if (x < 93)
            {
                x++;
            }
            break;
        case 80:
            if (y < 53)
            {
                y++;
            }
            break;
        }
    }
}

void Personaje::dibujar() {
    System::Console::SetCursorPosition(x, y); cout << caracter << caracter;
    System::Console::SetCursorPosition(x, y+1); cout << caracter << caracter;
}