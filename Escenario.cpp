#include "Escenario.h"

Escenario::Escenario() : porcentaje(0), tiempo_ultimo_cambio(clock()), indice_enemigo_actual(0) {}

Escenario::~Escenario() {
    for (auto entidad : listaEntidades) {
        delete entidad;
    }
    listaEntidades.clear();
}

void Escenario::generarPosicionNoUtilizada(vector<int>& posX_usadas, vector<int>& posY_usadas, int& x, int& y) {
    bool posicion_valida;
    do {
        posicion_valida = true;
        x = Entidad::RandInt(6, 93);
        y = Entidad::RandInt(16, 53);

        // Verificar si la posición generada ya está ocupada en el área 2x2
        for (int i = 0; i < posX_usadas.size(); i++) {
            // Revisar si alguna de las posiciones 2x2 ya está en uso
            if ((posX_usadas[i] == x && posY_usadas[i] == y) ||
                (posX_usadas[i] == x + 1 && posY_usadas[i] == y) ||
                (posX_usadas[i] == x && posY_usadas[i] == y + 1) ||
                (posX_usadas[i] == x + 1 && posY_usadas[i] == y + 1)) {
                posicion_valida = false;
                break;
            }
        }
    } while (!posicion_valida);

    // Agregar la nueva posición 2x2 a las listas de posiciones usadas
    posY_usadas.push_back(y);
    posX_usadas.push_back(x);
    posX_usadas.push_back(x + 1);
    posY_usadas.push_back(y + 1);
}

bool Escenario::verificarColision(int x1, int y1, int x2, int y2) {
    return (x1 < x2 + 2 && x1 + 2 > x2 && y1 < y2 + 2 && y1 + 2 > y2);
}

void Escenario::addEnemigo(int x, int y) {
    listaEntidades.push_back(new Enemigo(x, y));
}

void Escenario::addAgua(int x, int y) {
    listaEntidades.push_back(new Agua(x, y));
}

void Escenario::addReciclable(int x, int y) {
    listaEntidades.push_back(new Reciclables(x, y));
}

void Escenario::addSemilla(int x, int y) {
    listaEntidades.push_back(new Semillas(x, y));
}

void Escenario::addPersonaje(int x, int y) {
    listaEntidades.push_back(new Personaje(x, y, 3));
}

void Escenario::generarCorazon(int x, int y, int color) {
    System::Console::ForegroundColor = (color == 1 ? System::ConsoleColor::Red : System::ConsoleColor::Black);
    System::Console::SetCursorPosition(x + 0, y + 0);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 1, y + 0);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 0, y + 1);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 1, y + 1);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 2, y + 1);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 1, y + 2);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 3, y + 2);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 2, y + 2);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 3, y + 0);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 4, y + 0);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 3, y + 1);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 4, y + 1);
    cout << (char)219;
    System::Console::SetCursorPosition(x + 2, y + 3);
    cout << (char)219;
    System::Console::ResetColor;
}

void Escenario::generarCuadricula() {
    System::Console::SetWindowSize(100, 60);
    for (int i = 5; i < 95; i++) {
        System::Console::SetCursorPosition(i, 15);
        cout << (char)219;
    }
    for (int i = 15; i < 55; i++) {
        System::Console::SetCursorPosition(5, i);
        cout << (char)219;
    }
    for (int i = 5; i <= 95; i++) {
        System::Console::SetCursorPosition(i, 55);
        cout << (char)219;
    }
    for (int i = 15; i < 55; i++) {
        System::Console::SetCursorPosition(95, i);
        cout << (char)219;
    }
}

void Escenario::generarBarraPorcentaje(int porcentaje) {
    for (int i = 5; i < 5 + porcentaje; i++) {
        System::Console::SetCursorPosition(i, 11);
        cout << (char)219;
        System::Console::SetCursorPosition(i, 12);
        cout << (char)219;
    }
}

void Escenario::hacerVisibleEnemigo(size_t indice) {
    if (indice < listaEntidades.size()) {
        Enemigo* enemigo = dynamic_cast<Enemigo*>(listaEntidades[indice]);
        if (enemigo) {
            enemigo->setVisible(true);
        }
    }
}

