/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 20:06:38 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/24 20:06:39 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
 * down B (insert in b)
 */

static t_oper		*ft_down_b_helper(t_stack *stks, int index)
{
	int 		num;
	t_oper		*steps;

	steps = NULL;
	num = stks->size - index;
	while (num)
	{
		steps = ft_add_step(steps, 9);
		num--;
	}
	return (steps);
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

t_oper			*ft_down_b(t_stack *s, int index)
{
	t_oper		*steps;
	int 		elem;
	int 		winner;

	steps = NULL;
	if (s->stk_a[index] > s->b_max)
		steps = ft_down_b_helper(s, s->b_mxi);
	else if (s->stk_a[index] < s->b_min)
		steps = ft_down_b_helper(s, s->b_mxi);
	else
	{
		ft_check_after_max_b(s, &winner, &elem, index);
		if (elem < s->elems_b)
			ft_check_before_max_b(s, &winner, index);
		steps = ft_down_b_helper(s, winner);
	}
	return (steps);
}

//t_oper			*ft_down_b(t_stack *s, int index)
//{
//	t_oper		*steps;
//	int 		elem;
//	int 		b_max_index;
//	int 		winner;
//	int			num_a;
//	int			num_b;
//	int			elems_b;
//	int			size;
//	int 		top_b;
//
//	steps = NULL;
//	if (s->stk_a[index] > s->b_max)
//		steps = ft_down_b_helper(s, s->b_mxi);
//	else if (s->stk_a[index] < s->b_min)
//		steps = ft_down_b_helper(s, s->b_mxi);
//	else
//	{
//		elem = 0;
//		b_max_index = s->b_mxi;
//		size = s->size;
//		while (b_max_index < size)
//		{
//			num_a = s->stk_a[index];
//			num_b = s->stk_b[b_max_index];
//			if (num_a > num_b)
//			{
//				winner = b_max_index;
//				elem++;
//				break ;
//			}
//			b_max_index++;
//			elem++;
//		}
//		elems_b = s->elems_b;
//		if (elem < elems_b)
//		{
//			top_b = s->top_b;
//			while (top_b != b_max_index)
//			{
//				num_a = s->stk_a[index];
//				num_b = s->stk_b[top_b];
//				if (num_a > num_b)
//				{
//					winner = top_b;
//					break ;
//				}
//				top_b++;
//			}
//		}
//		steps = ft_down_b_helper(s, winner);
//	}
//	return (steps);
//}
