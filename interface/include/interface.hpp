#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Card.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void peprareWindow(int width, int heigth);

void displayScreen(int delay);

int calculateCardHeight(int width);

void drawCard(Card cardToShow, int position_x, int position_y, int card_w, int card_h);

void showCard(Card cardToShow);

#endif // INTERFACE_HPP