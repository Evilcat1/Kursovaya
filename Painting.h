#include <SDL.h>
#include <iostream>
#include <locale.h>
using namespace std;

void painting(SDL_Renderer* ren) {
    int n;
    cout << "Что вы хотите нарисовать?" << endl << "1-Прямоугольник, 2-Линию, 3-Точку" << endl;
    cin >> n;
    int x, y, z, t;
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);

    if (n == 1) {
        cout << "Введите координаты x, y, и размеры прямоугольника" << endl;
        cin >> x >> y >> z >> t;
        SDL_Rect rect1 = { x, y, z, t};
        SDL_RenderFillRect(ren, &rect1);
    }

    else if (n == 2) {
        cout << "Введите координаты x1, y1, x2, y2" << endl;
        cin >> x >> y >> z >> t;
        SDL_RenderDrawLine(ren, 20, 20, 400, 400);
    }

    else if (n == 3) {
        cout << "Введите координаты x, y" << endl;
        cin >> x >> y;
        SDL_RenderDrawPoint(ren, x, y);
    }

    SDL_RenderPresent(ren);
}