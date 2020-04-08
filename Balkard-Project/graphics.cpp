#include "graphics.h"
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <ctime>

#include <iostream>
#include <string>
#include <vector>



void graphics::clear() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
    SetConsoleCursorPosition(console, topLeft);
}

//void graphics::Color(int couleurDuTexte, int couleurDeFond) {
//    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
//}