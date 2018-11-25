#include <time.h>   

#include "Cpu.hpp"

using namespace std;
using namespace std::chrono;

const int DELAY_MICROSECONDS = 1200;
const int WIDTH = 224;
const int HEIGHT = 256;

void getPixels(uint32_t *pixels, State8080* state) {
	int pos, px, py;
	uint32_t p_value;
	for (int vramPtr=0; vramPtr<0x4000-0x2400; vramPtr++) {
		for (int b=0;b<8;b++) {
			p_value = (0x00FFFFFF * ((state->memory[0x2400 + vramPtr] >> b)&1)) | 0xFF000000;
			pos = vramPtr * 8 + b;
			px = pos % HEIGHT;
			py = WIDTH - (pos / HEIGHT) - 1;
			px = HEIGHT - px -1;
			py = WIDTH - py -1;
			pixels[px*WIDTH + py] = p_value;
		}
	}
}

int main (int argc, char**argv)
{

	// set up SDL 
    SDL_Window* window = SDL_CreateWindow("CHIP-8 Emulator",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            WIDTH*3, HEIGHT*3, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderSetLogicalSize(renderer, WIDTH*3, HEIGHT*3);
    
    SDL_Texture* sdl_texture = SDL_CreateTexture(renderer,
            SDL_PIXELFORMAT_ARGB8888,
            SDL_TEXTUREACCESS_STREAMING,
            WIDTH, HEIGHT);


    uint32_t pixels[WIDTH*HEIGHT];

	int done = 0;
	// int vblankcycles = 0;
	State8080* state = Init8080();
	milliseconds lastInterrupt;

	
	ReadFileIntoMemoryAt(state, (char*)"invaders.rom", 0);
	// ReadFileIntoMemoryAt(state, "invaders.g", 0x800);
	// ReadFileIntoMemoryAt(state, "invaders.f", 0x1000);
	// ReadFileIntoMemoryAt(state, "invaders.e", 0x1800);
	
	while (done == 0)
	{
        // SDL events
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                exit(0);
            }
        }

		done = Emulate8080Op(state);

		getPixels(pixels, state);

	    SDL_UpdateTexture(sdl_texture, NULL, pixels, WIDTH*sizeof(Uint32));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, sdl_texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        milliseconds ms = duration_cast< milliseconds >(
		    system_clock::now().time_since_epoch()
		);
        if ( (ms - lastInterrupt) > milliseconds(16))  //1/60 second has elapsed    
        {    
            GenerateInterrupt(state, 2);    //interrupt 2   	////////////////////////////////////////// 

            //Save the time we did this    
            lastInterrupt = ms;   
        } 

        //std::this_thread::sleep_for(std::chrono::microseconds(DELAY_MICROSECONDS));
	}
	return 0;
}