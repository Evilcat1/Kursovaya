#include <SDL.h>
#include <iostream>
#include <locale.h>
using namespace std;

void painting(SDL_Renderer* ren) {
    int n;
    cout << "��� �� ������ ����������?" << endl << "1-�������������, 2-�����, 3-�����" << endl;
    cin >> n;
    int x, y, z, t;
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);

    if (n == 1) {
        cout << "������� ���������� x, y, � ������� ��������������" << endl;
        cin >> x >> y >> z >> t;
        SDL_Rect rect1 = { x, y, z, t};
        SDL_RenderFillRect(ren, &rect1);
    }

    else if (n == 2) {
        cout << "������� ���������� x1, y1, x2, y2" << endl;
        cin >> x >> y >> z >> t;
        SDL_RenderDrawLine(ren, 20, 20, 400, 400);
    }

    else if (n == 3) {
        cout << "������� ���������� x, y" << endl;
        cin >> x >> y;
        SDL_RenderDrawPoint(ren, x, y);
    }

    SDL_RenderPresent(ren);
}