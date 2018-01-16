/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <my.h>

void status_game_menue(t_win *window)
{
	window->status_game->exit = 0;
	window->status_game->score = 0;
	window->status_game->menu = 1;
	window->status_game->finish_game = 0;
	window->status_game->game = 0;
	window->status_game->win = 0;
}

void status_game_retry(t_win *window)
{
	window->status_game->finish_game = 0;
	window->status_game->game = 1;
	window->status_game->win = 0;
	window->status_game->level = 0;
	window->status_game->score = 0;
}
