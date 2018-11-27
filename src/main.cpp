
#include "SDL2/SDL.h"

#include "InvadersIO.hpp"
#include "Intel8080.hpp"

using namespace std;
using namespace std::chrono;

// keymap from keyboard to port bit
// SDLK_0 is reserved to indicate the bit is not used
const vector<SDL_Keycode> keymap1 = 
		{SDLK_c, SDLK_2, SDLK_1, SDLK_0, SDLK_w, SDLK_a, SDLK_d, SDLK_0};
const vector<SDL_Keycode> keymap2 = 
		{SDLK_0, SDLK_0, SDLK_t, SDLK_0, SDLK_w, SDLK_a, SDLK_d, SDLK_z};

const int MSPERFRAME = 16;

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
	InvadersIO dev_io = InvadersIO();
	Intel8080 i8080 = Intel8080(&dev_io);
	i8080.loadFile("../roms/invaders.rom");
	uint16_t next_inte = 0x0008;

	milliseconds last_ms, now_ms;
	
	while (true)
	{
		// SDL events
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				exit(0);
			} else if (e.type == SDL_KEYDOWN) {
				const SDL_Keycode key = e.key.keysym.sym;
				if (key==SDLK_ESCAPE) {
					exit(0);
				}
				for (int i=0; i<8; i++) {
					if (keymap1[i]!=SDLK_0 && keymap1[i]==key) {
						dev_io.setPort1(i, true);
						break;
					}
				}				
				for (int i=0; i<8; i++) {
					if (keymap2[i]!=SDLK_0 && keymap2[i]==key) {
						dev_io.setPort2(i, true);
						break;
					}
				}	
			} else if (e.type == SDL_KEYUP) {
				const SDL_Keycode key = e.key.keysym.sym;
				for (int i=0; i<8; i++) {
					if (keymap1[i]!=SDLK_0 && keymap1[i]==key) {
						dev_io.setPort1(i, false);
						break;
					}
				}				
				for (int i=0; i<8; i++) {
					if (keymap2[i]!=SDLK_0 && keymap2[i]==key) {
						dev_io.setPort2(i, false);
						break;
					}
				}
			}
		}

		now_ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		if ((now_ms-last_ms) > milliseconds(MSPERFRAME))  //1/60 second has elapsed    
		{    
			// interrupt 
			i8080.generateInterrupt(next_inte);
			next_inte = (next_inte==0x0008 ? 0x0010 : 0x0008);
			last_ms = now_ms; 

			// draw graphics
			i8080.getPixels(pixels);
			SDL_UpdateTexture(sdl_texture, NULL, pixels, WIDTH*sizeof(Uint32));
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, sdl_texture, NULL, NULL);
			SDL_RenderPresent(renderer);
		} 
		
		// process 1 opcode
		i8080.mainLoop();
	}
	return 0;
}