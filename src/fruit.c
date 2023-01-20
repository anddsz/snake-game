#include "food.h"
#include "linked_list.h"
#include "renderer.h"
#include "game.h"

Food* createFood(int x, int y, SDL_Texture* texture){
	Food* food = (Food*)malloc(sizeof(Food));

	food->x = x;
	food->y = y;
	food->texture = texture;

	return food;
}

void renderFood(Food* food){
	if(food->texture == NULL){
		renderRectangle(food->x, food->y, 16, 16, 0xFF0000);

		return;
	}

	SDL_Rect texture_rectangle = {
		.x = food->x * 16,
		.y = food->y * 16,
		.w = 16,
		.h = 16,
	};

	SDL_RenderCopy(main_renderer, food->texture, NULL, &texture_rectangle);
}

int isFoodOnSnake(LinkedListNode** snake_head, Food* food){
	for(LinkedListNode* ptr = *snake_head; ptr != NULL; ptr = ptr->link){
		if(food->x == ((SnakeData*)ptr->data)->x
		&& food->y == ((SnakeData*)ptr->data)->y){
			if(ptr == *snake_head){
				return 1;
			}
		}
	}

	return 0;
}
