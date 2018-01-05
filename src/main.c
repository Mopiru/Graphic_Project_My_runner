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
		if (window->seconds > 5) {

		}
		//my_parallax(parallax, window->map->parallax);
		//display_map(window->map, window);
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
	while (1) {
		master_window(window);
		sfRenderWindow_destroy(window->window);
		destroy(window);
		return (0);
	}
	(void)argc;
}
