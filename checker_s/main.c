/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:38:47 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/10 15:31:58 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * write
 * read
 * malloc
 * free
 * exit
 */

#include "../shared_s/push_swap.h"

static void		ft_isinorder(int *tab, int size)
{
	int 		index;
	int 		number;

	index = 0;
	number = tab[index];
	index++;
	while (index < size)
	{
		if (number < tab[index])
			number = tab[index];
		else
		{
			ft_printf("что тут не так\n");
			break;
		}
		size--;
	}
}

static void		ft_poehali(char *str)
{
	return ;
}

int		main(int argc, char **argv)
{
	int 	**tab;
	int 	index;

	if (argc > 2)
	{
		tab = (int**)malloc(sizeof(int) * argc);
		index = 0;
		while (index < argc)
		{
			tab[index] = (int)malloc(sizeof(int)* 1);
//			tab[index] = (int)ft_atoi(*argv[index]);
			tab[index] = &index;
			index++;
		}
	}
	else
		ft_printf("error\n");
	return (0);
}
