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

//void				ft_use_and_add(t_oper **commands, t_stack *stks)
//{
//	static t_oper	*holder;
//	static int		flag;
//	t_oper			*new;
//
//	new = ft_new_oper(stks->last);
//	if (*commands != NULL)
//	{
//		if (flag == 0)
//			holder = new;
//		if (flag > 0)
//		{
//			holder->next = new;
//			holder = new;
//		}
//		else
//			(*commands)->next = new;
//		flag = 1;
//	}
//	else
//		*commands = new;
//}

//static int 			*ft_array_copy(int *array, int size)
//{
//	int 			index;
//	int 			*copy;
//
//	if (!array || size <= 0)
//		return (NULL);
//	if (!(copy = (int*)malloc(sizeof(int) * size)))
//		return (NULL);
//	index = 0;
//	while (index < size)
//	{
//		copy[index] = array[index];
//		index++;
//	}
//	return (copy);
//}

static void		ft_use_print_end_free(t_stack *stks, t_oper *answers)
{
	t_oper		*copy;
	t_oper		*holder;
	void		(*oper[11])(t_stack*);

	copy = answers;
	oper[0] = &sa;
	oper[1] = &sb;
	oper[2] = &ss;
	oper[3] = &pa;
	oper[4] = &pb;
	oper[5] = &ra;
	oper[6] = &rb;
	oper[7] = &rr;
	oper[8] = &rra;
	oper[9] = &rrb;
	oper[10] = &rrr;
	while (copy)
	{
		holder = copy->next;
		if (copy->command != -1)
			oper[copy->command](stks);
//		ft_printf("%s", copy->command);
		free(copy);
		copy = NULL;
		copy = holder;
	}
}

static void			ft_free_all_lists(t_oper *list)
{
	return ;
}

static int 			ft_spec_check_order(t_stack *stks)
{
	int 			index;
	int 			min;
	int 			min_index;

	index = 0;
	min_index = 0;
	min = stks->stk_a[0];
	while (index < stks->elems_a)
	{
		if (stks->stk_a[index] < min)
		{
			min = stks->stk_a[index];
			min_index = index;
		}
		index++;
	}

	return (0);
}

static int			ft_is_stack_in_decrease_order(int *b, int size)
{
	int 	index;

	index = 0;
	while (index < size)
	{
		if (index + 1 > size)
			break ;
		if (b[index] > b[index + 1])
			index++;
		else
			return (0);
	}
	return (1);
}

static t_oper 		*ft_check_steps(t_stack *stks, int index)
{
	t_oper 			*steps;
	int 			top_a;
	int 			elem_a;
	int 			top_b;
	int 			elem_b;

	top_a = stks->top_a - index;
	elem_a = stks->elems_a - index;
	top_a = stks->top_a + index;
	elem_a = stks->elems_a + index;

//	if (index == 0)
//	{
//
//	}


	steps = ft_new_oper("NULL");
	return (steps);
}

static int 			ft_main_algorithm(t_stack *stks)
{
	int 			external;
	int 			internal;
	t_oper			*answers[stks->size];
	int 			snum;
	int 			winner;

	ft_printf("something...\n");
	external = 0;
	while (external < stks->size)
	{
		internal = external;
		winner = 0;
		snum = 0;
		while (internal < stks->size)
		{
			answers[internal] = ft_check_steps(stks, internal);
			if (internal == external)
			{
				winner = internal;
				snum = answers[internal]->num;
			}
			else if (answers[internal]->num < snum)
			{
				free(answers[winner]); // необходимо очистить все листы
				winner = internal;
				snum = answers[internal]->num;
			}
			else
				free(answers[internal]); // необходимо очистить все листы
			internal++;
		}
		ft_use_print_end_free(stks, answers[winner]);
		external++;
	}
//	ft_return_numbers_to_home(stks);
//	if (ft_is_stack_in_order(stks) == 1) // не надо проверять, только для теста
//		ft_printf("отработало нормально\n");
//	else
//		ft_printf("накосячило нехило\n");
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
		return (ft_main_algorithm(*&stks));
	return (0);
}
