#include <SDL2/SDL.h>

void draw_thick_rect(SDL_Renderer* renderer, int rectX, int rectY, int rectWidth, int rectHeight, int thickness) { // Draws rect outlines outside of original rect according to thickness
    for(int i = 0; i < thickness; i++) {
        SDL_Rect rect = {rectX + i, rectY + i, rectWidth - (2 * i), rectHeight - (2 * i)};
        SDL_RenderDrawRect(renderer, &rect);
    }
}