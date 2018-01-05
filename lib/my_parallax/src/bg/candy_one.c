/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <my_parallax.h>

void add_candy_one1_2(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;

	tmp = add_to_chain_parallax(window, "./parallax/candy_one/1/3.png"
	, CANDY_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.01;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/1/4.png"
	, CANDY_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.02;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/1/5.png"
	, CANDY_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.03;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/1/6.png"
	, CANDY_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.05;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/1/7.png",
	 CANDY_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.01;
}

void add_candy_one_1(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;

	tmp = add_to_chain_parallax(window, "./parallax/candy_one/1/1.png"
	, CANDY_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = 0;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/1/2.png"
	, CANDY_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.001;
	add_candy_one1_2(window);
}
