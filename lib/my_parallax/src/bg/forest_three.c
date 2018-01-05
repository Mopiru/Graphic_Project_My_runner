/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <my_parallax.h>

void add_forest_three2(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;

	tmp = add_to_chain_parallax(window, "./parallax/forest/3/5.png"
	, FOREST_THREE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.01;
	tmp = add_to_chain_parallax(window, "./parallax/forest/3/4.png"
	, FOREST_THREE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.02;
	tmp = add_to_chain_parallax(window, "./parallax/forest/3/3.png"
	, FOREST_THREE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.03;
	tmp = add_to_chain_parallax(window, "./parallax/forest/3/2.png"
	, FOREST_THREE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.05;
	tmp = add_to_chain_parallax(window, "./parallax/forest/3/1.png"
	, FOREST_THREE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.1;
}

void add_forest_three(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;

	tmp = add_to_chain_parallax(window, "./parallax/forest/3/7.png"
	, FOREST_THREE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = 0;
	tmp = add_to_chain_parallax(window, "./parallax/forest/3/6.png"
	, FOREST_THREE, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.001;
	add_forest_three2(window);
}
