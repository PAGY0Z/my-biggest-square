/*
** EPITECH PROJECT, 2022
** B-CPE-110-RUN-1-1-BSQ-pierre-alexandre.grosset
** File description:
** bsq_main_file
*/

#include "biggest_square.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int check_lastchar(char const *buffer)
{
    int i = 0;
    while (buffer[i] != '\0') {
        i++;
    }
    if (buffer[i - 1] != '\n')
        return 0;
    return 1;
}

int map_creator(char const *buffer)
{
    int value = 0;
    int size = my_getnbr(buffer);
    if (size == -1 || size == 0)
        return 84;
    if (check_lastchar(buffer) == 0) {
        return 84;
    }
    char **map = my_str_to_word_array(buffer);
    if (map == NULL)
        return 84;
    if (map_validity(map, size) == 0)
        bsq(map);
    else
        value = 84;
    for (int x = 0; x < size + 2; x++) {
        free(map[x]);
    }
    free(map);
    return value;
}

int buffer_creator(int fd, struct stat *file_stats)
{
    int value = 0;
    if (file_stats->st_size < 4)
        return 84;
    char *buffer = malloc(sizeof(char) * (file_stats->st_size + 1));
    read(fd, buffer, file_stats->st_size);
    buffer[file_stats->st_size] = '\0';
    value = map_creator(buffer);
    free(buffer);
    return value;
}

int main(int argc, char **argv)
{
    struct stat file_stats;
    int fd;
    int value = 0;
    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
            return 84;
        stat(argv[1], &file_stats);
        value = buffer_creator(fd, &file_stats);
        close(fd);
        return value;
    }
    return 84;
}
