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

static int			ft_to_be_on_top(t_stack *fake, int index)
{
	int		num_to_top;
	int		num_to_down;

	num_to_top = fake->top_a - index + 1;	// wrong
	num_to_down = fake->size - index;		// wrong
	if (num_to_top == 1)
		;
	return (0);
}

static t_stack		*ft_set_the_fake_values(t_stack *stks, int index)
{
	t_stack			*fake;

	if (!(fake = (t_stack*)malloc(sizeof(t_stack) * 1)))
		return (NULL);
	fake->size = stks->size;
	fake->stk_a = stks->stk_a;
	fake->stk_b = stks->stk_b;
	fake->top_a = index;
	fake->top_b = stks->top_b;
	fake->elems_a = stks->elems_a;
	fake->elems_b = stks->elems_b;
	return (fake);
}

static t_oper		*ft_check_steps(t_stack *stks, int index)
{
	t_oper			*steps;
	t_stack			*fake;
	int				number;

	steps = NULL;
	if (index == 0 || index == 1)
		return (ft_add_step(NULL, 4));
	if (!(fake = ft_set_the_fake_values(stks, index)))
		return (NULL);
	number = ft_to_be_on_top(fake, index); // parser start
	free(fake);
	steps = ft_add_step(NULL, 5);
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
