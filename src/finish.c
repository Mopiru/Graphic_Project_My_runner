/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

void display_finish_two(t_win *window)
{
	t_obj *temp = window->head;

	while(temp != NULL) {
		if(window->status_game->win == 1 && temp->type_wall == WIN){
			sfSprite_setTextureRect(temp->sprite, temp->rect);
			sfSprite_setPosition(temp->sprite, temp->pos);
			sfRenderWindow_drawSprite(window->window
			, temp->sprite, NULL);
		}
		if(window->status_game->win == -1
		&& temp->type_wall == DEFEAT){
			sfSprite_setTextureRect(temp->sprite, temp->rect);
			sfSprite_setPosition(temp->sprite, temp->pos);
			sfRenderWindow_drawSprite(window->window
			, temp->sprite, NULL);
		}
		temp = temp->next;
	}
}

void display_finish_one(t_win *window)
{
	t_obj *temp = window->head;

	while(temp != NULL) {
		if (temp->type_wall == SCORE && window->status_game->win == 1){
			sfSprite_setTextureRect(temp->sprite, temp->rect);
			sfSprite_setPosition(temp->sprite, temp->pos);
			sfRenderWindow_drawSprite(window->window
			, temp->sprite, NULL);
		}
		if (temp->type_wall == DIE && window->status_game->win == -1){
			sfSprite_setTextureRect(temp->sprite, temp->rect);
			sfSprite_setPosition(temp->sprite, temp->pos);
			sfRenderWindow_drawSprite(window->window
			, temp->sprite, NULL);
		}
		temp = temp->next;
	}
	display_finish_two(window);
}

void status_game_next_level(t_win *window)
{
	if(window->status_game->level_activate == 1) {
		window->status_game->finish_game = 0;
		window->status_game->win = 0;
		window->status_game->game = 1;
		window->status_game->level += 1;
	} else {
		status_game_menue(window);
	}
}

void check_finish_button(t_win *window)
{
	if(window->mouse.x < 1137 && window->mouse.x > 752
	&& window->mouse.y > 300 && window->mouse.y < 615
	&& window->status_game->win == 1) {
		status_game_next_level(window);
	}
	if(window->mouse.x < 1137 && window->mouse.x > 752
	&& window->mouse.y > 300 && window->mouse.y < 615
	&& window->status_game->win == -1) {
		status_game_retry(window);
	}
}

t_win *finish(t_win *window)
{
	display_finish_one(window);
	if(window->status_game->win == 1)
		print_score(window);
	while(window->status_game->finish_game == 1) {

		master_event(window);
		get_instruction(window);
		check_finish_button(window);
		sfRenderWindow_display(window->window);
		if(window->status_game->exit == 1)
			return(0);
	}
	return(window);
}
