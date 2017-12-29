/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include <SFML/System/Time.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_parallax.h"

#ifndef __duck_hunt__
#define __duck_hunt__

typedef enum s_type
{
	BACKGROUND_DESERT,
	CHARACTER,
	OBSTACLE
} t_type;

typedef enum s_type_obst
{
	SQ_CANDY_ONE,
	SQ_CANDY_TWO,
	SQ_CANDY_THREE
} t_type_obst;

typedef struct s_obj
{
	t_type type;
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
	sfVector2f vitesse;
	sfIntRect rect;
	struct s_obj *next;
} t_obj;

typedef struct s_map
{
	int *obstacle;
	char *map;
	sfSprite *sprite;
	t_obj *head;
} t_map;

typedef struct s_win
{
	sfRenderWindow* window;
	sfTime time;
	sfEvent event;
	sfClock *clock;
	sfVector2i mouse;
	float seconds;
	t_map *map;
	t_obj *head;
} t_win;

t_map *get_map(char *pathname);
#endif
