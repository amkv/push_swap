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

void		sa(t_stack *stks)
{
	int		top;

	ft_strcpy(stks->last, "sa");
	stks->opnum = 0;
	if (stks->elems_a < 2)
		return (ft_no_change(stks));
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
	int		top;

	ft_strcpy(stks->last, "sb");
	stks->opnum = 1;
	if (stks->elems_b < 2)
		return (ft_no_change(stks));
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
	stks->opnum = 2;
	if (stks->elems_a < 2 || stks->elems_b < 2)
		return (ft_no_change(stks));
	stks->buf_a = stks->flag;
	stks->flag = 0;
	sa(stks);
	sb(stks);
	stks->flag = stks->buf_a;
	ft_strcpy(stks->last, "ss");
	ft_print_stacks(stks);
}

/*
** push a - take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

void		pa(t_stack *stks)
{
	int		size;

	ft_strcpy(stks->last, "pa");
	stks->opnum = 3;
	if (stks->elems_b == 0)
		return (ft_no_change(stks));
	size = stks->size - 1;
	if (stks->top_a == size && stks->elems_a == 0)
		stks->stk_a[(stks->top_a)] = stks->stk_b[(stks->top_b)];
	else
	{
		stks->stk_a[((stks->top_a) - 1)] = stks->stk_b[(stks->top_b)];
		(stks->top_a)--;
	}
	if (stks->top_b != size)
		(stks->top_b)++;
	else
		stks->top_b = size;
	(stks->elems_b)--;
	(stks->elems_a)++;
	ft_print_stacks(stks);
}

/*
** push b - take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

void		pb(t_stack *stks)
{
	int		size;

	ft_strcpy(stks->last, "pb");
	stks->opnum = 4;
	if (stks->elems_a == 0)
		return (ft_no_change(stks));
	size = (stks->size - 1);
	if (stks->top_b == size && stks->elems_b == 0)
		stks->stk_b[(stks->top_b)] = stks->stk_a[(stks->top_a)];
	else
	{
		stks->stk_b[((stks->top_b) - 1)] = stks->stk_a[(stks->top_a)];
		(stks->top_b)--;
	}
	if (stks->top_a != size)
		(stks->top_a)++;
	else
		stks->top_a = size;
	(stks->elems_a)--;
	(stks->elems_b)++;
	ft_print_stacks(stks);
}
