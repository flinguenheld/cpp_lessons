// g++ -std=c++17 first_window.cpp -I "include" -L "lib" -Wall -lSDL2main -lSDL2

// Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <stdio.h>
#include <string>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Bad practice
SDL_Window *gWindow = NULL;         // The window we'll be rendering to
SDL_Surface *gScreenSurface = NULL; // The surface contained by the window
SDL_Surface *gBird = NULL;          // The image we will load and show on the screen

bool init() {

  // Initialization flag
  bool success = false;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) >= 0) {

    // Create window
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow != NULL) {

      // Initialize PNG loading
      if (IMG_Init(IMG_INIT_PNG) != 0) {

        // Get window surface
        gScreenSurface = SDL_GetWindowSurface(gWindow);
        success = true;

      } else
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());

    } else
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

  } else
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

  return success;
}

SDL_Surface *loadSurface(std::string path) {

  // The final optimized image
  SDL_Surface *optimizedSurface = NULL;

  // Load image at specified path
  SDL_Surface *loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface != NULL) {

    // Convert surface to screen format
    optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
    if (optimizedSurface == NULL) {
      printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }

    // Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);

  } else
    printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());

  return optimizedSurface;
}

bool loadMedia() {
  // Loading success flag
  bool success = false;

  // Load PNG surface
  gBird = loadSurface("./bird.png");
  if (gBird != NULL) {
    success = true;
  } else
    printf("Failed to load PNG image!\n");

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
  IMG_Quit();
  SDL_Quit();
}

int main(int argc, char *argv[]) {
  // Start up SDL and create window
  if (init()) {

    if (loadMedia()) {

      bool quit = false;
      SDL_Event e;

      while (!quit) {

        while (SDL_PollEvent(&e) != 0)

          if (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_PLUS ||
              e.key.keysym.sym == SDLK_KP_PLUS || e.key.keysym.scancode == SDL_SCANCODE_KP_PLUS ||
              e.key.keysym.scancode == SDL_SCANCODE_SEMICOLON)
            quit = true;

        // Apply the image
        SDL_BlitSurface(gBird, NULL, gScreenSurface, NULL);

        // Update the surface
        SDL_UpdateWindowSurface(gWindow);
      }

    } else
      printf("Failed to load media!\n");

  } else
    printf("Failed to initialize!\n");

  // Free resources and close SDL
  close();

  return 0;
}
