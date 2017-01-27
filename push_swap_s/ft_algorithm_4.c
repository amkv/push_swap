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
 * up B (insert in b)
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

static int		ft_up_b_helper(t_stack *stks, int index)
{
	int 		num;

	if (index == stks->top_b)
		return (0);
	num = stks->top_b - index;
	if (num < 0)
		num = -1 * num;
	return (num);
}

static void		ft_check_after_max_b(t_stack *s, int *win, int *elem, int index)
{
	int 		b_max_index;

	*elem = 0;
	b_max_index = s->b_mxi;
	while (b_max_index < s->size)
	{
		if (s->stk_a[index] > s->stk_b[b_max_index])
		{
			*win = b_max_index;
			(*elem)++;
			break ;
		}
		b_max_index++;
		(*elem)++;
	}
}

static void		ft_check_before_max_b(t_stack *s, int *win, int index)
{
	int 		b_max_index;
	int 		top_b;

	b_max_index = s->b_mxi;
	top_b = s->top_b;
	while (top_b != b_max_index)
	{
		if (s->stk_a[index] > s->stk_b[top_b])
		{
			*win = top_b;
			break ;
		}
		top_b++;
	}
}

int				ft_up_b(t_stack *s, int index)
{
	int			steps;
	int 		elem;
	int 		winner;

	ft_set_min_max(s);
	if (s->stk_a[index] > s->b_max)
		steps = ft_up_b_helper(s, s->b_mxi);
	else if (s->stk_a[index] < s->b_min)
		steps = ft_up_b_helper(s, s->b_mxi);
	else
	{
		ft_check_after_max_b(s, &winner, &elem, index);
		if (elem < s->elems_b)
			ft_check_before_max_b(s, &winner, index);
		steps = ft_up_b_helper(s, winner);
	}
	return (steps);
}
