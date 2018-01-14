/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

t_obj_character *next_sprite_character(t_obj_character *temp
, t_win *window)
{
	if (temp->type == window->status) {
		temp->rect.left += temp->weight;
		if (temp->rect.left >= temp->max_sprite)
			temp->rect.left = temp->weight;
	}
	return(temp);
}

sfVector2f moov_character2(t_obj_character *temp, t_win *window)
{
	switch (window->key->key2)
	{
		case -1:
			temp->pos.y += 20;
			window->key->key2 = 0;
			break;
		case 1:
			temp->pos.y -= 27;
			window->key->key2 = 0;
			break;
		default:
			break;
	}
	return(temp->pos);
}

sfVector2f moov_character(t_obj_character *temp, t_win *window)
{
	switch (window->key->key)
	{
		case 1:
			temp->pos.x += 15;
			window->key->key = 0;
			break;
		case 2:
			temp->pos.x -= 10;
			window->key->key = 0;
			break;
		default:
			break;
	}
	moov_character2(temp, window);
	return(temp->pos);
}

int black_block(sfVector2f pos, int type, t_obj_character *temp, t_win *window)
{
	if (type == 3) {
		if (temp->pos.y < pos.y
		&& temp->pos.y + temp->hight > pos.y
		&& temp->pos.x + temp->weight > pos.x
		&& temp->pos.x < pos.x) {
			init_end_game(window);
			window->status_game->win = -1;
			return(0);
		}
	}
	if (type == 4) {
		if (temp->pos.y < pos.y
		&& temp->pos.y + temp->hight > pos.y
		&& temp->pos.x + temp->weight > pos.x
		&& temp->pos.x < pos.x) {
			init_end_game(window);
			window->status_game->win = 1;
			return(0);
		}
	}
	return (0);
}

int check_block(int *obstacle, t_obj_character *temp, t_win *window)
{
	for(int i = 1; i < obstacle[0]; i += 3) {
		if (obstacle[i] > 0 && obstacle[i + 2] != 0){
			if ((temp->pos.y + temp->hight >= obstacle[i + 1])
			&& (temp->pos.x >= obstacle[i])
			&& (temp->pos.x <= obstacle[i] + 70)
			&& obstacle[i + 2] != 0) {
				return(1);
			}
		}
		black_block((sfVector2f){obstacle[i], obstacle[i + 1]}
		, obstacle[i + 2], temp, window);
	}
	if(temp->pos.x < -100 || temp->pos.y < -50) {
		window->status_game->game = 0;
		window->status_game->win = -1;
		window->status_game->finish_game = 1;
	}
	return(0);
}
