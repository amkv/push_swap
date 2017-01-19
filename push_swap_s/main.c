/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:39:12 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/10 16:44:46 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
 * PUSH_SWAP
 */

int				main(int argc, char **argv)
{
	int			*tab;
	int			*copy_tab;
	int			*flags;
	t_oper		*commands;
	t_stack		*stks;

	if (argc <= 1)
		return (0);
	if (!(tab = (int*)malloc(sizeof(int) * argc - 1)))
		return (-1);
	copy_tab = tab;
	stks = NULL;
	commands = NULL;
	if (ft_validator(argc - 1, argv, *&tab, &flags) == -1)
		ft_putstr_fd("Error\n", 2);
	else
	{
		stks = ft_new_stks(*&copy_tab, argc - flags[0] - flags[1] - 1, flags);
		if (ft_find_the_way(&commands, *&stks) == -1)
			ft_putstr_fd("Error\n", 2);
		else
			ft_print_commands(commands);
	}
	ft_free_all(tab, stks, &commands, flags);
	return (0);
}
