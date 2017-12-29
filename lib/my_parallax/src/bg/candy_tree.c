/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <my_parallax.h>

void add_candy_tree1_2(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;

	tmp = add_to_chain_parallax(window, "./parallax/candy_one/3/2.png", CANDY_TREE
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.01;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/3/3.png", CANDY_TREE
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.02;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/3/4.png", CANDY_TREE
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.03;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/3/5.png", CANDY_TREE
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.05;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/3/6.png", CANDY_TREE
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.1;
}

void add_candy_tree(t_my_parallax *window)
{
	t_my_parallax_obj *tmp;

	tmp = add_to_chain_parallax(window, "./parallax/candy_one/3/1.png", CANDY_TREE
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = 0;
	tmp = add_to_chain_parallax(window, "./parallax/candy_one/3/1_5.png", CANDY_TREE
	, (sfIntRect){0,0,1920,1080});
	tmp->vitesse.x = -0.005;
	add_candy_tree1_2(window);
}
