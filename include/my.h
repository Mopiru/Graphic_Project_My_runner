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
#include <string.h>
#include "my_parallax.h"

#ifndef __duck_hunt__
#define __duck_hunt__

typedef enum s_type
{
	BACKGROUND_DESERT,
	CHARACTER,
	OBSTACLE
} t_type;

typedef enum s_type_obj
{
	ZERO,
	ONE,
	TWO,
	TREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	HEIGHT,
	NINE,
	START,
	PLAY,
	QUIT,
	DIE,
	TITLE,
	DEFEAT,
	MENU,
	WIN,
	SCORE
} t_type_obj;

typedef enum s_type_character
{
	RUN,
	JUMP
} t_type_character;

typedef enum s_type_obst
{
	SQ_CANDY_SPACE,
	SQ_CANDY_ONE,
	SQ_CANDY_TWO,
	SQ_CANDY_THREE,
	SQ_CANDY_FOUR
} t_type_obst;

typedef enum s_type_block
{
	DESERT,
	CANDY,
	FOREST
} t_type_block;

typedef struct s_manue
{
	int start;
	int quit;
} t_menu;

typedef struct s_obj
{
	t_type type;
	t_type_obj type_wall;
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
	int *save_obstacle;
	char *map;
	char *save;
	int parallax;
	int vitesse;
	int **level;
	sfVector2f pos;
	t_obj *head;
	t_type_block type_block;
} t_map;

typedef struct s_obj_character
{
	t_type_character type;
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
	sfVector2f vitesse;
	sfIntRect rect;
	int max_sprite;
	int weight;
	int hight;
	struct s_obj_character *next;
} t_obj_character;

typedef struct s_character
{
	t_obj_character *head;
	int vitesse;
	sfVector2f pos;
} t_character;

typedef struct s_get_key
{
	int key;
	int key2;
	int jump;
} t_get_key;

typedef struct s_status_game
{
	int menu;
	int game;
	int finish_game;
	int exit;
	long int score;
	int win;
	int level;
	int level_activate;

} t_status_game;

typedef struct s_win
{
	sfRenderWindow* window;
	sfTime time;
	sfEvent event;
	sfClock *clock;
	sfVector2i mouse;
	float seconds;
	t_get_key *key;
	t_map *map;
	t_type_character status;
	t_character *character;
	t_status_game *status_game;
	t_obj *head;
	t_menu *menu;
} t_win;

t_obj_character *init_chain_character(t_character *character, char *path_name, t_type_character type
, sfIntRect init_rect);
t_obj_character *next_sprite_character(t_obj_character *temp
, t_win *window);
void print_score(t_win *window);
t_win *re_window(t_win *window);
t_win *master_event(t_win *window);
t_menu *create_menu(void);
void add_button_quit(t_win *window);
t_status_game *init_status_game(void);
void add_button_play(t_win *window);
void put_str(char *str);
void number_font(t_win *window);
t_win *menu(t_win *window);
int *save_obs(int *obstacle);
void write_h(void);
void status_game_menue(t_win *window);
void status_game_retry(t_win *window);
void init_end_game(t_win *window);
t_win *init_window(char *map, int level_activate);
sfVector2f moov_character(t_obj_character *temp, t_win *window);
int check_block(int *obstacle, t_obj_character *temp, t_win *window);
t_get_key *init_key();
t_win *master_window(t_win *window);
void init_wall(t_win *window);
t_obj *add_to_chain(t_win *window, char *path_name, t_type_obj type
, sfIntRect init_rect);
t_obj *init_chain(t_win *window, char *path_name, t_type_obj type
, sfIntRect init_rect);
t_win *display_character(t_win *window);
void set_asset(t_map *map);
int len_str(char *str);
char *my_read(char *path);
t_win *finish(t_win *window);
t_win *get_instruction(t_win *window);
t_character *init_character(void);
t_win *moove_character_sprite(t_win *window);
t_map *get_map(char *pathname, int level_activate);
t_obj *init_chain_map(t_map *map, char *path_name, t_type_obst type
, sfIntRect inti_rect);
t_obj *add_to_chain_map(t_map *map, char *path_name, t_type_obst type
, sfIntRect inti_rect);
t_map *set_speed_map(t_map *map, int vitesse);
t_map *display_map(t_map *map, t_win *window);
t_obj_character *add_to_chain_character(t_character *character, char *path_name, t_type_character type
, sfIntRect init_rect);
#endif
