/*
** EPITECH PROJECT, 2022
** biggest square
** File description:
** biggest_square
*/

#ifndef BIGGEST_SQUARE_H_
    #define BIGGEST_SQUARE_H_
    #include <sys/stat.h>

    typedef struct values_struct_s {
        int v1;
        int v2;
        int v3;
    } values_struct_t;

    typedef struct biggest_square_s {
        int coord_x;
        int coord_y;
        int bsq_v;
    } biggest_square_t;

    typedef struct map_size_s {
        int size_x;
        int size_y;
    } map_size_t;

    // BSQ main file
    int buffer_creator(int fd, struct stat *file_stats);
    int map_creator(char const *buffer);

    // BSQ map checker
    int map_validity(char **map, int size);
    int map_check_char(char **map);
    int map_check_linesize(char **map);
    int map_check_size(char **map, int size);

    // BSQ map generator
    int map_generator(int size, char *pattern, char *size_char);
    int char_chooser(int x, int y, char *pattern);

    // BSQ map process
    int bsq(char **map);
    int indicator_append(char **map, values_struct_t *values, int x, int y);
    // void map_loop
    void map_display(int **v, biggest_square_t bsq_i, int x, char **map);

    // BSQ ranges
    int range_ofy(int y, biggest_square_t bsq_i);
    int range_ofx(int x, biggest_square_t bsq_i);

    // BSQ struct update
    void st_bsqi_update(int **v, int x, int y, biggest_square_t *bsq_i);
    void st_value_update(int **v, int x, int y, values_struct_t *values);

    // Default func 1
    int my_putchar(char c);
    int my_strlen(char const *str);
    int my_putstr(char const *str);
    int min_value(int a, int b, int c);
    int my_getnbr(char const *str);

    // Default func 2
    int is_validstr(char const *str);
    int is_token(char const c, char const *const tokens);
    int is_strnum(char const *str);
    char **my_str_to_word_array(char const *str);
    char *my_strdup(char const *str);

    // Default func 3
    int count_backslash(char const *str);

#endif /* !BIGGEST_SQUARE_H_ */
