#include <SDL.h>
#include <iostream>
#include <locale.h>
using namespace std;

void clear(SDL_Window* win, SDL_Renderer* ren){

    SDL_DestroyRenderer(ren);
    ren = NULL;

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (ren == NULL) {
        cout << "Can't create renderer: " << SDL_GetError() << endl;
    }

    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);

    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
}