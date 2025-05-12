#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>

int main(int argc,char *argv[])
// argc  argument count
// argv  argument vector representing the arguments

{
    bool init=SDL_Init(SDL_INIT_EVERYTHING);
    if(init!=0)
    {
        SDL_Log("SDL_Init Error: %s",SDL_GetError());
        return 1;
    }



}
