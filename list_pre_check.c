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


	// while (curr)
	// 	{
	// 		ft_putstr("Original map:\n");
	// 		print_map(board, size);
			
	// 		if (can_place(alltetriminos[0], board, size, pos) == 0)
	// 			size_map(size++, num_tets++);
	// 		// if (can_place(tetriminos[num_tets], board, size, pos) == 1)
	// 		// {
	// 		// 	place_tet(tetriminos[num_tets], board, size);
	// 		// }
	// 		curr = curr->next;
	// 	}

char **size_map(int size, int num_tets)
{
	char **board;

	while (size * size < 4 * (num_tets))
	 	size++;
	printf("2) size: %d\n", size);
	board = create_board(size);
	return (board);
}

int		can_place(char **tetrimino, char **board, int size, t_pos pos)
{
	int x;
	int y;
	int emptyspot;

	y = 0;
	emptyspot = 0;
	ft_putstr("printed map: \n");
	print_map(board, size);
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetrimino[y][x] == '#')
			{
				printf("Tetrimino[y][x]:  %c\n", tetrimino[y][x]);
				if (board[pos.row][pos.col] != '#')
				{
					printf("Number of emptyspots: %d\n", emptyspot);
					emptyspot++;
				}
			}
			x++;
		}
		y++;
	}
	if (emptyspot == 4)
		return (1);
	return (0);
}

char **place_tet(char **tetrimino, char **board, int size)
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
			ft_putstr(board[y]);
			x++;
		}
		y++;
	}
	return (board);
}

char **create_board(int size)
{
	char **board;
	int x;
	int y;

	y = 0;
	printf("Create board:\n");
	if (!(board = (char **)malloc(sizeof(char *) * size)))
		return (0);
	while (y < size)
	{	
		if (!(board[y] = (char *)malloc(sizeof(char) * size)))
			return (0);
		x = 0;
		while (x < size)
		{
			board[y][x] = '.';
			ft_putchar(board[y][x]);
			x++;
		}
		y++;
		ft_putchar('\n');
	}
	return (board);
}


void print_map(char **board, int size)
{
	int x;
	int y;

	y = 0;
	while (y <= size)
	{
		x = 0;
		while (x <= size)
		{
			ft_putchar(board[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	printf("x: %d\n", x);
	printf("y: %d\n", y);
}
