/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:49:34 by srodrigu          #+#    #+#             */
/*   Updated: 2016/11/18 23:06:43 by srodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"
#include "./headers/libft.h"


// void create_tetris_list(char *buffer, t_list **list, int chars_read)
// {
// 	int count;
	
//   	//ft_putnbr(nbr_pieces);
//   	write(1, "\n", 1);
// 	//tetris pieces will have all of the characters until we us ft_trim_newline

// 		//ft_trim_newline returns char *, we use the functions return in the list.
		
// 	}
// }

int	validate_tertrimino(t_list *list)
{
	int idx;
	t_list *curr;

	curr = list;
	while (curr)
	{
		if (ft_strcmp(curr->data, g_tetriminos[i]) != 0)
			return (0);
		curr = list->next;
	}
	return (1);
}

int		valid_file(char *buffer, int chars_read)
{
	while (chars_read > 0)
	{
		return (buffer[chars_read - 1] != '#' || buffer[chars_read - 1] != '.'
		|| buffer[chars_read - 1] != '\n' || buffer[chars_read - 1] != '\0')
		chars_read--;
	}
}

void file_read_create(char *file_name, t_list **list) //can't do % 21 because the
// last tetrimino ends with \0
{
	char buffer[546];
	ft_memset(buffer, '\0', 546);
	int fd;
	int chars_read;
	int store;
	
	chars_read = 21;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return ft_putstr("Open file:  ERROR");
	while ((chars_read = read(fd, buffer, 21))) //read 1 tetrimino at a time
	{
		if ((chars_read == 21 || chars_read == 20) && valid_file(buffer, 21) == 0)
			ft_list_push_back(list, ft_strndup(buffer, chars_read));
		// create_tetris_list(buffer, list, chars_read);
	}
	else
		ft_putstr("Read file:  ERROR\n");
	close(fd);
}
