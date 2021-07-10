#include <iostream>
#include <SDL.h>
#include "Createwindow.h"
#include "Clear.h"
#include <locale.h>
#include "Painting.h"
using namespace std;

void quit() {
    SDL_DestroyWindow(win);
    win = NULL;

    SDL_DestroyRenderer(ren);
    ren = NULL;

    SDL_Quit();
}

int main(int arhc, char** argv) {
    setlocale(LC_ALL, "Russian");
    int x=0;
    init();
    while (x!=2) {
        cout << "Если вы хотите нарисовать фигуру, нажмите 1, если хотите выйти, нажмите 2, если хотите отчистить поле, нажмите 3" << endl;
        cin >> x;
        if (x == 1) {
            painting(ren);
        }

        else if (x == 2) {
            quit();
        }
        else if (x == 3) {
            clear(win, ren);
        }
    }
    return 0;
}