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
	if (index == 0 || index == 1)
		return (ft_add_step(steps, 4));
	up_a = ft_up_a(stks, index);
	down_a = ft_down_a(stks, index);
	up_b = ft_up_b(stks, index);
//	down_b = ft_down_b(stks, index);
//	steps = ft_merge_steps(up_a, down_a, up_b, down_b); // merge and free
	steps = up_a;

	if (!steps)
		steps = ft_add_step(steps, 5);

//	steps = ft_add_step(NULL, 5);
	return (steps);
}

static int			ft_main_algorithm(t_stack *stks)
{
	int				external;
	int				internal;
	t_oper			*answers[stks->size];
	int				num_oper;
	int				winner;

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
//	if (ft_is_stack_in_order(stks) == 1) // не надо проверять, только для теста
//		ft_printf("отработало нормально\n");
//	else
//		ft_printf("накосячило нехило\n");
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
		while (index < stks->elems_b + 1)
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
