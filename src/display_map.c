/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

t_obj *cond_pos_map(t_obj *temp, t_win *window, t_type type, t_map *map)
{
	if (temp->type == type) {
		sfSprite_setPosition(temp->sprite, map->pos);
		sfRenderWindow_drawSprite(window->window, temp->sprite, NULL);
	}
	return (temp);
}

t_map *set_block_sprite(t_type_obst type, t_map *map, t_win *window)
{
	t_obj *temp = map->head;

	while (temp != NULL) {
		cond_pos_map(temp, window, type, map);
		temp = temp->next;
;}
	return(map);
}
t_map *which_block_candy(t_map *map, int type, t_win *window)
{
	switch (type)
	{
		case 1:
			set_block_sprite(SQ_CANDY_ONE, map, window);
			break;
		case 2:
			set_block_sprite(SQ_CANDY_TWO, map, window);
			break;
		case 3:
			set_block_sprite(SQ_CANDY_THREE, map, window);
			break;
		case 4:
			set_block_sprite(SQ_CANDY_FOUR, map, window);
			break;
		default:
			set_block_sprite(SQ_CANDY_SPACE, map, window);
			break;
	}
	return(map);
}

t_map *set_sprite_candy(t_map *map, t_win *window)
{
	int type = 0;

	for(int i = 1; i < map->obstacle[0]; i += 3) {
		type = map->obstacle[i + 2];
		map->pos.x = map->obstacle[i];
		map->pos.y = map->obstacle[i + 1];
		which_block_candy(map, type, window);
		map->obstacle[i] -= map->vitesse;
	}
	return(map);
}

t_map *display_map(t_map *map, t_win *window)
{
	switch (map->type_block)
	{
		case DESERT:
			break;
		case CANDY:
			set_sprite_candy(map, window);
			break;
		case FOREST:
			break;
		default:
			break;
	}
	return(map);
}
