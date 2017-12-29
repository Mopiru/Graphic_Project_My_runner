/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

char *my_strcat(char *str1, char *str2)
{
	int len = my_strlen(str1) + my_strlen(str2) + 1;
	int i = 0;
	int j = 0;
	char *result = malloc(sizeof(char) * len);

	while (str1[i] != '\0') {
		result[i] = str1[i];
		i ++;
	}
	while (str2[j] != '\0') {
		result[i] = str2[j];
		i ++;
		j ++;
	}
	result[i] = '\0';
	return (result);
}

char *my_read(char *path)
{
	int size = 4096;
	char *buffer = malloc(sizeof(char) * size);
	char *map = malloc(sizeof(char));
	int fd = open(path, O_RDONLY);
	int rd = read(fd, buffer, size - 1);

	if (read(fd, buffer, size - 1) == -1) {
		exit (84);
	}
	map[0] = '\0';
	while (rd > 0) {
		buffer[rd] = '\0';
		map = my_strcat(map, buffer);
		rd = read(fd, buffer, size - 1);
	}
	free(buffer);
	return (map);
}

t_map *get_map(char *pathname)
{
	t_map *map = malloc(sizeof(t_map));

	map->map = my_read(pathname);
	printf("%s\n", map->map);
	return(map);
}
