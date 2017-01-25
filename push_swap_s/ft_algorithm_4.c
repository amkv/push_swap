/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:59:22 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/24 15:59:23 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
 * up B
 */

static t_oper		*ft_up_b_helper(t_stack *stks, int index)
{
	int 		num;
	t_oper		*steps;

	steps = NULL;
	if (index == stks->top_b)
		return (NULL);
	num = stks->top_b - index;
	if (num < 0)
		num = -1 * num;
	while (num)
	{
		steps = ft_add_step(steps, 6);
		num--;
	}
	return (steps);
}

t_oper			*ft_up_b(t_stack *s, int i)
{
	t_oper		*steps;
	int 		topb;

	steps = NULL;
	topb = s->top_b;
	while (topb < s->size)
	{
//		if (topb == s->top_b)
//		{
//			if (s->stk_a[i] < s->stk_b[s->size - 1] && s->stk_a[i] > s->stk_b[topb + 1])
//				break;
//		}
		if (topb == s->size - 1)
			break;
		if (s->stk_a[i] < s->stk_b[topb] && s->stk_a[i] > s->stk_b[topb + 1])
			break;
		topb++;
	}
	if (topb == s->size - 1)
		steps = ft_add_step(steps, 6);
	else
		steps = ft_up_b_helper(s, topb);
	return (steps);
}
