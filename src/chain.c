/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <my.h>

t_obj *init_chain_map(t_map *map, char *path_name, t_type_obst type
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

t_obj *add_to_chain_map(t_map *map, char *path_name, t_type_obst type
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

t_obj_character *init_chain_character(t_character *character, char *path_name, t_type_character type
, sfIntRect init_rect)
{
	character->head = malloc(sizeof(t_obj_character));
	character->head->sprite = sfSprite_create();
	character->head->texture = sfTexture_createFromFile(path_name, NULL);
	sfSprite_setTexture(character->head->sprite, character->head->texture
	, sfTrue);
	character->head->pos = (sfVector2f){0,0};
	character->head->vitesse = (sfVector2f){0,0};
	character->head->rect = init_rect;
	character->head->type = type;
	character->head->next = NULL;
	return(character->head);
}

t_obj_character *add_to_chain_character(t_character *character, char *path_name, t_type_character type
, sfIntRect init_rect)
{
	t_obj_character *new = malloc(sizeof(t_obj_character));
	t_obj_character *save = character->head;

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

t_obj *init_chain(t_win *window, char *path_name, t_type_obj type
, sfIntRect init_rect)
{
	window->head = malloc(sizeof(t_obj));
	window->head->sprite = sfSprite_create();
	window->head->texture = sfTexture_createFromFile(path_name, NULL);
	sfSprite_setTexture(window->head->sprite, window->head->texture
	, sfTrue);
	window->head->pos = (sfVector2f){0,0};
	window->head->vitesse = (sfVector2f){0,0};
	window->head->rect = init_rect;
	window->head->type_wall = type;
	sfSprite_setTextureRect(window->head->sprite, window->head->rect);
	sfSprite_setPosition(window->head->sprite, window->head->pos);
	window->head->next = NULL;
	return(window->head);
}
