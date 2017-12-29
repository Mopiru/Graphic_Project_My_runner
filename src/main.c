/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

t_win *destroy(t_win *window)
{
	t_obj *temp = window->head;

	while (temp != NULL) {
		sfSprite_destroy(temp->sprite);
		sfTexture_destroy(temp->texture);
		temp = temp->next;
	}
	sfClock_destroy(window->clock);
	return (window);
}

t_obj *init_chain(t_win *window, char *path_name, t_type type
, sfIntRect inti_rect)
{
	window->head = malloc(sizeof(t_obj));
	window->head->sprite = sfSprite_create();
	window->head->texture = sfTexture_createFromFile(path_name, NULL);
	window->head->pos = (sfVector2f){0,0};
	window->head->vitesse = (sfVector2f){0,0};
	window->head->rect = inti_rect;
	window->head->type = type;
	window->head->next = NULL;
	return (window->head);
}

t_obj *add_to_chain(t_win *window, char *path_name, t_type type
, sfIntRect inti_rect)
{
	t_obj *new = malloc(sizeof(t_obj));
	t_obj *save = window->head;

	new->sprite = sfSprite_create();
	new->texture = sfTexture_createFromFile(path_name, NULL);
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



t_win *master_event(t_win *window)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtMouseButtonPressed) {
			window->mouse
			= sfMouse_getPosition((sfWindow*)window->window);
		}
	}
	return (window);
}

t_win *master_window(t_win *window)
{
	t_my_parallax *parallax = my_parallax_init(10, window->window);
	sfRenderWindow_display(window->window);
	while (sfRenderWindow_isOpen(window->window)) {
		window->time = sfClock_getElapsedTime(window->clock);
		window->seconds = window->time.microseconds / 1000000.0;
		if (window->seconds > 2) {
			sfClock_restart(window->clock);
		}
		my_parallax(parallax, 5);
		master_event(window);
		sfRenderWindow_display(window->window);
	}
	return (window);
}

int main(int argc, char **argv)
{
	t_win *window;
	sfVideoMode mode = {1920, 1080, 64};

	window = malloc(sizeof(t_win));
	window->head = NULL;
	window->window = sfRenderWindow_create(mode, "my_runner"
	, sfClose, NULL);
	window->clock = sfClock_create();
	window->map = get_map(argv[1]);
/*	while (1) {
		master_window(window);
		sfRenderWindow_destroy(window->window);
		destroy(window);
		return (0);
	}*/
	(void)argc;
}
