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

static t_oper 		*ft_check_steps(t_stack *stks, int index)
{
	t_oper 			*steps;

	steps = ft_new_oper("NULL");
	return (steps);
}

static int 			ft_main_algorithm(t_stack *stks)
{
	int 			index;
	t_oper			*answers[stks->size];
	int 			snum;
	int 			winner;

	ft_printf("something...\n");
	index = 0;
	snum = 0;
	winner = -1;
	while (index < stks->size)
	{
		answers[index] = ft_check_steps(stks, index);
		if (index == 0)
		{
			winner = index;
			snum = answers[index]->num;
		}
		else if (answers[index]->num < snum)
		{
			winner = index;
			snum = answers[index]->num;
		}
		index++;
	}

/*
 	index = 0;
 	while (index < stks->size)
 	{

 		index++;
 	}
*/

//	int bla = 0;
//	while (bla < stks->size)
//	{
//		ft_printf("%d\n", answers[bla]->index);
//		bla++;
//	}

	// free() answers // 2d array
	return (1);
}

static int			ft_if_2(t_stack *stks)
{
	sa(stks);
	ft_printf("sa\n");
	return (1);
}

int					ft_find_the_way(t_stack *stks)
{
	if (ft_is_stack_in_order(stks) == 1)
		return (1);
	else if (stks->size == 2)
		return (ft_if_2(*&stks));
	else if (stks->size == 3)
		return (ft_main_algorithm(*&stks));
	return (0);
}
