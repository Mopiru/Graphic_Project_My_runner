/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <my_parallax.h>

void add_desert2(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;


	tmp = add_to_chain_parallax(window, "./parallax/desert_one/4.png"
	, DESERT_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.2;
	tmp = add_to_chain_parallax(window, "./parallax/desert_one/3.png"
	, DESERT_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.3;
	tmp = add_to_chain_parallax(window, "./parallax/desert_one/2.png"
	, DESERT_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.4;
	tmp = add_to_chain_parallax(window, "./parallax/desert_one/1.png"
	, DESERT_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.5;
}

void add_desert_one(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;

	tmp = add_to_chain_parallax(window, "./parallax/desert_one/9.png"
	, DESERT_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = 0;
	tmp = add_to_chain_parallax(window, "./parallax/desert_one/8.png"
	, DESERT_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.001;
	tmp = add_to_chain_parallax(window, "./parallax/desert_one/7.png"
	, DESERT_ONE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.001;
	tmp = add_to_chain_parallax(window, "./parallax/desert_one/6.png", DESERT_ONE
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0;
	tmp = add_to_chain_parallax(window, "./parallax/desert_one/5.png", DESERT_ONE
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.1;
	add_desert2(window);
}
