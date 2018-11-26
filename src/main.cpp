
#include "Intel8080.hpp"

using namespace std;
using namespace std::chrono;



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


	// initialize emulator
	Intel8080 i8080 = Intel8080();
	i8080.loadFile("../roms/invaders.rom");


	milliseconds lastInterrupt;
	
	while (true)
	{
		// SDL events
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
				if (e.type == SDL_QUIT) {
						exit(0);
				}
		}

		i8080.mainLoop();

		i8080.getPixels(pixels);

		SDL_UpdateTexture(sdl_texture, NULL, pixels, WIDTH*sizeof(Uint32));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, sdl_texture, NULL, NULL);
		SDL_RenderPresent(renderer);

		milliseconds ms = duration_cast< milliseconds >(
				system_clock::now().time_since_epoch());
		if ( (ms - lastInterrupt) > milliseconds(16))  //1/60 second has elapsed    
		{    
			i8080.generateInterrupt(2);    //interrupt 2    ////////////////////////////////////////// 

			//Save the time we did this    
			lastInterrupt = ms;   
		} 

		// std::this_thread::sleep_for(std::chrono::microseconds(DELAY_MICROSECONDS));
	}
	return 0;
}