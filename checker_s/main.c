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
 * CHECKER
 */

/*
 * write, read, malloc, free, exit
 */

#include "../shared_s/push_swap.h"

int		main(int argc, char **argv)
{
	int *tab;
	int *copy_tab;
	int flag;
	t_stack		*stks;
//	char 	**commands;

	if (argc <= 1)
		return (0);
	if (!(tab = (int*)malloc(sizeof(int) * argc - 1)))
		return (-1);
	copy_tab = tab;
	if (ft_validator(argc - 1, argv, *&tab, &flag) == -1)
		ft_putstr_fd("Error\n", 2);
//	else if (ft_isinorder(tab, argc - flag - 1) == 1)
//		ft_printf("OK\n");
	else
	{
		ft_printf("processing...\n\n");
		stks = ft_new_stks(*&copy_tab, argc - flag - 1, flag);
		ft_read_arguments();
//		ft_use_commands(commands, tab);
	}
	free(copy_tab);
	return (0);
}
