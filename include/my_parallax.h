/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Network.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

#ifndef __my_parallax__
#define __my_parallax__

typedef enum s_my_parallax_type
{
	DESERT_ONE,
	DESERT_TWO,
	CANDY_ONE,
	CANDY_TWO,
	CANDY_TREE,
	CANDY_FOUR,
	CANDY_FIVE,
	CANDY_SIX,
	CANDY_SEVEN,
	CANDY_HEIGHT,
	FOREST_ONE,
	FOREST_TWO,
	FOREST_THREE,
	FOREST_FOUR
} t_my_parallax_type;

typedef struct s_my_parallax_obj
{
	t_my_parallax_type type;
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
	sfVector2f vitesse;
	sfIntRect rect;
	struct s_my_parallax_obj *next;
} t_my_parallax_obj;

typedef struct s_my_parallax
{
	sfRenderWindow* window;
	t_my_parallax_obj *head;
	int vitesse;
} t_my_parallax;

t_my_parallax_obj *add_to_chain_parallax(t_my_parallax *window, char *path_name,
	t_my_parallax_type type, sfIntRect inti_rect);
t_my_parallax_obj *init_chain_parallax(t_my_parallax *window, char *path_name
, t_my_parallax_type type, sfIntRect inti_rect);
t_my_parallax *set_speed_parallax(t_my_parallax *parallax, int vitesse);
t_my_parallax *my_parallax_init(int vitesse, sfRenderWindow *window);
t_my_parallax *my_parallax(t_my_parallax *parallax, t_my_parallax_type type);
void add_desert_two(t_my_parallax *window);
void add_desert_one(t_my_parallax *window);
void add_candy_one_1(t_my_parallax *window);
void add_candy_two_1(t_my_parallax *window);
void add_candy_tree(t_my_parallax *window);
void add_candy_four(t_my_parallax *window);
void add_candy_five(t_my_parallax *window);
void add_candy_six(t_my_parallax *window);
void add_candy_seven(t_my_parallax *window);
void add_candy_height(t_my_parallax *window);
void add_forest_one(t_my_parallax *window);
void add_forest_two(t_my_parallax *window);
void add_forest_three(t_my_parallax *window);
void add_forest_four(t_my_parallax *window);
#endif
