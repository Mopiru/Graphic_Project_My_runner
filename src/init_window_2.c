/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

void number_font(t_win *window)
{
	add_to_chain(window, "./asset/number/one.png", ONE
	, (sfIntRect){0,0,45,100});
	add_to_chain(window, "./asset/number/two.png", TWO
	, (sfIntRect){0,0,45,100});
	add_to_chain(window, "./asset/number/tree.png", TREE
	, (sfIntRect){0,0,45,100});
	add_to_chain(window, "./asset/number/four.png", FOUR
	, (sfIntRect){0,0,45,100});
	add_to_chain(window, "./asset/number/five.png", FIVE
	, (sfIntRect){0,0,45,100});
	add_to_chain(window, "./asset/number/six.png", SIX
	, (sfIntRect){0,0,45,100});
	add_to_chain(window, "./asset/number/seven.png", SEVEN
	, (sfIntRect){0,0,45,100});
	add_to_chain(window, "./asset/number/height.png", HEIGHT
	, (sfIntRect){0,0,45,100});
	add_to_chain(window, "./asset/number/nine.png", NINE
	, (sfIntRect){0,0,45,100});
	add_to_chain(window, "./asset/number/zero.png", ZERO
	, (sfIntRect){0,0,45,100});
}

void init_end_game(t_win *window)
{
	window->status_game->game = 0;
	window->status_game->finish_game = 1;
}
