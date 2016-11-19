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
//we'll probably want to use this const format to save our shapes. and put them in or create a header file for them.
//const char shape[] = {"###.\n..#.\n....\n....\n"};

//if we add this to our libft we could use this in ft_trim_newline
//(basically doing it with the helper function there)
//ft_count_char(char *str, char <character_to_be_counted>)

//by the time you get here you know the string characters are valid already, you are just checking the shape.
static int	list_pieces_valid(t_list **list)
{
	t_list *tmp;

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
		//ft_putstr(tmp->data);
		
/*we could us this if statement for the exit check stated below*/
		//if (!(ft_strstr(tmp->data, <one_of_the_tetris_shapes>)))
		//	exit (1);
		
		//'if statement' below currently shows if and what we matched.
		//we eventually want it to exit if one of the strings Don't match a shape. otherwise continue
		//we need to cycle through the tetris shapes that are in tetri-all.c
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
			//commented code: prints current index and character at that index
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

// commented code: runs through the list without actually checking the characters. (used for testing)
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

	//the return above is the "buched together" version of the code below.
	//the code below is broken up but works the same. use either.
	/*	if (!(list_chars_valid(&list) && list))
		return (0);
	if (!(list_pieces_valid(&list)))
		return (0);
	return (1);
	*/
}
