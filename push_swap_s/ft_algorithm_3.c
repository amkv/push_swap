/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:56:47 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/24 15:56:48 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
 * To be on the top
 */

t_oper		*ft_up_a(t_stack *stks, int index)
{
	int 		num;
	t_oper		*steps;

	steps = NULL;
	if (index == stks->top_a)
		return (NULL);
	num = stks->top_a - index;
	if (num < 0)
		num = -1 * num;
	while (num)
	{
		steps = ft_add_step(steps, 5);
		num--;
	}
	return (steps);
}

t_oper		*ft_down_a(t_stack *stks, int index)
{
	int 		num;
	t_oper		*steps;

	steps = NULL;
	num = stks->size - index;
	while (num)
	{
		steps = ft_add_step(steps, 8);
		num--;
	}
	return (steps);
}
