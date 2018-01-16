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

t_win *game_loop(t_win *window)
{
	t_my_parallax *parallax = my_parallax_init(200, window->window);

	set_speed_map(window->map, 10);
	while (window->status_game->game == 1) {
		window->time = sfClock_getElapsedTime(window->clock);
		window->seconds = window->time.microseconds / 1000000.0;
		if (window->seconds > 0.02) {
			sfClock_restart(window->clock);
			moove_character_sprite(window);
			window->status_game->score += 1;
		}
		my_parallax(parallax, window->map->parallax);
		display_map(window->map, window);
		master_event(window);
		display_character(window);
		get_instruction(window);
		sfRenderWindow_display(window->window);
	}
	return(window);
}

t_win *master_window(t_win *window)
{

	sfRenderWindow_display(window->window);
	sfRenderWindow_setFramerateLimit(window->window, 60);
	while (sfRenderWindow_isOpen(window->window)) {
		menu(window);
		game_loop(window);
		finish(window);
		if(window->status_game->exit == 1)
			return(0);
		re_window(window);
	}
	return (window);
}

int verify(char ** argv, int argc)
{
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'L')
		return (1);
	if (argc == 2 && argv[1][0] != '-')
		return (0);
	return(0);
}

int main(int argc, char **argv)
{
	t_win *window;
	int level_activate;

	if(argc == 1){
		put_str("./my_runner:     bad argument: 0 given but 1 is required\n");
		put_str("retry whith -h\n");
		return(84);
	}
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
		write_h();
	level_activate = verify(argv, argc);
	window = init_window(argv[1], level_activate);
	while (1) {
		master_window(window);
		get_instruction(window);
		sfRenderWindow_destroy(window->window);
		destroy(window);
		if(window->status_game->exit == 1)
			return(0);
	}
}
