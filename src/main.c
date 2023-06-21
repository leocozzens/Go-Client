// Local headers
#include <window.h>

int main(void) {
    
    SDL_Window* master = NULL;
    SDL_Renderer* renderer = NULL;
    init(&master, &renderer);

    _Bool winActive = 1;
    while(winActive) {
    run_loop(&winActive, renderer);
    }

    clean_quit(master, renderer);

    return 0;
}