/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 22:13:23 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/11 22:13:27 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** swap a - swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements).
*/

//static void		ft_set_operation_name(t_stack *stks, char *str)
//{
//	ft_strcpy(stks->last, str);
//}

void		sa(t_stack *stks)
{
	int 	top;

	ft_strcpy(stks->last, "sa");
	if (stks->elems_a < 2)
		return (ft_print_stacks(stks));
	top = stks->top_a;
	stks->buf_a = stks->stk_a[top];
	stks->stk_a[top] = stks->stk_a[top + 1];
	stks->stk_a[top + 1] = stks->buf_a;
	ft_print_stacks(stks);
}

/*
** swap b - swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements).
*/

void		sb(t_stack *stks)
{
	int 	top;

	ft_strcpy(stks->last, "sb");
	if (stks->elems_b < 2)
		return (ft_print_stacks(stks));
	top = stks->top_b;
	stks->buf_b = stks->stk_b[top];
	stks->stk_b[top] = stks->stk_b[top + 1];
	stks->stk_b[top + 1] = stks->buf_b;
	ft_print_stacks(stks);
}

/*
** sa and sb at the same time.
*/

void		ss(t_stack *stks)
{
	ft_strcpy(stks->last, "ss");
	stks->buf_a = stks->flag;
	stks->flag = 0;
	sa(stks);
	sb(stks);
	stks->flag = stks->buf_a;
	ft_print_stacks(stks);
}

/*
** push a - take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

//void	pa(t_stack *stks)
//{
//	int 	top_a;
//	int 	top_b;
//
//	if (points[3] == 0)
//		return (ft_print_stacks(stack_a, stack_b, points));
//	top_a = points[0];
//	top_b = points[2];
//	if (points[5] != top_a)
//		stack_a[top_a + 1] = stack_b[top_b];
//	else
//		stack_a[top_a] = stack_b[top_b];
//	points[0]--;
//	points[1]++;
//	points[0] = points[0];
//	points[3]--;
//	ft_print_stacks(stack_a, stack_b, points);
//}

void	pa(t_stack *stks)
{
	int 	top_a;
	int 	top_b;
	int 	size;

	ft_strcpy(stks->last, "pa");
	if (stks->elems_b == 0)
		return (ft_print_stacks(stks));
	top_a = stks->top_a;
	top_b = stks->top_b;
	size = stks->size;

//	int s0_a = stks->stk_a[0];
//	int s1_a = stks->stk_a[1];
//	int s2_a = stks->stk_a[2];
//	int s3_a = stks->stk_a[3];
//	int s4_a = stks->stk_a[4];
//
//	int s0_b = stks->stk_b[0];
//	int s1_b = stks->stk_b[1];
//	int s2_b = stks->stk_b[2];
//	int s3_b = stks->stk_b[3];
//	int s4_b = stks->stk_b[4];

	stks->stk_a[top_a - 1] = stks->stk_b[top_b];
	if (top_b == size - 1)
		;
	else
		(stks->top_b)--;



	(stks->elems_a)++;
	(stks->top_a)--;
	(stks->elems_b)--;
	ft_print_stacks(stks);
}

/*
** push b - take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

void	pb(t_stack *stks)
{
	int 	top_a;
	int 	top_b;
	int 	size;

	ft_strcpy(stks->last, "pb");
	if (stks->elems_a == 0)
		return (ft_print_stacks(stks));
	top_a = stks->top_a;
	top_b = stks->top_b;
	size = stks->size;

//	int s0_a = stks->stk_a[0];
//	int s1_a = stks->stk_a[1];
//	int s2_a = stks->stk_a[2];
//	int s3_a = stks->stk_a[3];
//	int s4_a = stks->stk_a[4];
//
//	int s0_b = stks->stk_b[0];
//	int s1_b = stks->stk_b[1];
//	int s2_b = stks->stk_b[2];
//	int s3_b = stks->stk_b[3];
//	int s4_b = stks->stk_b[4];

	if (top_b > 1)
	{
		stks->stk_b[top_b - 1] = stks->stk_a[top_a];
		(stks->top_b)--;
	}
	else if (top_b == 0)
	{
		stks->stk_b[top_b] = stks->stk_a[top_a];
	}
	(stks->top_a)++;
	(stks->elems_a)--;
	(stks->elems_b)++;
	ft_print_stacks(stks);
}
