/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

void add_button_retry(t_win *window)
{
	t_obj *temp = malloc(sizeof(t_obj));

	temp = add_to_chain(window, "./asset/defeat_retry.png", DEFEAT
	, (sfIntRect){0,0,815,551});
	temp->pos.x = 552;
	temp->pos.y = 100;
}

void add_button_menu(t_win *window)
{
	t_obj *temp = malloc(sizeof(t_obj));

	temp = add_to_chain(window, "./asset/menu.png", MENU
	, (sfIntRect){0,0,176,176});
	temp->pos.x = 100;
	temp->pos.y = 100;
}

void add_button_win(t_win *window)
{
	t_obj *temp = malloc(sizeof(t_obj));

	temp = add_to_chain(window, "./asset/win.png", WIN
	, (sfIntRect){0,0,815,515});
	temp->pos.x = 552;
	temp->pos.y = 100;
}

void init_wall(t_win *window)
{
	t_obj *temp = malloc(sizeof(t_obj));

	init_chain(window, "./asset/die.png", DIE
	, (sfIntRect){0,0,1920, 1080});
	add_to_chain(window, "./asset/start.png", START
	, (sfIntRect){0,0,1920, 1080});
	add_to_chain(window, "./asset/score.png", SCORE
	, (sfIntRect){0,0,1920, 1080});
	number_font(window);
	add_button_quit(window);
	add_button_win(window);
	add_button_play(window);
	add_button_retry(window);
	add_button_menu(window);
	free(temp);
}

t_win *init_window(char *map, int level_activate)
{
	t_win *window = malloc(sizeof(t_win));
	sfVideoMode mode = {1920, 1080, 64};
	window->head = NULL;
	init_wall(window);
	window->window = sfRenderWindow_create(mode, "my_runner"
	, sfClose, NULL);
	window->map = get_map(map, level_activate);
	window->clock = sfClock_create();
	window->character = init_character();
	window->status = RUN;
	window->status_game = init_status_game();
	window->key = init_key();
	window->menu = create_menu();
	window->status_game->level_activate = level_activate;
	return(window);
}
