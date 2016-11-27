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

int		can_place(char **tetrimino, char **board, int size, t_pos pos)
{
	int x;
	int y;
	int emptyspot;

	x = 0;
	y = 0;
	emptyspot = 0;
	size = board[x];
	while (y < 4)
	{
		while (x < 4)
		{
			if (tetrimino[y][x] == '#')
			{
				if (board[pos.row + y][pos.col + x] != '#')
					emptyspot++;
			}
			x++;
		}
		y++;
	}
	if (emptyspot == 4)
		return (1);
	return (0);
}

char *place_tet(char **tetrimino, char **board, int size)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < size)
	{
		while (x < size)
		{
			if (tetrimino[y][x] == '#')
				board[y][x] = '#';
			x++;
		}
		y++;
	}
}

char **create_board(int size)
{
	char **board;
	char *rows;
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(board = (char **)malloc(sizeof(char *) * size)))
		return (0);
	while (y <= size)
	{
		while (x < size)
		{
			if (!(rows = (char *)malloc(sizeof(char) * size)))
				return (0);
			rows[x] = '.';
			ft_putchar(rows[x]);
			x++;
		}
		x = 0;
		y++;
	}
	return (board);
}

/*
char **print_map(t_list *list, char **fourbyfourboard)
{
	int x;
	int y;

	while (fourbyfourboard[y] > 0)
	{
		ft_putstr(&fourbyfourboard[y]);
	}
}
*/