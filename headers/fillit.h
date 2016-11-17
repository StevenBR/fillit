#ifndef _FILLIT_H

# define _FILLIT_H
#include <unistd.h>
#include <fcntl.h>
#include "list.h"
#include "libft.h"

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

void file_read_create(char *file_name, t_list **list);
//void create_tetris_list(char *str, t_list **list);
void create_tetris_list(char *str, t_list **list, int nbr_pieces);
int list_is_valid(t_list *list);

#endif