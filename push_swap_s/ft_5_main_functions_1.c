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

static void		ft_upf(t_oper **copy, t_stack *stks)
{
	t_oper		*holder;

	holder = (*copy)->next;
	if (stks->flag == 0)
	{
		ft_putstr((*copy)->oper);
		ft_putchar('\n');
	}
	free((*copy)->oper);
	free((*copy));
	*copy = NULL;
	*copy = holder;
}

void			ft_use_print_and_free(t_stack *stks, t_oper **answers)
{
	t_oper		*copy;
	void		(*oper[11])(t_stack*);

	if (*answers == NULL)
		return ;
	oper[0] = &sa;
	oper[1] = &sb;
	oper[2] = &ss;
	oper[3] = &pa;
	oper[4] = &pb;
	oper[5] = &ra;
	oper[6] = &rb;
	oper[7] = &rr;
	oper[8] = &rra;
	oper[9] = &rrb;
	oper[10] = &rrr;
	copy = (*answers)->holder;
	while (copy)
	{
		oper[copy->command](stks);
		ft_upf(&copy, stks);
	}
	*answers = NULL;
}

void			ft_set_min_max_a(t_stack *stks)
{
	int			i;

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

void			ft_set_min_max_b(t_stack *stks)
{
	int			i;

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
