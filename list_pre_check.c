/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pre_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:50:39 by srodrigu          #+#    #+#             */
/*   Updated: 2016/11/18 22:13:04 by srodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"
#include "tetri-all.c"
//#define T1 "###.\n..#.\n....\n....\n"
//#define T2 "#.\n#.\n##\n"
const char shape[] = {"###.\n..#.\n....\n....\n"};
//	{'#', '.', '.', '.},
//	{'.', '.', '.', '.'},
//	{'.', '.', '.', '.'}
//};
const char const_shape[][21] = {
	{'#', '#', '#', '.'},
	{'#', '.', '.', '.'},
	{'.', '.', '.', '.'},
	{'.', '.', '.', '.'}
};
//by the time you get here you know the tetris pieces are valid alread, you are just checking the shape.
static int	list_pieces_valid(t_list **list)
{
	t_list *tmp;
	//unsigned int flag;

	ft_putstr("test define\n");
//	ft_putstr("t1: \n");
//	ft_putstr(T1);
//	ft_putstr("end of t1...");
	tmp = *list;
//	ft_putlist(tmp);
	ft_putstr("Validating Pieces... \n");
	ft_putstr("Test Piece: \n");
	ft_putstr(T7);
	while (tmp)
	{
		//this 'if statement' currently shows if and what we matched.
		//we eventually want it to exit if one of the strings dont match a shape. otherwise continue
		//we need to cycle through the tetris shapes that are in tetri-all.c
//		ft_putstr(tmp->data);
		//if (!(ft_strstr(tmp->data, <one_of_the_tetris_shapes>)))
		//	exit (1);
		if (ft_strstr(tmp->data, T7))
		//if (ft_strcmp((const char *)tmp->data, (const char *)T7) == 0)
		{
			ft_putstr("\nfound a match\n");
			ft_putstr(tmp->data);
			ft_putchar('\n');
		}
		tmp = tmp->next;
	}

	return (1);
}

static int	list_chars_valid(t_list **list)
{
	t_list	*tmp;
	int		index;
	char	c;

	ft_putstr("Validating characters... \n");
	tmp = *list;
	while (tmp && (index = -1))
	{
		ft_putstr(tmp->data);
		ft_putstr("\n");
		if (ft_strlen(tmp->data) != 16)
			return (0);
		while ((c = *(tmp->data + ++index)))
		{
			//ft_putstr("current index: ");
			//ft_putnbr(index);
			//ft_putchar('\n');
			//ft_putstr("current char: ");
			//ft_putchar(c);
			//ft_putchar('\n');
			if (!(c == '.' || c == '#'))
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

/*
static int	list_chars_valid(t_list **list)
{
	t_list	*tmp;
	int		index;
	//char	c;
	
	ft_putstr("Validating characters... \n");
	tmp = *list;
	while (tmp && (index = -1))
	{
		ft_putstr(tmp->data);

		tmp = tmp->next;
	}
	return (1);
}
*/

int			list_is_valid(t_list *list)
{
	return (list_chars_valid(&list) && list) ? list_pieces_valid(&list) : 0;
}
