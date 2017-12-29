/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <my_parallax.h>

void add_candy_height_2(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;

	tmp = add_to_chain_parallax(window, "./parallax/candy_one/8/2.png", CANDY_HEIGHT
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.01;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/8/3.png", CANDY_HEIGHT
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.02;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/8/4.png", CANDY_HEIGHT
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.03;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/8/5.png", CANDY_HEIGHT
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.05;
}

void add_candy_height(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;

	tmp = add_to_chain_parallax(window, "./parallax/candy_one/8/1.png", CANDY_HEIGHT
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = 0;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/8/1_5.png", CANDY_HEIGHT
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.001;
	add_candy_height_2(window);
}
