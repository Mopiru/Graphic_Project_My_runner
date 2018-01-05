/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <my_parallax.h>

void add_candy_five_2(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;

	tmp = add_to_chain_parallax(window, "./parallax/candy_one/5/2.png"
	, CANDY_FIVE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.01;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/5/3.png"
	, CANDY_FIVE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.02;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/5/4.png"
	, CANDY_FIVE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.03;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/5/5.png"
	, CANDY_FIVE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.05;
}

void add_candy_five(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;

	tmp = add_to_chain_parallax(window, "./parallax/candy_one/5/1.png"
	, CANDY_FIVE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = 0;
	add_candy_five_2(window);
}
