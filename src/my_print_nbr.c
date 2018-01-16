/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

t_obj *cond_print_score(t_win *window, t_obj *temp, int number, sfVector2f pos)
{
	while(temp != NULL) {
		if ((int)temp->type_wall == number) {
			sfSprite_setPosition(temp->sprite, pos);
			sfRenderWindow_drawSprite(window->window
			, temp->sprite, NULL);
			}
			temp = temp->next;
	}
	return (temp);
}

void print_score(t_win *window)
{
	int number;
	t_obj *temp = window->head;
	sfVector2f pos = {1300,635};
	int save = window->status_game->score;

	while (window->status_game->score != 0) {
		number = window->status_game->score % 10;
		window->status_game->score = window->status_game->score / 10;
		pos.x -= 45;
		cond_print_score(window, temp, number, pos);
	}
	window->status_game->score = save;
}
