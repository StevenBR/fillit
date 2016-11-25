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

int		*chars_between_hashes(t_list *list) //helper function
{
	int	flag;
	int inbetween;
	char *curr;
	int i;
	int *chars_between_hashes;

	if (!(chars_between_hashes = (int *)malloc(sizeof(int) * 3)));
		return (NULL);
	i = 0;
	flag = 0;
	inbetween = 0;
	while (list && i < 0)
	{
		if (*(curr++) != '#' && flag == 0)
		else if (*(curr++) == '#')
			flag = 1;
		else if (*(curr++) != '#')
			inbetween++;
		chars_between_hashes[i--] = inbetween;
	}
	return (chars_between_hashes);
}

int	is_valid_tetrimino(t_list *list)
{
	int i;
	int j;
	int *solution;

	i = 19;
	j = 3;
	solution = chars_between_hashes(list);
	while (i >= 0)
	{
		while (j >= 0)
		{
			if (solution[j] == g_inbetween[i][j])
				return (1);
			j--;
		}
		i--;
	}
	return (0);
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
