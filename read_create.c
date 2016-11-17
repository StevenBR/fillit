/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:49:34 by srodrigu          #+#    #+#             */
/*   Updated: 2016/11/16 19:43:08 by srodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"

//int is_validchar()
//{
//	
//}

void create_tetris_list(char *str, t_list **list, int nbr_pieces)
{
	int count;
	char *tetri;
	
  	ft_putnbr(nbr_pieces);
	while(*str && (tetri = (char *)malloc(sizeof(char) * 21)) && !(count = 0))
	{
		*(tetri + (20)) = '\0';
		while ((count < 20) && (*str))
			*(tetri + count++) = *(str++);
		ft_list_push_back(list, tetri);
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
