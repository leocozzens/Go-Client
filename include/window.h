#ifndef WINDOW_H
#define WINDOW_H

// C standard libraries
#include <stdio.h>

// Local headers
#include <graphics.h>

#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9
#define TILE_SIZE 50
#define BORDER_PADDING 10

void init(SDL_Window **window, SDL_Renderer **renderer);
void run_loop(_Bool *winActive, SDL_Renderer* renderer);
void clean_quit(SDL_Window *window, SDL_Renderer *renderer);

#endif