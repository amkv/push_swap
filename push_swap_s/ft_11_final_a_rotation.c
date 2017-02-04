/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_11_final_a_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:55:28 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/03 17:55:32 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void		ft_print_status(t_stack *stks)
{
	stks->flag = 1;
	ft_print_stacks(stks);
	stks->flag = 0;
}

static int		ft_return_place(t_stack *s)
{
	int			index;
	int			b_num;

	index = s->top_a;
	b_num = s->stk_b[s->top_b];
	while (index < s->size)
	{
		if (index == s->top_a)
		{
			if (b_num < s->stk_a[index] && b_num < s->stk_a[s->size - 1])
				return (index);
			if (b_num > s->stk_a[index] && b_num < s->stk_a[s->size - 1])
				return (index + 1);
		}
		else if (index == s->size - 1)
		{
			if (b_num < s->stk_a[index] && b_num < s->stk_a[s->top_a])
				return (index);
			else if (b_num > s->stk_a[index])
				return (index);
		}
		else if (b_num > s->stk_a[index] && b_num < s->stk_a[index + 1])
			return (index + 1);
		index++;
	}
	return (0);
}

static void		ft_rotate_a(t_stack *stks, int place)
{
	int		up_a;
	int		down_a;
	int		num;

	ft_set_min_max_a(stks);
	up_a = ft_up_a(stks, place);
	down_a = ft_down_a(stks, place);
	num = down_a;
	(up_a <= down_a) ? (num = up_a) : (num);
	if (stks->a_mni != 0)
	{
		while (num--)
		{
			if (up_a < down_a)
			{
				ra(stks);
				if (stks->flag == 0)
					ft_putstr("ra\n");
			}
			else
			{
				rra(stks);
				if (stks->flag == 0)
					ft_putstr("rra\n");
			}
		}
	}
}

void 	ft_make_nice_a_and_say_bye_to_b(t_stack *stks)
{
	int 		place;

//	ft_printf("status\n");
//	ft_print_status(stks);

	while (stks->elems_b)
	{
		place = ft_return_place(stks);
		ft_rotate_a(stks, place);
//		ft_print_status(stks);
		pa(stks);
		ft_putstr("pa\n");
//		ft_print_status(stks);
	}


//	ft_print_status(stks);
}
