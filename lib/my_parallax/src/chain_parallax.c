/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <my_parallax.h>

t_my_parallax_obj *init_chain_parallax(t_my_parallax *window, char *path_name, t_my_parallax_type type
, sfIntRect inti_rect)
{
	window->head = malloc(sizeof(t_my_parallax_obj));
	window->head->sprite = sfSprite_create();
	window->head->texture = sfTexture_createFromFile(path_name, NULL);
	sfSprite_setTexture(window->head->sprite, window->head->texture
	, sfTrue);
	window->head->pos = (sfVector2f){0,0};
	window->head->vitesse = (sfVector2f){0,0};
	window->head->rect = inti_rect;
	window->head->type = type;
	window->head->next = NULL;
	return (window->head);
}

t_my_parallax_obj *add_to_chain_parallax(t_my_parallax *window, char *path_name, t_my_parallax_type type
, sfIntRect inti_rect)
{
	t_my_parallax_obj *new = malloc(sizeof(t_my_parallax_obj));
	t_my_parallax_obj *save = window->head;

	new->sprite = sfSprite_create();
	new->texture = sfTexture_createFromFile(path_name, NULL);
	sfSprite_setTexture(new->sprite, new->texture
	, sfTrue);
	new->pos = (sfVector2f){0,0};
	new->vitesse = (sfVector2f){0,0};
	new->rect = inti_rect;
	new->type = type;
	new->next = NULL;
	while (save != NULL && save->next != NULL) {
		save = save->next;
	}
	save->next = new;
	return (new);
}
