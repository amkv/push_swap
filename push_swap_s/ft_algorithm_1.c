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

static t_oper		*ft_check_steps(t_stack *stks, int index)
{
	t_oper			*up_a;
	t_oper			*up_b;
	t_oper			*down_a;
	t_oper			*down_b;
	t_oper			*steps;

	steps = NULL;
	if (index == 0 || index == 1 )
		return (ft_add_step(steps, 4));
	if ((up_a = ft_up_a(stks, index)))
		ft_printf("up_a: %d\n", up_a->holder->num);
	else
		ft_printf("up_a: 0\n");
	if ((down_a = ft_down_a(stks, index)))
		ft_printf("down_a: %d\n", down_a->holder->num);
	else
		ft_printf("down_a: 0\n");
	if ((up_b = ft_up_b(stks, index)))
		ft_printf("up_b: %d\n", up_b->holder->num);
	else
		ft_printf("up_b: 0\n");
	if ((down_b = ft_down_b(stks, index)))
		ft_printf("down_b: %d\n\n", down_b->holder->num);
	else
		ft_printf("down_b: 0\n\n");
	steps = ft_merge_steps(up_a, down_a, up_b, down_b); // merge and free
	if (!steps)
		steps = ft_add_step(steps, 5);
	return (steps);
}

static int 			ft_test_function(t_stack *stks)
{
	t_oper			*steps;
	int 			i;
	int 			index;

	index = 5;
	steps = NULL;
	pb(stks);
	pb(stks);
	sb(stks);
	pb(stks);
	rrb(stks);
	pb(stks);
	pb(stks);

	stks->flag = 1;
	ft_print_stacks(stks);
	stks->flag = 0;
	ft_printf("num a: %d\n", stks->stk_a[index]);
	ft_printf("index: %d\n\n",  index);
	steps = ft_check_steps(stks, index);
	ft_printf("\nmax: %d\n", stks->b_max);
	ft_printf("mx_i: %d\n", stks->b_mxi);
	ft_printf("min: %d\n", stks->b_min);
	ft_printf("mn_i: %d\n", stks->b_mni);
	ft_printf("num of operations: %d\n\n", steps->holder->num);
	ft_use_print_and_free(stks, &steps);
	stks->flag = 1;
	ft_print_stacks(stks);
	stks->flag = 0;
	return (0);
}

//static t_oper		*ft_check_steps(t_stack *stks, int index)
//{
//	t_oper			*up_a;
//	t_oper			*up_b;
//	t_oper			*down_a;
//	t_oper			*down_b;
//	t_oper			*steps;
//
//	steps = NULL;
//	if (index == 0 || index == 1 )
//		return (ft_add_step(steps, 4));
//	up_a = ft_up_a(stks, index);
//	down_a = ft_down_a(stks, index);
//	up_b = ft_up_b(stks, index);
//	down_b = ft_down_b(stks, index);
//	steps = ft_merge_steps(up_a, down_a, up_b, down_b); // merge and free
//	steps = ft_add_step(steps, 4); // убрать в ft_merge_steps
//	return (steps);
//}

static int			ft_main_algorithm(t_stack *stks)
{
	int				external;
	int				internal;
	t_oper			*answers[stks->size];
	int				num_oper;
	int				winner;

	return (ft_test_function(stks));
	external = 0;
	while (external < stks->size)
	{
		internal = external;
		winner = external;
		num_oper = 0;
		while (internal < stks->size)
		{
			if (!(answers[internal] = ft_check_steps(stks, internal)))
				return (-1);
			if (external == 0 || external == 1)
				break ;
			if (internal == external)
			{
				winner = internal;
				num_oper = answers[internal]->num;
			}
			else if (answers[internal]->num < num_oper)
			{
				ft_free_steps(&answers[winner]);
				winner = internal;
				num_oper = answers[internal]->num;
			}
			else
				ft_free_steps(&answers[internal]);
			internal++;
		}
		ft_use_print_and_free(stks, &answers[winner]);
		external++;
	}
	return (1);
}

int					ft_push_swap(t_stack *stks)
{
	int			index;

	if (ft_is_stack_in_order(stks) == 1)
		return (1);
	else if (stks->size == 2)
	{
		sa(stks);
		ft_printf("sa\n");
		return (1);
	}
	else if (stks->size >= 3)
	{
		if (ft_main_algorithm(*&stks) == -1)
			return (-1);
		index = 0;
		while (index < stks->size)
		{
			pa(stks);
			if (stks->flag != 1)
				ft_printf("pa\n");
			index++;
		}
		return (1);
	}
	return (0);
}
