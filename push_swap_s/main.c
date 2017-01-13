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
	int			flag;
//	char		**commands;
	t_stack		*stks;

	if (argc <= 1)
		return (0);
	if (!(tab = (int*)malloc(sizeof(int) * argc - 1)))
		return (-1);
	copy_tab = tab;
	stks = NULL;
	if (ft_validator(argc - 1, argv, *&tab, &flag) == -1)
		ft_putstr_fd("Error\n", 2);
	else if (ft_isinorder(tab, argc - flag - 1) == 1)
		ft_printf("");
	else
	{
		ft_printf("processing...\n\n");
		stks = ft_new_stks(*&copy_tab, argc - flag - 1, flag);

//		sa(stks);
//		sb(stks);
//		ss(stks);
		pb(stks);
//		pb(stks);
//		pb(stks);
//		pa(stks);
//		sb(stks);
//		ss(stks);
//		pa(stks);
//		pb(stks);
//		ra(stks);
//		rb(stks);
//		rr(stks);
//		rra(stks);
//		rrb(stks);
//		rrr(stks);
	}
	ft_free_all(copy_tab, stks);
	return (0);
}

void			ft_free_all(int *copy_tab, t_stack *stks)
{
	free(copy_tab); // можно ли его почистить прямо в stks (адрес же извествен?)
	if (stks)
	{
		free(stks->stk_b);
		free(stks);
	}
}
