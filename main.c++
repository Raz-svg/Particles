#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include <vector>

using namespace std;

int height = 1000;
int width = 1200;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

typedef struct {
    int x;
    int y;
    int r;
    int g;
    int b;
    int a;
} circle;

vector<circle> circles;



void gravity(vector<circle>& circles, float gravity) {
    for (auto& c : circles) {
        c.y += gravity;
    }
}

void collidion_with_circle(circle& c1, circle& c2) {
    int dx = c1.x - c2.x;
    int dy = c1.y - c2.y;
    float distance = sqrt(dx * dx + dy * dy);
    if (distance < 20) {
        float angle = atan2(dy, dx);
        float speed = 5.0f;
        c1.x += cos(angle) * speed;
        c1.y += sin(angle) * speed;
        c2.x -= cos(angle) * speed;
        c2.y -= sin(angle) * speed;
    }
}

int main(int argc, char* argv[]) {

    int counter=0;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    window = SDL_CreateWindow("Particle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    bool running = true;

    bool mouseDown = false;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    mouseDown = true;
                }
            }

            if (event.type == SDL_MOUSEBUTTONUP) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    mouseDown = false;
                }
            }

            if (event.type == SDL_MOUSEMOTION && mouseDown) {
                int mouseX = event.motion.x;
                int mouseY = event.motion.y;
                int r = rand() % 256;
                int g = rand() % 256;
                int b = rand() % 256;
                int a = rand() % 256;
                circles.push_back({mouseX, mouseY, r, g, b, a});
                counter++;
            }
          
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        gravity(circles, 9.8);
        for (size_t i = 0; i < circles.size(); ++i) {
            for (size_t j = i + 1; j < circles.size(); ++j) {
                collidion_with_circle(circles[i], circles[j]);
            }
        }

        for (auto& c : circles) {
            if (c.y > height) {
                c.y = height;
            }
            if (c.y < 0) {
                c.y = 0;
            }
            if (c.x > width) {
                c.x = width;
            }
            if (c.x < 0) {
                c.x = 0;
            }
            filledCircleRGBA(renderer, c.x, c.y, 5, c.r, c.g, c.b, c.a);
           
           
        }
         cout<<counter<<endl;

        SDL_RenderPresent(renderer);


    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
