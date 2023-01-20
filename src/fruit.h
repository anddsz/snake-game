#ifndef food_H
#define food_H

#include "linked_list.h"
#include "snake.h"
#include <SDL2/SDL_image.h>

typedef struct Food Food;

typedef struct Food {
	int x, y;
	SDL_Texture* texture;
} Food;

Food createFoodData(int x, int y, SDL_Texture* texture);
void moveFood(Food* food, int x, int y);
void renderFood(Food* food);
char isFoodOnSnake(LinkedListNode** snake_head, Food food);

#endif
