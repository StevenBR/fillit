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
	t_list *curr;
	int	num_tets;
	char ***tetriminos;

	
	list = 0;
	if (ac != 2)
	{
		(ft_putstr("error"));
		return (1);
	}
	else
	{
		file_read_create(av[1], &list);
		num_tets = 0;
		curr = list;
		while (curr)
		{
			printf("%s\n", curr->data);
			num_tets++;
			curr = curr->next;
		}
		printf("mallocking\n");
		tetriminos = (char ***)malloc(sizeof(char **) * num_tets);
		num_tets = 0;
		curr = list;
		printf("malloc completed\n");
		while (curr)
		{
			tetriminos[num_tets] = convert_1d_to_2d(list->data);
			shift_tetrimino(tetriminos[num_tets]);
			int i = 0;
			while (i < 4)
			{
				printf("%s\n", tetriminos[num_tets][i++]);
			}
			if(is_valid_tetrimino(tetriminos[num_tets]) == 0)
			{
				ft_putstr("error");
				return (1);
			}
			curr = curr->next;
		}
		// create_initial_board();
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
