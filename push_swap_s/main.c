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
** PUSH_SWAP
*/

int				main(int argc, char **argv)
{
	int			*tab;
	int			*flags;
	t_stack		*stks;

	if (argc <= 2) // проверить в checker эту же проверку
		return (0);
	tab = NULL;
	stks = NULL;
	if (ft_validator(&argc, argv, &tab, &flags) == -1)
		ft_putstr_fd("Push_swap_validator_Error\n", 2);
	else
	{
		if (!(stks = ft_new_stks(*&tab, argc - flags[0] - flags[1], flags)))
			ft_putstr_fd("Error\n", 2);
		else if (ft_push_swap(*&stks) == -1)
			ft_putstr_fd("Algorithm_Error\n", 2);
//		if (ft_is_stack_in_order(stks) == 1)
//			ft_printf("OK\n");
//		else
//			ft_printf("KO\n");
	}
	ft_free_all(tab, stks, NULL, flags);
	return (0);
}
