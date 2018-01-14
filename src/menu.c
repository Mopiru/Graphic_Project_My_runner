/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

void display_menu(t_win *window)
{
	t_obj *temp = window->head;

	while(temp != NULL) {
		if (temp->type_wall == QUIT || temp->type_wall == PLAY
		|| temp->type_wall == START){
			sfSprite_setTextureRect(temp->sprite, temp->rect);
			sfSprite_setPosition(temp->sprite, temp->pos);
			sfRenderWindow_drawSprite(window->window, temp->sprite, NULL);
		}
		temp = temp->next;
	}
}

void check_menu_button(t_win *window)
{
	if(window->mouse.x < 660 && window->mouse.x > 484
	&& window->mouse.y > 750 && window->mouse.y < 926) {
		window->status_game->menu = 0;
		window->status_game->game = 1;
	}
	if(window->mouse.x < 1436 && window->mouse.x > 1260
	&& window->mouse.y > 750 && window->mouse.y < 926) {
		window->status_game->menu = 0;
		window->status_game->exit = 1;
	}
}

t_win *menu(t_win *window)
{
	display_menu(window);
	while(window->status_game->menu == 1) {
		master_event(window);
		check_menu_button(window);
		sfRenderWindow_display(window->window);
		if(window->status_game->exit == 1)
			return(0);
	}
	return(window);
}

void add_button_quit(t_win *window)
{
	t_obj *temp = malloc(sizeof(t_obj));

	temp = add_to_chain(window, "./asset/quit.png", QUIT
	, (sfIntRect){0,0,176, 176});
	temp->pos.x = 1260;
	temp->pos.y = 750;
}

void add_button_play(t_win *window)
{
	t_obj *temp = malloc(sizeof(t_obj));

	temp = add_to_chain(window, "./asset/play.png", PLAY
	, (sfIntRect){0,0,176, 176});
	temp->pos.x = 484;
	temp->pos.y = 750;
}
