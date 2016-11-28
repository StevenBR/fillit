#ifndef _FILLIT_H

# define _FILLIT_H
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "list.h"
#include <stdio.h>

typedef enum {
	t0,
	t1,
	t2,
	t3,
	t4,
	t5,
	t6,
	t7,
	t8,
	t9,
	t10,
	t11,
	t12,
	t13,
	t14,
	t15,
	t16,
	t17,
	t18,
} termo;



typedef struct	s_pos
{
	int row;
	int col;
}				t_pos;

// int g_inbetween[19][3] = {
// 	{0, 0, 0},
// 	{4, 4, 4},
// 	{0, 2, 0},
// 	{4, 0, 4},
// 	{0, 4, 0},
// 	{3, 0, 3},
// 	{0, 3, 0},
// 	{4, 3, 0},
// 	{4, 0, 0},
// 	{0, 0, 4},
// 	{0, 3, 4},
// 	{3, 0, 0},
// 	{4, 0, 3},
// 	{0, 0, 3},
// 	{3, 0, 4},
// 	{4, 4, 0},
// 	{0, 0, 2},
// 	{0, 4, 4},
// 	{2, 0, 0}
// };

void 	file_read_create(char *file_name, t_list **list);
char **convert_1d_to_2d(char *tetrimino1d);
void shift_tetrimino(char **tetrimino);
int		valid_file(char *buffer, int chars_read);
int		*chars_between_hashes(t_list *list);
int	is_valid_tetrimino(char **tetrimino);
char **create_board(int size);
int		can_place(char **tetrimino, char **board, int size, t_pos pos);
char **place_tet(char **tetrimino, char **board, int size);
char			*ft_strndup(char *s, size_t n);
void print_map(char **board, int size);
char **size_map(int size, int num_tets);
int	solve(char **tetrimino, char **board, int size, t_pos pos, int num_tets);

#endif