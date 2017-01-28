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

//static t_oper		*ft_check_steps2(t_stack *stks, int index)
//{
//	int				up_a;
//	int				up_b;
//	int				down_a;
//	int				down_b;
//	t_oper			*steps;
//
//	steps = NULL;
//	ft_set_min_max(stks);
//	ft_printf("up_a: %d\n", up_a = ft_up_a(stks, index));
//	ft_printf("down_a: %d\n", down_a = ft_down_a(stks, index));
//	ft_printf("up_b: %d\n", up_b = ft_up_b(stks, index));
//	ft_printf("down_b: %d\n\n", down_b = ft_down_b(stks, index));
////	steps = ft_merge_steps(up_a, down_a, up_b, down_b);
//	return (steps);
//}
//
//static int 			ft_test_function(t_stack *s)
//{
//	t_oper			*steps;
//	int 			i;
//	int 			index;
//
//	index = 6;
//	steps = NULL;
//	pb(s);
//	pb(s);
//	pb(s);
//	pb(s);
//	rrb(s);
//	pb(s);
//	pb(s);
//
//	s->flag = 1;
//	ft_print_stacks(s);
//	s->flag = 0;
//	ft_printf("index: %d\n",  index);
//	ft_printf("num a: %d\n\n", s->stk_a[index]);
//	steps = ft_check_steps2(s, index);
//	ft_printf("-----------------\n");
//	ft_printf("max: %d\n", s->b_max);
//	ft_printf("mx_i: %d\n", s->b_mxi);
//	ft_printf("min: %d\n", s->b_min);
//	ft_printf("mn_i: %d\n", s->b_mni);
//	ft_printf("-----------------\n");
//	ft_printf("num of operations: %d\n\n", steps->holder->num);
//	ft_use_print_and_free(s, &steps);
//	s->flag = 1;
//	ft_print_stacks(s);
//	s->flag = 0;
//	return (0);
//}

/*
 * *********** *********** *********** *********** *********** ***********
 */

static void			ft_return_to_home(t_stack *stks)
{
	int 			index;

	index = 0;
	while (index < stks->size)
	{
		pa(stks);
		if (stks->flag != 1)
			ft_printf("pa\n");
		index++;
	}
}

static void 		ft_make_b_nice(t_stack *stks)
{
	int 			up_b;
	int 			down_b;
	int 			num;

	ft_set_min_max(stks);
	up_b = ft_up_b_helper(stks, stks->b_mxi);
	down_b = ft_down_b_helper(stks, stks->b_mxi);
	if (stks->b_mxi != 0)
	{
		if (up_b < down_b)
			num = up_b;
		else
			num = down_b;
		while (num)
		{
			if (up_b < down_b)
			{
				rb(stks);
				if (stks->flag == 0)
					ft_printf("rb\n");
			}
			else
			{
				rrb(stks);
				if (stks->flag == 0)
					ft_printf("rrb\n");
			}
			num--;
		}
	}
}



static t_oper		*ft_check_steps(t_stack *stks, int index)
{
	int				up_a;
	int				up_b;
	int				down_a;
	int				down_b;
	t_oper			*steps;

	ft_set_min_max(stks);
//	ft_printf("-----------------\n");
//	ft_printf("up_a: %d\n", up_a = ft_up_a(stks, index));
//	ft_printf("down_a: %d\n", down_a = ft_down_a(stks, index));
//	ft_printf("up_b: %d\n", up_b = ft_up_b(stks, index));
//	ft_printf("down_b: %d\n\n", down_b = ft_down_b(stks, index));
//	ft_printf("-----------------\n");
	up_a = ft_up_a(stks, index);
	down_a = ft_down_a(stks, index);
	up_b = ft_up_b(stks, index);
	down_b = ft_down_b(stks, index);
	steps = ft_merge_steps(up_a, down_a, up_b, down_b);
	int winner;
	winner = steps->holder->num;
	return (steps);
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
			num_oper = candidate->num;
			answer = candidate;
		}
		else if (candidate->num < num_oper)
		{
			ft_free_steps(&answer);
			num_oper = candidate->num;
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

//	return (ft_test_function(stks));
	index = 0;
	while (index < stks->size)
	{
		steps = NULL;
		if (index <= 1)
			steps = ft_add_step(steps, 4);
		else
		{
			alt = ft_check_push_to_top_b(stks);
			if (alt && alt->holder->num == 1)
				steps = alt;
			else
			{
				steps = ft_internal_loop(stks, index, index, 0);
				if (alt && alt->holder->num < steps->holder->num)
				{
					//free(steps);
//					ft_printf("ALTERNATE WON, num = %d\n", alt->holder->num);
//					ft_printf("loop, num = \n", steps->holder->num);
					steps = alt;
				}
				else
				{
//					if (alt)
//						ft_printf("alternate, num = %d\n", alt->holder->num);
//					else
//						ft_printf("alternate, num = NULL\n");
//					ft_printf("LOOP WON, num = \n", steps->holder->num);
					if (alt)
						free(alt);
				}
			}
		}
		ft_use_print_and_free(stks, &steps);
//		static int ind;
//		ft_printf("-----------------------------index %d\n", ind++);
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
	if (ft_main_algorithm(*&stks) == -1)
		return (-1);
	else
		return (1);
}
