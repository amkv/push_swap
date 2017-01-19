/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_algorithm_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:05:22 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/18 12:05:24 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void				ft_add_command(t_oper **commands, t_stack *stks)
{
	static t_oper	*holder;
	static int		flag;
	t_oper			*new;

	new = ft_new_oper(stks->last);
	if (*commands != NULL)
	{
		if (flag == 0)
			holder = new;
		if (flag > 0)
		{
			holder->next = new;
			holder = new;
		}
		else
			(*commands)->next = new;
		flag = 1;
	}
	else
		*commands = new;
}

static int 		ft_if_2(t_oper **commands, t_stack *stks)
{
	sa(stks);
	ft_add_command(*&commands, stks);
	return (1);
}

int 		ft_find_the_way(t_oper **commands, t_stack *stks)
{
	if (ft_is_stack_in_order(stks) == 1)
		return (1);
	else if (stks->size == 2)
		return (ft_if_2(*&commands, *&stks));
	return (0);
}
