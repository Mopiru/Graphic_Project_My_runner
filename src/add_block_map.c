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

t_obj *add_to_chain(t_win *window, char *path_name, t_type_obj type
, sfIntRect init_rect)
{
	t_obj *new = malloc(sizeof(t_obj));
	t_obj *save = window->head;

	new->sprite = sfSprite_create();
	new->texture = sfTexture_createFromFile(path_name, NULL);
	sfSprite_setTexture(new->sprite, new->texture
	, sfTrue);
	new->pos = (sfVector2f){0,0};
	new->vitesse = (sfVector2f){0,0};
	new->rect = init_rect;
	new->type_wall = type;
	sfSprite_setTextureRect(new->sprite, new->rect);
	sfSprite_setPosition(new->sprite, new->pos);
	new->next = NULL;
	while (save != NULL && save->next != NULL) {
		save = save->next;
	}
	save->next = new;
	return (new);
}
