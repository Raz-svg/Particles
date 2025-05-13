#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include <vector>

using namespace std;

int height = 800;
int width = 1000;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;


typedef struct {
    int x;
    int y;
    int r;
    int g;
    int b;
    int a;
}circle;

vector<circle> circles;

int main(int argc, char* argv[]) {




    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Particle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    bool running = true;

    bool mouseDown = false;
    int mouseX = 0, mouseY = 0;
    int r=0, g=0, b=0, a=0;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                mouseDown = true;
                mouseX = event.button.x;
                mouseY = event.button.y;
                 r=rand() % 256;
                 g=rand() % 256;
                 b=rand() % 256;
                 a=rand() % 256;
                circles.push_back({mouseX, mouseY, r, g, b, a});

            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (mouseDown) {
            for (const auto& circle : circles) {
                filledCircleRGBA(renderer, circle.x, circle.y, 20, circle.r, circle.g, circle.b, circle.a);
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
