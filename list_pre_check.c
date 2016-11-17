/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pre_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:50:39 by srodrigu          #+#    #+#             */
/*   Updated: 2016/11/12 22:50:41 by srodrigu         ###   ########.fr       */
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

	ft_putstr("test define\n");
	ft_putstr(T1);
	tmp = *list;
//	ft_putlist(tmp);
	ft_putstr("Validating Pieces... \n");
	while (tmp)
	{
		ft_putstr(tmp->data);
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
		while ((c = *(tmp->data + ++index)))
			if (!((((index % 5) == 4) && (c == '\n')) ||
				((index == 20) && c == '\0') ||
				(c == '.' || c == '#')))
				return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			list_is_valid(t_list *list)
{
	return (list_chars_valid(&list) && list) ? list_pieces_valid(&list) : 0;
}
