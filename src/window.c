#include <window.h>

void init(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        exit(1);
    }

    *window = SDL_CreateWindow(
        "Go Fish",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        TILE_SIZE * BOARD_WIDTH,
        TILE_SIZE * BOARD_HEIGHT,
        SDL_WINDOW_RESIZABLE
    );
    *renderer = SDL_CreateRenderer(*window, -1, 0);

    if (*window == NULL || *renderer == NULL) {
        fprintf(stderr, "Failed to create SDL window or renderer: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
}

void run_loop(_Bool *winActive, SDL_Renderer* renderer) {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            *winActive = 0;
        }
    }

    SDL_SetRenderDrawColor(renderer, 248, 176, 76, 255);
    SDL_RenderClear(renderer); // Clears with RenderDrawColor

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            SDL_Rect rect = {(j * TILE_SIZE) + BORDER_PADDING, (i * TILE_SIZE) + BORDER_PADDING, TILE_SIZE, TILE_SIZE};
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
    SDL_Rect outerRect = {0, 0, (TILE_SIZE * BOARD_WIDTH) + BORDER_PADDING * 2, (TILE_SIZE * BOARD_HEIGHT) + BORDER_PADDING * 2};
    SDL_RenderDrawRect(renderer, &outerRect);
    SDL_RenderPresent(renderer);
}

void clean_quit(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}