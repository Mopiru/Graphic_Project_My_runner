/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

t_menu *create_menu(void)
{
	t_menu *menu = malloc(sizeof(t_menu));

	menu->start = 1;
	menu->quit = 0;
	return(menu);
}

t_status_game *init_status_game(void)
{
	t_status_game *status_game = malloc(sizeof(t_status_game));

	status_game->exit = 0;
	status_game->score = 0;
	status_game->menu = 1;
	status_game->finish_game = 0;
	status_game->game = 0;
	status_game->win = 0;
	return(status_game);
}

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

t_win *init_window(char *map)
{
	sfVideoMode mode = {1920, 1080, 64};
	t_win *window = malloc(sizeof(t_win));
	window->head = NULL;
	init_wall(window);
	window->window = sfRenderWindow_create(mode, "my_runner"
	, sfClose, NULL);
	window->clock = sfClock_create();
	window->map = get_map(map);
	window->character = init_character();
	window->status = RUN;
	window->status_game = init_status_game();
	window->key = init_key();
	window->menu = create_menu();
	return(window);
}
