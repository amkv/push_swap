/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_algorithm_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:05:22 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/18 12:05:24 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** main algorithm
*/

/*
//	ft_printf("-----------------\n");
//	ft_printf("up_a: %d\n", up_a = ft_up_a(stks, index));
//	ft_printf("down_a: %d\n", down_a = ft_down_a(stks, index));
//	ft_printf("up_b: %d\n", up_b = ft_up_b(stks, index));
//	ft_printf("down_b: %d\n\n", down_b = ft_down_b(stks, index));
//	ft_printf("-----------------\n");
//	int winner;
//	winner = steps->holder->num;
//	ft_printf("winner %d\n", winner);
*/

static t_oper		*ft_check_steps(t_stack *stks, int index)
{
	int				up_a;
	int				up_b;
	int				down_a;
	int				down_b;
	int				winner;

	ft_set_min_max_b(stks);
	up_a = ft_up_a(stks, index);
	down_a = ft_down_a(stks, index);
	up_b = ft_up_b(stks, index);
	down_b = ft_down_b(stks, index);
	winner = ft_candidates(up_a, down_a, up_b, down_b);
	if (winner == 0)
		return (ft_ua_ub(up_a, up_b));
	else if (winner == 1)
		return (ft_da_db(down_a, down_b));
	else if (winner == 2)
		return (ft_ua_db(up_a, down_b));
	else if (winner == 3)
		return (ft_da_ub(down_a, up_b));
	else
		return (NULL);
}

static t_oper		*ft_internal_loop(t_stack *s, int in, int ex, int num_oper)
{
	t_oper			*candidate;
	t_oper			*answer;

	answer = NULL;
	while (in < s->size)
	{
		if (!(candidate = ft_check_steps(s, in)))
			break ;
		if (in == ex)
		{
			num_oper = candidate->holder->num;
			answer = candidate;
		}
		else if (candidate->holder->num <= num_oper)
		{
			ft_free_steps(&answer);
			num_oper = candidate->holder->num;
			answer = candidate;
		}
		else
			ft_free_steps(&candidate);
		in++;
	}
	return (answer);
}

static int			ft_main_algorithm(t_stack *stks)
{
	int				index;
	t_oper			*steps;
	t_oper			*alt;

	index = 0;
	while (index < stks->size)
	{
		steps = NULL;
		if (index <= 1)
			steps = ft_add_step(steps, 4);
/*
//		else if (index == stks->size)
//		{
//			ft_set_min_max_b(stks);
//			if (stks->stk_a[stks->top_a] > stks->b_max)
//				index++;
//				continue;
//		}
*/
		else
		{
			alt = ft_check_push_to_top_b(stks);
			if (alt && alt->holder->num == 1)
				steps = alt;
			else
			{
				steps = ft_internal_loop(stks, index, index, 0);
				if (alt && alt->holder->num <= steps->holder->num)
				{
//					free(steps);
					steps = alt;
				}
				else
				{
					if (alt)
						free(alt);
				}
			}
		}
		ft_use_print_and_free(stks, &steps);
		static int ind;
		ft_printf("-----------------------------index %d\n", ind++);
		index++;
	}
	ft_make_b_nice(stks);
	ft_return_to_home(stks);
	return (1);
}

int					ft_push_swap(t_stack *stks)
{
	if (ft_is_stack_in_order(stks) == 1)
		return (1);
	else if (stks->size == 2)
	{
		sa(stks);
		ft_printf("sa\n");
		return (1);
	}
	else if (stks->size == 3)
		return (ft_eq_3(stks));
	else if (stks->size <= 5)
		return (ft_eq_5(stks));
	else if (ft_main_algorithm(*&stks) == -1)
		return (-1);
	else
		return (1);
}
