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
<<<<<<< HEAD
 * write, read, malloc, free, exit
 */

#include "../shared_s/push_swap.h"
#pragma GCC diagnostic ignored "-Wunused-function"
=======
 * write
 * read
 * malloc
 * free
 * exit
 */

#include "../shared_s/push_swap.h"
>>>>>>> b9feb9350a9d82d894af78c366c98885dc76196f

static void		ft_isinorder(int *tab, int size)
{
	int 		index;
	int 		number;
<<<<<<< HEAD
	int 		tab_number;

	if (size <= 1)
	{
		ft_printf("что-то тут не так\n");
		return ;
	}
=======

>>>>>>> b9feb9350a9d82d894af78c366c98885dc76196f
	index = 0;
	number = tab[index];
	index++;
	while (index < size)
	{
<<<<<<< HEAD
		tab_number = tab[index];
		if (number < tab_number)
			number = tab_number;
		else
		{
			ft_printf("что-то тут не так\n");
			return ;
		}
		size--;
		index++;
	}
	ft_printf("отсортирован и прекрасен\n");
}

//static void		ft_poehali(char *str)
//{
//	return ;
//}

int		main(int argc, char **argv)
{
	int 	*tab;
	int 	index;

	ft_printf("argc:  %d\n\n", argc);
	if (argc > 2)
	{
		index = 0;
		tab = (int*)malloc(sizeof(int) * argc);
		while (index < argc - 1)
		{
			tab[index] = (int)ft_atoi(argv[index + 1]);
			ft_printf("index:  %d\n", index);
			ft_printf("atoi:   %d\n", (int)ft_atoi(argv[index + 1]));
			ft_printf("tab[i]: %d\n\n", tab[index]);
			index++;
		}
		ft_isinorder(tab, argc);
=======
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
>>>>>>> b9feb9350a9d82d894af78c366c98885dc76196f
	}
	else
		ft_printf("error\n");
	return (0);
}
