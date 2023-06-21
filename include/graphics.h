#ifndef GRAPHICS_H
#define GRAPHICS_H

// Simple direct media layer graphics lib
#include <SDL2/SDL.h>

void draw_thick_rect(SDL_Renderer* renderer, int rectX, int rectY, int rectWidth, int rectHeight, int thickness, int offset);

#endif