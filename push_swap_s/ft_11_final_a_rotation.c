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

static int		ft_return_brother(t_stack *s)
{
	int		index;
	int		b;
	int		a;

	index = s->top_a;
	a = s->stk_a[s->top_a];
	b = s->stk_b[s->top_b];
	while (index < s->size)
	{
		if (b < s->stk_a[index] && a > s->stk_a[index])
			return (index);
		index++;
	}
	return (-1);
}

static int		ft_return_place(t_stack *s)
{
	int		index;
	int		b;
	int		brother;

	index = s->top_a;
	b = s->stk_b[s->top_b];
	ft_set_min_max_a(s);
	if ((brother = ft_return_brother(s)) != -1)
		return (brother);
	if (b > s->a_max)
		return (s->a_mni);
	if (b < s->a_min)
		return (s->a_mni);
	while (index != s->size - 1)
	{
		if (b < s->stk_a[index])
			return (index);
		else if (b > s->stk_a[index] && b < s->stk_a[index + 1]
				&& s->stk_a[index + 1] == s->size - 1)
			return (index + 1);
		else if (b > s->stk_a[index] && b < s->stk_a[index + 1])
			return (index + 1);
		index++;
	}
	return (0);
}

static void		ft_rotate_a(t_stack *stks, int place, int up_a, int down_a)
{
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

void			ft_make_nice_a_and_say_bye_to_b(t_stack *stks)
{
	int		place;

	ft_eq_5(stks, 3);
	while (stks->elems_b)
	{
		place = ft_return_place(stks);
		ft_rotate_a(stks, place, 0, 0);
		pa(stks);
		ft_putstr("pa\n");
	}
	ft_set_min_max_a(stks);
	ft_rotate_a(stks, stks->a_mni, 0, 0);
}
