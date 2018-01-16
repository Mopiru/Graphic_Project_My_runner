/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

t_win *re_window(t_win *window)
{
	free(window->character);
	free(window->map->obstacle);

	window->head = NULL;
	init_wall(window);
	window->character = init_character();
	window->status = RUN;
	window->key = init_key();
	window->menu = create_menu();
	if(window->status_game->level_activate == 1) {
		window->map->save_obstacle =
		save_obs(window->map->level[window->status_game->level]);
		window->map->obstacle = save_obs(window->map->save_obstacle);
	} else {
		window->map->obstacle = save_obs(window->map->save_obstacle);
	}
	window->mouse.x = 0;
	window->mouse.y = 0;
	return(window);
}

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
	status_game->level = 0;
	return(status_game);
}

int *save_obs(int *obstacle)
{
	int *new = malloc(sizeof(int) * obstacle[0]);

	new[0] = obstacle[0];
	for(int i = 1; i <= obstacle[0]; i ++) {
		new[i] = obstacle[i];
	}
	return (new);
}
