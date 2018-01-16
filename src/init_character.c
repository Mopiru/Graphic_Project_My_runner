/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

void add_character(t_character *character)
{
	t_obj_character *temp;

	temp = init_chain_character(character, "./asset/santa/santa_1/run.png"
	, RUN, (sfIntRect){0,0,85,170});
	temp->max_sprite = 1870;
	temp->weight = 85;
	temp->hight = 160;
	temp = add_to_chain_character(character
	, "./asset/santa/santa_1/jump.png", JUMP, (sfIntRect){0,0,85,170});
	temp->max_sprite = 1700;
	temp->weight = 85;
}

t_character *init_character(void)
{
	t_character *character = malloc(sizeof(character));
	add_character(character);
	return(character);
}

t_win *moove_character_sprite(t_win *window)
{
	t_obj_character *temp = window->character->head;

	while(temp != NULL) {
		next_sprite_character(temp, window);
		temp = temp->next;
	}
	return(window);
}

sfVector2f pos_character(t_win *window, t_obj_character *temp)
{
	if(check_block(window->map->obstacle, temp, window) == 0
	&& window->key->jump == 0){
		temp->pos.y += 5;
	}
	if(window->key->key == 0 || window->key->jump != 0) {
		if(window->key->jump < 100 && window->key->jump != 0) {
			temp->pos.y -= 8;
			window->key->jump += 20;
		}else if(window->key->jump > 0) {
			window->key->jump = 0;
		}
	}
	moov_character(temp, window);
	return (temp->pos);
}

t_win *display_character(t_win *window)
{
	t_obj_character *temp = window->character->head;

	while(temp != NULL) {
		if (temp->type == window->status){
			sfSprite_setTextureRect(temp->sprite, temp->rect);
			temp->pos = pos_character(window, temp);
			sfSprite_setPosition(temp->sprite, temp->pos);
			sfRenderWindow_drawSprite(window->window, temp->sprite, NULL);
		}
		temp = temp->next;
	}
	return(window);
}
