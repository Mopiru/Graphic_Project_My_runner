/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

void add_candy(t_map *map)
{
	add_to_chain(map, "./asset/map_candy/sq_candy_two.png", SQ_CANDY_TWO
	, (sfIntRect){0,0,70,60});
	add_to_chain(map, "./asset/map_candy/sq_candy_three.png", SQ_CANDY_THREE
	, (sfIntRect){0,0,70,60});
	add_to_chain(map, "./asset/map_candy/sq_candy_four.png", SQ_CANDY_FOUR
	, (sfIntRect){0,0,70,60});
	add_to_chain(map, "./asset/map_candy/sq_space.png", SQ_CANDY_SPACE
	, (sfIntRect){0,0,70,60});
}

void set_asset(t_map *map)
{
	init_chain(map, "./asset/map_candy/sq_candy_one.png", SQ_CANDY_ONE
	, (sfIntRect){0,0,70,60});
	add_candy(map);
}

int len_str(char *str)
{
	int i = 0;

	while (str[i] != '\n') {
		i ++;
	}
	return (i + 1);
}

t_type_block get_block(int parallax)
{
	printf("info = %d \n", parallax);
	if (parallax == 0 || parallax == 1)
		return (0);
	if (parallax == 2 || parallax == 3 || parallax == 4 || parallax == 5
	|| parallax == 6 || parallax == 7 || parallax == 8 || parallax == 9)
		return(1);
	if ( parallax == 10 || parallax == 11 || parallax == 12
	|| parallax == 13)
		return (2);
	return(0);
}

char *get_info(t_map *map)
{
	int len = len_str(map->map);
	int here = 0;
	char *info = malloc(sizeof(char) * 2);

	info[1] = '\0';
	info[0] = map->map[0];
	map->parallax = atoi(info);
	free(info);
	map->type_block = get_block(map->parallax);
	for(int i = 0; map->map[i + len] != '\0'; i ++) {
		map->map[i] = map->map[i + len];
		here ++;
	}
	map->map[here] = '\0';
	return (map->map);
}

int next_line(void)
{
	static int  i = -60;

	i += 60;
	return(i);
}

int *get_pos_map(t_map *map)
{
	int *pos = malloc(sizeof(int) * ((strlen(map->map) * 3) + 1));
	int y = next_line();
	int x = 0;
	int i = 1;

	pos[0] = (strlen(map->map) * 3)  + 1;
	for(int k = 0; map->map[k] != '\0'; k ++) {
		pos[i] = x * 70;
		pos[i + 1] = y;
		if (map->map[k] == ' ')
			pos[i + 2] = 0;
		else if (map->map[k] == '\n') {
			pos[i + 2] = 0;
			x = -1;
			 y = next_line();
		}
		else
			pos[i + 2] = map->map[k] - '0';
		i += 3;
		x ++;
	}
	return(pos);
}

t_map *get_map(char *pathname)
{
	t_map *map = malloc(sizeof(t_map));

	map->map = my_read(pathname);
	map->vitesse = 2;
	map->map = get_info(map);
	map->head = NULL;
	map->head = malloc(sizeof(t_obj));
	set_asset(map);
	map->obstacle = get_pos_map(map);
	return(map);
}
