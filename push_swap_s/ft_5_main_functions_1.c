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
** main algorithm functions 2
*/

void		ft_set_min_max_a(t_stack *stks)
{
	int		i;

	i = stks->top_a;
	stks->a_min = stks->stk_a[i];
	stks->a_mni = i;
	stks->a_max = stks->stk_a[i];
	stks->a_mxi = i;
	while (i < stks->size)
	{
		if (stks->stk_a[i] < stks->a_min)
		{
			stks->a_min = stks->stk_a[i];
			stks->a_mni = i;
		}
		if (stks->stk_a[i] > stks->a_max)
		{
			stks->a_max = stks->stk_a[i];
			stks->a_mxi = i;
		}
		i++;
	}
}

void		ft_set_min_max_b(t_stack *stks)
{
	int		i;

	i = stks->top_b;
	stks->b_min = stks->stk_b[i];
	stks->b_mni = i;
	stks->b_max = stks->stk_b[i];
	stks->b_mxi = i;
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

void		ft_make_b_nice(t_stack *stks)
{
	int		up_b;
	int		down_b;
	int		num;

	ft_set_min_max_b(stks);
	up_b = ft_up_b_helper(stks, stks->b_mxi);
	down_b = ft_down_b_helper(stks, stks->b_mxi);
	num = down_b;
	(up_b <= down_b) ? (num = up_b) : (num);
	if (stks->b_mxi != 0)
		while (num--)
		{
			if (up_b < down_b)
			{
				rb(stks);
				if (stks->flag == 0)
					ft_putstr("rb\n");
			}
			else
			{
				rrb(stks);
				if (stks->flag == 0)
					ft_putstr("rrb\n");
			}
		}
}

// depricated
void		ft_return_to_home(t_stack *stks)
{
	int		index;

	index = 0;
	while (index < stks->size)
	{
		pa(stks);
		if (stks->flag != 1)
			ft_printf("pa\n");
		index++;
	}
}