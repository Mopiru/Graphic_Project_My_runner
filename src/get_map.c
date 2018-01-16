/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

t_type_block get_block(int parallax)
{
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

int *get_pos_map(char *map)
{
	int *pos = malloc(sizeof(int) * ((strlen(map) * 3) + 1));
	int y = 0;
	int x = 0;
	int i = 1;

	pos[0] = (strlen(map) * 3)  + 1;
	for(int k = 0; map[k] != '\0'; k ++) {
		pos[i] = x * 70;
		pos[i + 1] = y;
		if (map[k] == ' ')
			pos[i + 2] = 0;
		else if (map[k] == '\n') {
			pos[i + 2] = 0;
			x = -1;
			y += 60;
		} else
			pos[i + 2] = map[k] - '0';
		x ++;
		i += 3;
	}
	return(pos);
}

int **get_level(t_map *map)
{
	int **level = malloc(sizeof(int *) * 5);

	map->map = my_read("./map/map_1");
	map->map = get_info(map);
	level[0] = get_pos_map(map->map);
	free(map->map);
	map->map = my_read("./map/map_2");
	map->map = get_info(map);
	level[1] = get_pos_map(map->map);
	free(map->map);
	map->map = my_read("./map/map_3");
	map->map = get_info(map);
	level[2] = get_pos_map(map->map);
	free(map->map);
	map->map = my_read("./map/map_4");
	map->map = get_info(map);
	level[3] = get_pos_map(map->map);
	free(map->map);
	return(level);
}

t_map *get_map(char *pathname, int level_activate)
{
	t_map *map = malloc(sizeof(t_map));

	if (level_activate == 1) {
		map->level = get_level(map);
		map->obstacle = save_obs(map->level[0]);
		map->save_obstacle = save_obs(map->level[0]);
	}else{
		map->map = my_read(pathname);
		map->map = get_info(map);
		map->obstacle = get_pos_map(map->map);
		map->save_obstacle = save_obs(map->obstacle);
	}
	map->vitesse = 2;
	map->head = NULL;
	map->head = malloc(sizeof(t_obj));
	set_asset(map);
	return(map);
}
