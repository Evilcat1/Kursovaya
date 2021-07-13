#include <SDL.h>
#include <string>
const int CLIP_MOUSEOVER = 0;
const int CLIP_MOUSEOUT = 1;
const int CLIP_MOUSEDOWN = 2;
const int CLIP_MOUSEUP = 3;
SDL_Surface* buttonSheet = NULL;
SDL_Surface* scr = NULL;
SDL_Event event;
SDL_Rect clips[4];

class Button {
private:
    SDL_Rect box;  // �������� ������ (��������������)
    SDL_Rect* clip;  // ����� ������� ������� ����� ��������

public:
    Button(int x, int y, int w, int h);  // �����������
    void handle_events();  // ��������� �������
    void show();  // ���������� "������" �� ������
};
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, clip, destination, &offset);
}
void set_clips() {
    clips[CLIP_MOUSEOVER].x = 0;
    clips[CLIP_MOUSEOVER].y = 0;
    clips[CLIP_MOUSEOVER].w = 320;
    clips[CLIP_MOUSEOVER].h = 240;

    clips[CLIP_MOUSEOUT].x = 320;
    clips[CLIP_MOUSEOUT].y = 0;
    clips[CLIP_MOUSEOUT].w = 320;
    clips[CLIP_MOUSEOUT].h = 240;

    clips[CLIP_MOUSEDOWN].x = 0;
    clips[CLIP_MOUSEDOWN].y = 240;
    clips[CLIP_MOUSEDOWN].w = 320;
    clips[CLIP_MOUSEDOWN].h = 240;

    clips[CLIP_MOUSEUP].x = 320;
    clips[CLIP_MOUSEUP].y = 240;
    clips[CLIP_MOUSEUP].w = 320;
    clips[CLIP_MOUSEUP].h = 240;
}
Button::Button(int x, int y, int w, int h) {
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
    clip = &clips[CLIP_MOUSEOUT];
}
void Button::handle_events() {
    int x = 0, y = 0;  /// �������� ������� ���� �� ���������
    if (event.type == SDL_MOUSEMOTION) {  // ���� ���� �������� ��������� ����� ���������� �������
        x = event.motion.x;
        y = event.motion.y;
        // ���� ������ ������ "������"
        if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h)) {
            clip = &clips[CLIP_MOUSEOVER];  // ������ ���� � ���������� � ���, ��� ������ �� ������
        }
        else {
            clip = &clips[CLIP_MOUSEOUT];  // ����� �� �� ������
        }
    }
    // ���� ���� ������ ������
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {  // ����� ������� ����
            x = event.button.x;  // ����������
            y = event.button.y;
            ///  ... ��� ��� ���� ������������� ������ ������ ������
            if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h)) {
                clip = &clips[CLIP_MOUSEDOWN];  // ������ ���� � ���������� � ���, ��� ������ ������
            }
        }
    }
    // ���� ������ ���� ������
    if (event.type == SDL_MOUSEBUTTONUP) {
        if (event.button.button == SDL_BUTTON_LEFT) {  // ����� ������� ���� ... ������ ����������
            x = event.button.x;
            y = event.button.y;
            if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h)) {
                clip = &clips[CLIP_MOUSEUP];
            }
        }
    }
}
void Button::show() {
    apply_surface(box.x, box.y, buttonSheet, scr, clip);
}



 