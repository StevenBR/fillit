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


void create_tetris_list(char *str, t_list **list, int nbr_pieces)
{
	int count;
	char *tetri;
	
  	ft_putnbr(nbr_pieces);
  	write(1, "\n", 1);
	//tetris pieces will have all of the characters until we us ft_trim_newline
	while(*str && (tetri 
		= (char *)malloc(sizeof(char) * 21)) && !(count = 0))
	{
		*(tetri + (20)) = '\0';
		while ((count < 20) && (*str))
			*(tetri + count++) = *(str++);
		//ft_trim_newline returns char *, we use the functions return in the list.
		ft_list_push_back(list, ft_trim_newline(tetri));
		str++;
	}
}

void	covert_to_tertrimino(char *buffer)
{
	char **store;

	store = (char **)malloc(sizeof(char *) * 4);

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

void file_read_create(char *file_name, t_list **list)
{
	char buffer[546];
	ft_memset(buffer, '\0', 546);
	int fd;
	int chars_read;
	
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return ft_putstr("Open file:  ERROR");
	chars_read = read(fd, buffer, 546);
	if (valid_file(buffer, chars_read) == 0)
	{
		create_tetris_list(buffer, list, blocks_read);
	}
	else
		ft_putstr("Read file:  ERROR\n");
	close(fd);
}
