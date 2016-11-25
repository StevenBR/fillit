/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pre_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:50:39 by srodrigu          #+#    #+#             */
/*   Updated: 2016/11/18 23:27:07 by srodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"
#include "tetri-all.c"

char *copy_lst_content(t_list *list, char **fourbyfourboard)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (list->data)
	{
		while (y <= 3)
		{
			while (x <= 3)
			{
				if (data == "#")
					ft_strcpy((fourbyfourboard[y][x]), data[x])
				x++;
			}
			y++;
		}
	}
}

char **create_initial_board(void)
{
	char **fourbyfourboard;
	char *rows;
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(fourbyfourboard = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	while (y <= 3)
	{
		while (x < 4)
		{
			if (!(rows = (char *)malloc(sizeof(char) * 5)))
				return (0);
			rows[x] = '.';
			ft_putchar(rows[x]);
			if (x == 3)
			{
				rows[x] = '\n';
				ft_putchar(rows[x]);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (fourbyfourboard);
}


char **first_piece_on_board(t_list *list)
{
	char **fourbyfourboard;
	char *rows;
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(fourbyfourboard = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	while (y <= 3)
	{
		while (x < 4)
		{
			if (!(rows = (char *)malloc(sizeof(char) * 5)))
				return (0);
			rows[x] = '.';
			ft_putchar(rows[x]);
			if (x == 3)
			{
				rows[x] = '\n';
				ft_putchar(rows[x]);
			}
			x++;
		}
		x = 0;
		y++;
	}

	return (fourbyfourboard);
}
