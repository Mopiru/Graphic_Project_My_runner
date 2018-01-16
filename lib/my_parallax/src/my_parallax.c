/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <my_parallax.h>

void add_all_parallax(t_my_parallax *window)
{
	add_candy_one_1(window);
	add_candy_two_1(window);
	add_candy_tree(window);
	add_candy_four(window);
	add_candy_five(window);
	add_candy_six(window);
	add_candy_seven(window);
	add_candy_height(window);

}

t_my_parallax *my_parallax_init(int vitesse, sfRenderWindow *window)
{
	t_my_parallax_obj *tmp;
	t_my_parallax *temp;

	temp = malloc(sizeof(t_my_parallax));
	temp->head = NULL;
	temp->window = window;
	temp->vitesse = vitesse;
	tmp = init_chain_parallax(temp, "./parallax/desert_one/9.png", DESERT_ONE
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = 0;
	add_all_parallax(temp);
	return (temp);
}

t_my_parallax_obj *cond_pos(t_my_parallax_obj *temp, t_my_parallax *parallax, t_my_parallax_type type)
{
	sfVector2f pos_save = temp->pos;

	if (temp->type == type) {
		temp->pos.x += temp->vitesse.x * parallax->vitesse;
		if (temp->pos.x <= -1920)
			temp->pos.x = 0;
		sfSprite_setPosition(temp->sprite, temp->pos);
		sfRenderWindow_drawSprite(parallax->window, temp->sprite, NULL);
		pos_save.x = 1920 + temp->pos.x;
		sfSprite_setPosition(temp->sprite, pos_save);
		sfRenderWindow_drawSprite(parallax->window, temp->sprite, NULL);
	}
	return (temp);
}

t_my_parallax *set_speed_parallax(t_my_parallax *parallax, int vitesse)
{
	parallax->vitesse = vitesse;
	return(parallax);
}

t_my_parallax *my_parallax(t_my_parallax *parallax, t_my_parallax_type type)
{

	t_my_parallax_obj *temp = parallax->head;
	while (temp != NULL) {
		cond_pos(temp, parallax, type);
		temp = temp->next;
;}
	return (parallax);
}
