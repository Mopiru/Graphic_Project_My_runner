/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <my.h>

t_obj *init_chain(t_map *map, char *path_name, t_type_obst type
, sfIntRect init_rect)
{
	map->head = malloc(sizeof(t_obj));
	map->head->sprite = sfSprite_create();
	map->head->texture = sfTexture_createFromFile(path_name, NULL);
	sfSprite_setTexture(map->head->sprite, map->head->texture
	, sfTrue);
	map->head->pos = (sfVector2f){0,0};
	map->head->vitesse = (sfVector2f){0,0};
	map->head->rect = init_rect;
	map->head->type = type;
	map->head->next = NULL;
	return(map->head);
}

t_obj *add_to_chain(t_map *map, char *path_name, t_type_obst type
, sfIntRect init_rect)
{
	t_obj *new = malloc(sizeof(t_obj));
	t_obj *save = map->head;

	new->sprite = sfSprite_create();
	new->texture = sfTexture_createFromFile(path_name, NULL);
	sfSprite_setTexture(new->sprite, new->texture
	, sfTrue);
	new->pos = (sfVector2f){0,0};
	new->vitesse = (sfVector2f){0,0};
	new->rect = init_rect;
	new->type = type;
	new->next = NULL;
	while (save != NULL && save->next != NULL) {
		save = save->next;
	}
	save->next = new;
	return (new);
}