void Escenario::imp_game_over() {
    system("cls");
    System::Console::ForegroundColor = System::ConsoleColor::Cyan;
    System::Console::SetCursorPosition(0, 12);
    cout << R"(
                              ++------------------------------------------------++
                              ++------------------------------------------------++
                              ||   sSSSSs   .S_SSSs     .S_SsS_S.     sSSs      ||
                              ||  d%%%%SP  .SS~SSSSS   .SS~S*S~SS.   d%%SP      ||
                              || d%S'      S%S   SSSS  S%S `Y' S%S  d%S'        ||
                              || S%S       S%S    S%S  S%S     S%S  S%S         ||
                              || S&S       S%S SSSS%S  S%S     S%S  S&S         ||
                              || S&S       S&S  SSS%S  S&S     S&S  S&S_Ss      ||
                              || S&S       S&S    S&S  S&S     S&S  S&S~SP      ||
                              || S&S sSSs  S&S    S&S  S&S     S&S  S&S         ||
                              || S*b `S%%  S*S    S&S  S*S     S*S  S*b         ||
                              || S*S   S%  S*S    S*S  S*S     S*S  S*S.        ||
                              ||  SS_sSSS  S*S    S*S  S*S     S*S   SSSbs      ||
                              ||   Y~YSSY  SSS    S*S  SSS     S*S    YSSP      ||
                              ||                  SP           SP               ||
                              ||                  Y            Y                ||
                              ||                                                ||
                              ||   sSSs_sSSs     .S    S.     sSSs   .S_sSSs    ||
                              ||  d%%SP~YS%%b   .SS    SS.   d%%SP  .SS~YS%%b   ||
                              || d%S'     `S%b  S%S    S%S  d%S'    S%S   `S%b  ||
                              || S%S       S%S  S%S    S%S  S%S     S%S    S%S  ||
                              || S&S       S&S  S&S    S%S  S&S     S%S    d*S  ||
                              || S&S       S&S  S&S    S&S  S&S_Ss  S&S   .S*S  ||
                              || S&S       S&S  S&S    S&S  S&S~SP  S&S_sdSSS   ||
                              || S&S       S&S  S&S    S&S  S&S     S&S~YSY%b   ||
                              || S*b       d*S  S*b    S*S  S*b     S*S   `S%b  ||
                              || S*S.     .S*S  S*S.   S*S  S*S.    S*S    S%S  ||
                              ||  SSSbs_sdSSS    SSSbs_S*S   SSSbs  S*S    S&S  ||
                              ||   YSSP~YSSY      YSSP~SSS    YSSP  S*S    SSS  ||
                              ||                                    SP          ||
                              ||                                    Y           ||
                              ||                                                ||
                              ++------------------------------------------------++
                              ++------------------------------------------------++
)";
    _sleep(1500);
    System::Console::ResetColor();
}

void Escenario::imp_you_win() {
    System::Console::Clear();
    System::Console::ForegroundColor = System::ConsoleColor::Cyan;
    System::Console::SetCursorPosition(0, 12);
    cout << R"(
                                >>========================================<<
                                ||                                        ||
                                ||                                        ||
                                ||  ____     ___                          ||
                                ||  `MM(     )M'                          ||
                                ||   `MM.    d'                           ||
                                ||    `MM.  d' _____  ___   ___           ||
                                ||     `MM d' 6MMMMMb `MM    MM           ||
                                ||      `MM' 6M'   `Mb MM    MM           ||
                                ||       MM  MM     MM MM    MM           ||
                                ||       MM  MM     MM MM    MM           ||
                                ||       MM  MM     MM MM    MM           ||
                                ||       MM  YM.   ,M9 YM.   MM           ||
                                ||      _MM_  YMMMMM9   YMMM9MM_          ||
                                ||                                        ||
                                ||                                        ||
                                ||                                        ||
                                ||                                        ||
                                ||                                        ||
                                ||  ____              ___                 ||
                                ||  `Mb(      db      )d' 68b             ||
                                ||   YM.     ,PM.     ,P  Y89             ||
                                ||   `Mb     d'Mb     d'  ___ ___  __     ||
                                ||    YM.   ,P YM.   ,P   `MM `MM 6MMb    ||
                                ||    `Mb   d' `Mb   d'    MM  MMM9 `Mb   ||
                                ||     YM. ,P   YM. ,P     MM  MM'   MM   ||
                                ||     `Mb d'   `Mb d'     MM  MM    MM   ||
                                ||      YM,P     YM,P      MM  MM    MM   ||
                                ||      `MM'     `MM'      MM  MM    MM   ||
                                ||       YP       YP      _MM__MM_  _MM_  ||
                                ||                                        ||
                                ||                                        ||
                                >>========================================<<
)";
    _sleep(1500);
    System::Console::ResetColor();
}

