/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

void add_candy(t_map *map)
{
	add_to_chain_map(map, "./asset/map_candy/sq_candy_two.png", SQ_CANDY_TWO
	, (sfIntRect){0,0,70,60});
	add_to_chain_map(map, "./asset/map_candy/sq_candy_three.png", SQ_CANDY_THREE
	, (sfIntRect){0,0,70,60});
	add_to_chain_map(map, "./asset/map_candy/sq_candy_four.png", SQ_CANDY_FOUR
	, (sfIntRect){0,0,70,60});
	add_to_chain_map(map, "./asset/map_candy/sq_space.png", SQ_CANDY_SPACE
	, (sfIntRect){0,0,70,60});
}

void set_asset(t_map *map)
{
	init_chain_map(map, "./asset/map_candy/sq_candy_one.png", SQ_CANDY_ONE
	, (sfIntRect){0,0,70,60});
	add_candy(map);
}

int len_str(char *str)
{
	int i = 0;

	while (str[i] != '\n') {
		i ++;
	}
	return (i + 1);
}

t_map *set_speed_map(t_map *map, int vitesse)
{
	map->vitesse = vitesse;
	return(map);
}
