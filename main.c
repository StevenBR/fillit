/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 03:32:04 by srodrigu          #+#    #+#             */
/*   Updated: 2016/11/18 23:20:08 by srodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"

int main(int ac, char **av)
{
	/* Be back soon, don't miss me too much <3 
	 * ps. it's ok to cry :') */
	t_list *list;

	list = 0;
	if (ac != 2)
		(ft_putstr("Incorrect # of parameters"));
	else
	{
		(file_read_create(*(av + 1), &list));
		if(!(is_valid_tetrimino(list)))
			return (0);
		create_initial_board();
	}
	// (list_is_valid(list)) ? ft_putstr("valid list: :D\n")
	// 	: ft_putstr("invalid list: :/");
	//	if(ac != 2)
//		ft_putstr("Incorrect number of parameters");
//	else
//		file_read_create(*(av + 1), &list);
	
//	if(list_is_valid(list))
//		ft_putstr("valid list: :D\n");
////		solve_fillit(0);
//	else
//		ft_putstr("invalid list: :/");
	return (0);
}
