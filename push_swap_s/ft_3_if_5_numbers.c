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


//static t_oper		*ft_to_b_up(int up_a)
//{
//	t_oper			*steps;
//
//	steps = NULL;
//	while (up_a > 0)
//	{
//		steps = ft_add_step(steps, 5);
//		up_a--;
//	}
//	steps = ft_add_step(steps, 4);
//	return (steps);
//}
//
//static t_oper		*ft_to_b_down(int dw_a)
//{
//	t_oper			*steps;
//
//	steps = NULL;
//	while (dw_a > 0)
//	{
//		steps = ft_add_step(steps, 8);
//		dw_a--;
//	}
//	steps = ft_add_step(steps, 4);
//	return (steps);
//}
//
//static t_oper				*ft_check_push_to_top_a(t_stack *s)
//{
//	int				top_a;
//	int				ntopb;
//	int				up_a;
//	int				dw_a;
//
//	ntopb = s->stk_b[s->top_b];
//	top_a = s->top_a;
//	while (top_a != s->size - 1)
//	{
//		if (s->stk_a[top_a] > ntopb && s->stk_a[top_a] < s->stk_b[s->size - 1])
//		{
//			up_a = ft_up_a(s, top_a);
//			dw_a = ft_down_a(s, top_a);
//			if (up_a > dw_a)
//				return (ft_to_b_down(dw_a));
//			else
//				return (ft_to_b_up(up_a));
//		}
//		top_a++;
//	}
//	return (NULL);
//}

int			ft_eq_5(t_stack *stks)
{
	int 	elem_b;

	pb(stks);
	if (stks->size == 5)
		pb(stks);
	ft_eq_3(stks);
	ft_set_min_max_a(stks);
	elem_b = stks->elems_b;
	while (elem_b > 1)
	{
		if (stks->stk_b[stks->top_b] < stks->a_min)
			pa(stks);
		else if (stks->stk_b[stks->top_b] > stks->a_max)
			pa(stks);
		else if (stks->stk_b[stks->top_b] > stks->stk_a[stks->top_a + 1])
		{
			rra(stks);
			pa(stks);
		}
		elem_b--;
	}



	return (1);
}
