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

static void		ft_set_min_max(t_stack *stks)
{
	int 		i;

	i = stks->top_b;
	stks->b_min = stks->stk_b[i];
	stks->b_max = stks->stk_b[i];
	while (i < stks->size)
	{
		if (stks->stk_b[i] <= stks->b_min)
		{
			stks->b_min = stks->stk_b[i];
			stks->b_mni = i;
		}
		if (stks->stk_b[i] >= stks->b_max)
		{
			stks->b_max = stks->stk_b[i];
			stks->b_mxi = i;
		}
		i++;
	}
}

static t_oper	*ft_up_b_helper(t_stack *stks, int index)
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

t_oper			*ft_up_b(t_stack *s, int index)
{
	t_oper		*steps;
	int 		elem;
	int 		b_max_index;
	int 		winner;
	int			num_a;
	int			num_b;
	int			elems_b;
	int			size;
	int 		top_b;

	steps = NULL;
	ft_set_min_max(s);
	if (s->stk_a[index] > s->b_max)
		steps = ft_up_b_helper(s, s->b_mxi);
	else if (s->stk_a[index] < s->b_min)
		steps = ft_up_b_helper(s, s->b_mxi);
	else
	{
		elem = 0;
		b_max_index = s->b_mxi;
		size = s->size;
		while (b_max_index < size)
		{
			num_a = s->stk_a[index];
			num_b = s->stk_b[b_max_index];
			if (num_a > num_b)
			{
				winner = b_max_index;
				elem++;
				break ;
			}
			b_max_index++;
			elem++;
		}
		elems_b = s->elems_b;
		if (elem < elems_b)
		{
			top_b = s->top_b;
			while (top_b != b_max_index)
			{
				num_a = s->stk_a[index];
				num_b = s->stk_b[top_b];
				if (num_a > num_b)
				{
					winner = top_b;
					break ;
				}
				top_b++;
			}
		}
		steps = ft_up_b_helper(s, winner);
	}
	return (steps);
}
