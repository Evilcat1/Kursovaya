
#include<SDL.h>
#include<iostream>
#include "Header.h"
SDL_Window* win = NULL;
//SDL_Surface* scr = NULL;
SDL_Surface* pengvin = NULL;
/*int processEvents() {
	SDL_Rect r;
	bool run = true; // переменная для выполнения цикла while
	SDL_Event e;     // объект для данных получаемого события
	while (run) {
		while (SDL_PollEvent(&event) != NULL) {
			if (SDL_PollEvent(&event)) {
				myButton.handle_events();
			}
		
			if (event.type == SDL_QUIT) {
				run = false;
			}
		}
		SDL_BlitSurface(pengvin, NULL, scr, NULL);
		SDL_UpdateWindowSurface(win);
	}
	return 0;
 }*/

int init(SDL_Surface* scr) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		return 1;
	}
	win = SDL_CreateWindow("OKNO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (win == NULL) {
		return 1;
	}
	 scr=SDL_GetWindowSurface(win);
	// SDL_Delay(2000);

	return 0;
	
}int load() {
	pengvin = SDL_LoadBMP("pengvin.BMP");
	if (pengvin == NULL) {
		return 1;
	}
	return 0;
}
int quit() {
	SDL_FreeSurface(pengvin);
	

	SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}


int main(int argc, char** args) {
	if (init(scr) == 1) {
		return 1;
	}
	if (load() == 1) {
		return 1;
	}
	bool Quit = false;
	//if (processEvents() == 1) {
		//return 1;
	//}
	set_clips();  // установка положения клипов на спрайте
	Button myButton(170, 120, 320, 240);  // кнопка
	while (Quit == false) { // цикл ожидания действий пользователя
		if (SDL_PollEvent(&event)) {
			myButton.handle_events();  // обрабатываем события
			if (event.type == SDL_QUIT) {   // если выход - сменить флаг
				Quit = true;
			}
		}
		SDL_FillRect(scr, &scr->clip_rect, SDL_MapRGB(scr->format, 0xFF, 0xFF, 0xFF));
		myButton.show();  // показываем кнопку
		//if (SDL_Flip(scr) == -1) {
			//return 1;
		//}
	}

	SDL_BlitSurface(pengvin, NULL, scr, NULL);

	SDL_UpdateWindowSurface(win);
	//SDL_Delay(2000);
	return quit();

};