void Escenario::play() {
    System::Console::CursorVisible = false;
    System::Console::Clear();
    // Inicialización del reloj para el contador
    clock_t tiempo_inicio = clock();  // Guarda el tiempo al inicio del juego
    double tiempo_transcurrido = 0;

    std::vector<int> posX_usadas;
    std::vector<int> posY_usadas;

    int x, y;
    int corazonX = 19;

    for (int i = 0; i < cantidad_enemigos; i++) {
        generarPosicionNoUtilizada(posX_usadas, posY_usadas, x, y);
        addEnemigo(x, y);
    }

    for (int i = 0; i < cantidad_agua; i++) {
        generarPosicionNoUtilizada(posX_usadas, posY_usadas, x, y);
        addAgua(x, y);
    }

    for (int i = 0; i < cantidad_reciclables; i++) {
        generarPosicionNoUtilizada(posX_usadas, posY_usadas, x, y);
        addReciclable(x, y);
    }

    for (int i = 0; i < cantidad_semillas; i++) {
        generarPosicionNoUtilizada(posX_usadas, posY_usadas, x, y);
        addSemilla(x, y);
    }

    generarPosicionNoUtilizada(posX_usadas, posY_usadas, x, y);
    addPersonaje(x, y);

    generarCuadricula();
    for (int i = 0, j = 5; i < 3; i++) {
        generarCorazon(j, 3, 1);
        j += 7;
    }
    generarBarraPorcentaje(porcentaje);

    for (int i = 0; i < listaEntidades.size(); i++) {
        listaEntidades[i]->dibujar();
    }

    //MOSTRAR FIGURAS
    System::Console::SetCursorPosition(36, 6);
    cout << "Personaje";
    Personaje* pers = new Personaje(40, 4, 0);
    pers->dibujar();

    System::Console::SetCursorPosition(47, 6);
    cout << "Enemigo";
    Enemigo* enem = new Enemigo(50, 4);
    enem->setVisible(true);
    enem->dibujar();

    System::Console::SetCursorPosition(59, 6);
    cout << "Agua";
    Agua* agua = new Agua(60, 4);
    agua->dibujar();

    System::Console::SetCursorPosition(66, 6);
    cout << "Reciclable";
    Reciclables* basura = new Reciclables(70, 4);
    basura->dibujar();

    System::Console::SetCursorPosition(78, 6);
    cout << "Semilla";
    Semillas* semilla = new Semillas(80, 4);
    semilla->dibujar();

    System::Console::SetCursorPosition(88, 6);
    cout << "Arbol";
    Semillas* arbol = new Semillas(89, 4);
    arbol->setRegada(true);
    arbol->dibujar();

    while (porcentaje < 70 || tiempo_transcurrido < 120) {
        // Obtener el tiempo transcurrido usando clock()
        clock_t tiempo_actual = clock();
        tiempo_transcurrido = double(tiempo_actual - tiempo_inicio) / CLOCKS_PER_SEC;

        // Mostrar el contador en la pantalla
        System::Console::SetCursorPosition(60, 57);
        cout << "Tiempo transcurrido: " << int(tiempo_transcurrido) << " segundos";

        if (tiempo_transcurrido >= 120) {
            break; // Terminar el juego 120 segundos
        }

        if (porcentaje >= 70) {
            break; // Terminar el juego 70%
        }

        // Hacer un enemigo visible cada 2 segundos
        if (double(tiempo_actual - tiempo_ultimo_cambio) / CLOCKS_PER_SEC >= 2.0) {
            if (indice_enemigo_actual < listaEntidades.size()) {
                hacerVisibleEnemigo(indice_enemigo_actual);
                indice_enemigo_actual++; // Pasamos al siguiente enemigo
                tiempo_ultimo_cambio = tiempo_actual; // Actualizamos el tiempo del último cambio
            }
        }

        //PORCENTAJE
        generarBarraPorcentaje(porcentaje);
        System::Console::SetCursorPosition(45, 13);
        cout << "             ";
        System::Console::SetCursorPosition(45, 13);
        cout << porcentaje << "%";

        //CONTADOR AGUA
        generarBarraPorcentaje(porcentaje);
        System::Console::SetCursorPosition(10, 57);
        cout << "                   ";
        System::Console::SetCursorPosition(10, 57);
        cout << "Contador Agua: " << contador_agua;

        // Hacer un dynamic_cast para comprobar si la última entidad es un personaje
        Personaje* personaje = dynamic_cast<Personaje*>(listaEntidades.back());
        if (personaje) {
            // Si es un personaje, accedemos a sus vidas
            if (personaje->getVidas() > 0) {
                // Lógica del juego mientras el personaje tenga vidas
                for (int i = 0; i < listaEntidades.size(); i++) {
                    Semillas* semilla = dynamic_cast<Semillas*>(listaEntidades[i]);
                    Enemigo* enemigo = dynamic_cast<Enemigo*>(listaEntidades[i]);
                    Agua* agua = dynamic_cast<Agua*>(listaEntidades[i]);
                    Reciclables* reciclable = dynamic_cast<Reciclables*>(listaEntidades[i]);
                    if (semilla) {
                        semilla->dibujar(); // Dibuja solo si es una semilla
                    }
                    if (enemigo) {
                        enemigo->dibujar();
                    }
                    if (agua) {
                        agua->dibujar();
                    }
                    if (reciclable) {
                        reciclable->dibujar();
                    }
                }

                for (auto entidad : listaEntidades) {
                    if (verificarColision(personaje->getX(), personaje->getY(), entidad->getX(), entidad->getY())) {
                        // Colisión detectada
                        if (Enemigo* enemigo = dynamic_cast<Enemigo*>(entidad)) {
                            // Verificar si el enemigo es visible antes de restar vida
                            if (enemigo->getVisible()) {
                                // Colisión con enemigo visible: restar una vida
                                personaje->setVidas(personaje->getVidas() - 1);
                                if (personaje->getY() < enemigo->getY()) {
                                    personaje->borrar();
                                    personaje->setX(personaje->getY() - 2);
                                }
                                if (personaje->getX() < enemigo->getX()) {
                                    personaje->borrar();
                                    personaje->setX(personaje->getX() - 2);
                                }
                                else if (personaje->getX() >= enemigo->getX()) {
                                    personaje->borrar();
                                    personaje->setX(personaje->getX() + 2);
                                }
                                generarCorazon(corazonX, 3, 2);
                                corazonX -= 7;
                            }
                        }
                        else if (dynamic_cast<Agua*>(entidad)) {
                            // Colisión con agua: aumentar contador de agua
                            contador_agua++;
                            porcentaje += 0.5;
                            listaEntidades.erase(std::remove(listaEntidades.begin(), listaEntidades.end(), entidad), listaEntidades.end());
                            entidad->borrar();
                            delete entidad;
                        }
                        else if (dynamic_cast<Reciclables*>(entidad)) {
                            porcentaje += 2;
                            listaEntidades.erase(std::remove(listaEntidades.begin(), listaEntidades.end(), entidad), listaEntidades.end());
                            entidad->borrar();
                            delete entidad;
                        }
                        else if (Semillas* semilla = dynamic_cast<Semillas*>(entidad)) {
                            if (contador_agua > 0 && !(semilla->getRegada())) {
                                semilla->setRegada(true);
                                contador_agua--;
                                porcentaje += 5;
                                // Eliminar un enemigo visible al azar
                                std::vector<Enemigo*> enemigosVisibles;
                                for (auto e : listaEntidades) {
                                    Enemigo* en = dynamic_cast<Enemigo*>(e);
                                    if (en && en->getVisible()) {
                                        enemigosVisibles.push_back(en);
                                    }
                                }
                                if (!enemigosVisibles.empty()) {
                                    // Elegir un enemigo al azar
                                    int indexAleatorio = Entidad::RandInt(0, enemigosVisibles.size() - 1);
                                    Enemigo* enemigoAleatorio = enemigosVisibles[indexAleatorio];
                                    enemigoAleatorio->borrar();
                                    enemigoAleatorio->setVisible(false);
                                    // Eliminar el enemigo al azar de la lista
                                    listaEntidades.erase(std::remove(listaEntidades.begin(), listaEntidades.end(), enemigoAleatorio), listaEntidades.end());
                                    delete enemigoAleatorio;
                                }
                            }
                        }
                    }
                }

                personaje->borrar();
                personaje->mover();
                personaje->dibujar();
                _sleep(10);
            }
            else {
                // Lógica cuando el personaje no tiene más vidas
                break;
            }
        }
    }
    // Si se rompe el bucle porque el porcentaje es >= 70 o el tiempo transcurrido es >= 120
    if (porcentaje >= 70) {
        imp_you_win();
    }
    else {
        imp_game_over();
    }

    delete pers;
    delete semilla;
    delete agua;
    delete basura;
    delete enem;
    delete arbol;
}