// g++ -std=c++17 first_window.cpp -I "include" -L "lib" -Wall -lSDL2main -lSDL2

// Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <stdio.h>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Bad practice
SDL_Window *gWindow = NULL;         // The window we'll be rendering to
SDL_Surface *gScreenSurface = NULL; // The surface contained by the window
SDL_Surface *gBird = NULL;          // The image we will load and show on the screen

bool init() {

  // Initialization flag
  bool success = true;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    success = false;
  } else {
    // Create window
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      success = false;
    } else {
      // Get window surface
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
  }

  return success;
}

bool loadMedia() {
  // Loading success flag
  bool success = true;

  // Load splash image
  gBird = SDL_LoadBMP("./poulet.bmp");
  if (gBird == NULL) {
    printf("Unable to load image %s! SDL Error: %s\n", "./poulet.bmp", SDL_GetError());
    success = false;
  }

  return success;
}

void close() {
  // Deallocate surface
  SDL_FreeSurface(gBird);
  gBird = NULL;

  // Destroy window
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;

  // Quit SDL subsystems
  SDL_Quit();
}

int main(int argc, char *argv[]) {
  // Start up SDL and create window
  if (!init()) {
    printf("Failed to initialize!\n");
  } else {
    // Load media
    if (!loadMedia()) {
      printf("Failed to load media!\n");
    } else {

      // --
      bool quit = false;
      SDL_Event e;

      while (!quit) {

        while (SDL_PollEvent(&e) != 0)

          // if (e.type == SDL_QUIT) {
          //   quit = true;
          // }

          if (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_PLUS ||
              e.key.keysym.sym == SDLK_KP_PLUS || e.key.keysym.scancode == SDL_SCANCODE_KP_PLUS ||
              e.key.keysym.scancode == SDL_SCANCODE_SEMICOLON)
            quit = true;

        // Apply the image
        SDL_BlitSurface(gBird, NULL, gScreenSurface, NULL);

        // Update the surface
        SDL_UpdateWindowSurface(gWindow);
      }
    }
  }

  // Free resources and close SDL
  close();

  return 0;
}
