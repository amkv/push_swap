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
** if <= 5 numbers
*/

void			ft_make_a_nice(t_stack *stks)
{
	t_oper *steps;

	steps = NULL;
	ft_set_min_max_a(stks);
	if (stks->a_mxi == stks->top_a)
		steps = ft_add_step(NULL, 5);
	if (stks->elems_a == 4)
	{
		if (stks->a_mxi == stks->top_a + 1)
			steps = ft_add_step(ft_add_step(NULL, 8), 8);
		else if (stks->a_mxi == stks->top_a + 2)
			steps = ft_add_step(NULL, 8);
	}
	else
	{
		if (stks->a_mxi == stks->top_a + 1)
			steps = ft_add_step(ft_add_step(NULL, 5), 5);
		else if (stks->a_mxi == stks->top_a + 2)
			steps = ft_add_step(ft_add_step(NULL, 8), 8);
		else if (stks->a_mxi == stks->top_a + 3)
			steps = ft_add_step(NULL, 8);
	}
	ft_use_print_and_free(stks, &steps);
}

static int		ft_check_the_place_in_a(t_stack *stks)
{
	int			index;
	int			elem;

	index = stks->a_mni;
	elem = 4;
	if (stks->stk_b[stks->top_b] < stks->a_min)
		return (stks->a_mni);
	else if (stks->stk_b[stks->top_b] > stks->a_max)
		return (stks->a_mni);
	while ((index < stks->size))
	{
		if (stks->stk_b[stks->top_b] < stks->stk_a[index++])
			return (--index);
		elem--;
	}
	if (elem > 1)
	{
		index = 1;
		while (index != stks->a_mni)
			if (stks->stk_b[stks->top_b] < stks->stk_a[index++])
				return (--index);
	}
	return (0);
}

static t_oper	*ft_second_number(t_oper *steps, t_stack *stks)
{
	int			place;

	place = ft_check_the_place_in_a(stks);
	if (place == 1)
		;
	else if (place == 2)
		steps = ft_add_step(steps, 5);
	else if (place == 3)
		steps = ft_add_step(ft_add_step(steps, 5), 5);
	else if (place == 4)
		steps = ft_add_step(steps, 8);
	return (ft_add_step(steps, 3));
}

static t_oper	*ft_first_number(t_oper *steps, t_stack *s)
{
	if (s->stk_b[s->top_b] < s->a_min)
		steps = ft_add_step(steps, 3);
	else if (s->stk_b[s->top_b] > s->a_max)
		steps = ft_add_step(steps, 3);
	else if (s->stk_b[s->top_b] < s->stk_a[s->top_a + 1])
		steps = ft_add_step(ft_add_step(steps, 5), 3);
	else if (s->stk_b[s->top_b] > s->stk_a[s->top_a + 1])
		steps = ft_add_step(ft_add_step(steps, 8), 3);
	return (steps);
}

int				ft_eq_5(t_stack *stks, int incident)
{
	t_oper		*steps;

	steps = ft_add_step(NULL, 4);
	if (stks->size == 5)
		steps = ft_add_step(steps, 4);
	ft_eq_3(stks, steps, incident);
	ft_set_min_max_a(stks);
	steps = ft_first_number(NULL, stks);
	ft_use_print_and_free(stks, &steps);
	if (stks->size == 5)
	{
		ft_set_min_max_a(stks);
		steps = ft_second_number(NULL, stks);
		ft_use_print_and_free(stks, &steps);
	}
	ft_make_a_nice(stks);
	return (1);
}
