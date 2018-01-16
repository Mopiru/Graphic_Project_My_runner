/*
** EPITECH PROJECT, 2017
** epitech,project 2017 RN
** File description:
** epitech,project 2017 RN
*/
#include "my.h"

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i ++;
	}
	return (i);
}

void put_str(char *str)
{
	char c;

	for(int i = 0; str[i] != '\0'; i ++) {
		c = str[i];
		write(1, &c, 1);
	}
}

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

void write_h(void)
{
	put_str("runner created with CSFML.\n\n\n");
	put_str("USAGE:\n");
	put_str("./my_runner [FLAG] map.txt\n\n\n");
	put_str("FLAG:\n");
	put_str("-h		print the usage and quit.\n");
	put_str("-L		play with original map\n");
	put_str("WARNING! If you use -L dont put map.txt in argument\n\n\n");
	put_str("USER INTERACTIONS:\n");
	put_str("SAPACE_KEY			smooth jump.\n");
	put_str("UP_KEY				go up quickly\n");
	put_str("UP_DOWN				go down quickly\n");
	put_str("UP_RIGHT			go right quickly\n");
	put_str("UP_LEFT				go left quickly\n\n\n");
	put_str("RULES:\n");
	put_str("Dont touch the black block\n");
	put_str("You can walk on white & brun & grey block\n");
	put_str("Touch the white block to finish the level\n\n");
}
