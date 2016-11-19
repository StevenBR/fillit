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
	//tetris pieces will have all of the characters until we us ft_trim_newline
	while(*str && (tetri = (char *)malloc(sizeof(char) * 21)) && !(count = 0))
	{
		*(tetri + (20)) = '\0';
		while ((count < 20) && (*str))
			*(tetri + count++) = *(str++);
		//ft_trim_newline returns char *, we use the functions return in the list.
		ft_list_push_back(list, ft_trim_newline(tetri));
		str++;
	}
}

void file_read_create(char *file_name, t_list **list)
{
	char buffer[546];
	ft_memset(buffer, '\0', 546);
	int fd;
	int blocks_read;
	
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return ft_putstr("Open file:  ERROR");
	blocks_read = read(fd, buffer, 546) ;
	if (!(blocks_read % 21))
		create_tetris_list(buffer, list, blocks_read);
	else
		ft_putstr("Read file:  ERROR\n");
	close(fd);
}
