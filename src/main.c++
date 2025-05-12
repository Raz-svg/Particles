#include<SDL2/SDL.h>
#include<iostream>

int height=600;
int width=800;

SDL_Window* window=nullptr;
SDL_Renderer* renderer=nullptr;
SDL_Texture* texture=nullptr;
SDL_Surface* surface=nullptr;


int main(int argc,char* argv[]){

    if(SDL_Init(SDL_INIT_VIDEO)<0){
        std::cout<<"SDL could not initialize! SDL_Error: "<<SDL_GetError()<<std::endl;
        return 1;
    }
    window=SDL_CreateWindow("Particle",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(window==nullptr){
        std::cout<<"Window could not be created! SDL_Error: "<<SDL_GetError()<<std::endl;
        return 1;
    }
    if (renderer == nullptr) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    bool running=true;
    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                running=false;
            }
        }
        SDL_SetRenderDrawColor(renderer,252,255,255,255);
           // Clear the screen with the draw color
        SDL_RenderClear(renderer); 
        // Update the screen
        SDL_RenderPresent(renderer); 
    }
     
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;


}