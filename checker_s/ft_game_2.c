/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:07:17 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/16 12:07:23 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void		ft_use_commands(int n, t_stack *stks)
{
	void		(*oper[11])(t_stack*);

	oper[1] = &sa;
	oper[2] = &sb;
	oper[3] = &ss;
	oper[4] = &pa;
	oper[5] = &pb;
	oper[6] = &ra;
	oper[7] = &rb;
	oper[8] = &rr;
	oper[9] = &rra;
	oper[0] = &rrb;
	oper[10] = &rrr;
	oper[n](stks);
}

static	int 	ft_game_act_2(t_history *history, int oper)
{
	if (oper == 15)
		ft_print_history(history, 1);
	if (oper == 16)
		ft_print_history(history, 0);
	if (oper == 17)
		return (1);
	return (0);
}

int				ft_game_act(char *argument, t_stack *stks, t_history *history)
{
	int			oper;

	oper = ft_check_game_command(argument);
//	free(argument);
	if (oper >= 0 && oper < 11)
		ft_use_commands(oper, stks);
	else if (oper == 11)
		return (-1);
	else if (oper == 12)
		ft_print_list_of_commands();
	else if (oper == 13)
	{
		if (stks->elems_a < stks->size)
			ft_printf("warning: stack a not filled, only %d of %d"
			" numbers in the stack\n", stks->elems_a,  stks->size);
		if (ft_isinorder(stks->stk_a, stks->size) == 0)
			ft_printf("KO\n");
		else
			ft_printf("OK\n");;
	}
	else if (oper == 14)
		ft_print_stacks(stks);
	else
		return (ft_game_act_2(history, oper));
	return (0);
}
