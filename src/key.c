/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

t_get_key *init_key()
{
	t_get_key *key = malloc(sizeof(t_get_key));

	key->key = 0;
	key->jump = 0;
	return(key);
}

t_win *get_instruction_3(t_win *window)
{
	if(sfKeyboard_isKeyPressed(sfKeyEscape))
		window->status_game->exit = 1;
	return(window);
}

t_win *get_instruction_2(t_win *window)
{
	if(sfKeyboard_isKeyPressed(sfKeyRight))
		window->key->key = 1;
	else if(sfKeyboard_isKeyPressed(sfKeyLeft))
		window->key->key = 2;
	else if(sfKeyboard_isKeyPressed(sfKeyReturn))
		window->key->key = 3;
	return(window);
}

t_win *get_instruction(t_win *window)
{
	if(sfKeyboard_isKeyPressed(sfKeyUp))
		window->key->key2 = 1;
	else if(sfKeyboard_isKeyPressed(sfKeyDown))
		window->key->key2 = -1;
	else if(sfKeyboard_isKeyPressed(sfKeySpace)){
		window->key->key = 0;
		window->key->jump = 1;
	}
	get_instruction_2(window);
	get_instruction_3(window);
	return(window);
}
