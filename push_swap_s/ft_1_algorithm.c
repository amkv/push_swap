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

static t_oper	*ft_check_steps(t_stack *stks, int index)
{
	int			up_a;
	int			up_b;
	int			down_a;
	int			down_b;
	int			winner;

	ft_set_min_max_b(stks);
	up_a = ft_up_a(stks, index);
	down_a = ft_down_a(stks, index);
	up_b = ft_up_b(stks, index);
	down_b = ft_down_b(stks, index);
	winner = ft_candidates(up_a, down_a, up_b, down_b);

//	{
//		ft_printf("-----------------\n");
//		ft_printf("up_a: %d\n", up_a = ft_up_a(stks, index));
//		ft_printf("down_a: %d\n", down_a = ft_down_a(stks, index));
//		ft_printf("up_b: %d\n", up_b = ft_up_b(stks, index));
//		ft_printf("down_b: %d\n\n", down_b = ft_down_b(stks, index));
//		if (winner == 0)
//			ft_printf("winner[0]: ua_ub\n");
//		else if (winner == 1)
//			ft_printf("winner[1]: da_db\n");
//		else if (winner == 2)
//			ft_printf("winner[2]: ua_db\n");
//		else if (winner == 3)
//			ft_printf("winner[3]: da_ub\n");
//	}

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

static t_oper	*ft_internal_loop(t_stack *s, int in, int ex, int num_oper)
{
	t_oper		*candidate;
	t_oper		*answer;

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

static int		ft_main_loop(t_stack *stks, int i, t_oper *steps, t_oper *alt)
{
	while (i < stks->size)
	{
		steps = NULL;
		if (i <= 1)
			steps = ft_add_step(steps, 4);
		else
		{
			alt = ft_check_push_to_top_b(stks);
			steps = ft_internal_loop(stks, i, i, 0);
			if (alt && alt->holder->num <= steps->holder->num)
			{
				ft_free_steps(&steps);
				steps = alt;
			}
			else
				if (alt)
					ft_free_steps(&alt);
		}
		ft_use_print_and_free(stks, &steps);
//		static int ind;
//		ft_printf("-----------------------------i %d\n", ind++);
		i++;
//		if (stks->elems_a == 5)
//			break ;
	}
//	stks->flag = 1;
//	ft_print_stacks(stks);
//	stks->flag = 0;
//	ft_printf("------------------------------\n");

//	ft_eq_5(stks, 3);
//	stks->flag = 1;
//	ft_print_stacks(stks);
//	stks->flag = 0;
//	ft_printf("------------------------------\n");

//	ft_make_a_nice(stks);
//	stks->flag = 1;
//	ft_print_stacks(stks);
//	stks->flag = 0;
//	ft_printf("------------------------------\n");
	ft_make_b_nice(stks);
	ft_return_to_home(stks);
	return (1);
}

int				ft_push_swap(t_stack *stks)
{
	if (ft_is_stack_in_order(stks) == 1)
		return (1);
	else if (stks->size == 2)
		return (ft_eq_2(stks));
	else if (stks->size == 3)
		return (ft_eq_3(stks, NULL, 1));
	else if (stks->size <= 5)
		return (ft_eq_5(stks, 2));
	else if (ft_main_loop(*&stks, 0, NULL, NULL) == -1)
		return (-1);
	else
		return (1);
}
