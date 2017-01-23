/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 22:13:31 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/11 22:13:32 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** rotate a - shift up all elements of stack a by 1.
** The first element becomes the last one.
*/

void			ra(t_stack *stks)
{
	int			elems;
	int			top;

	ft_strcpy(stks->last, "ra");
	stks->opnum = 5;
	if (stks->elems_a < 2)
		return (ft_no_change(stks));
	elems = stks->elems_a;
	top = stks->top_a;
	stks->buf_a = stks->stk_a[top];
	while (elems > 0)
	{
		if ((top + 1) == stks->size - 1)
		{
			stks->stk_a[top] = stks->stk_a[top + 1];
			top++;
		}
		stks->stk_a[top] = stks->stk_a[top + 1];
		top++;
		elems--;
	}
	stks->stk_a[((stks->size) - 1)] = stks->buf_a;
	ft_print_stacks(stks);
}

/*
** rotate b - shift up all elements of stack b by 1.
** The first element becomes the last one.
*/

void			rb(t_stack *stks)
{
	int			elems;
	int			top;

	ft_strcpy(stks->last, "rb");
	stks->opnum = 6;
	if (stks->elems_b < 2)
		return (ft_no_change(stks));
	elems = stks->elems_b;
	top = stks->top_b;
	stks->buf_b = stks->stk_b[top];
	while (elems > 0)
	{
		if ((top + 1) < stks->size)
		{
			stks->stk_b[top] = stks->stk_b[top + 1];
			top++;
		}
		elems--;
	}
	stks->stk_b[((stks->size) - 1)] = stks->buf_b;
	ft_print_stacks(stks);
}

/*
**  ra and rb at the same time.
*/

void			rr(t_stack *stks)
{
	ft_strcpy(stks->last, "rr");
	stks->opnum = 7;
	if (stks->elems_a < 2 || stks->elems_b < 2)
		return (ft_no_change(stks));
	stks->buf_a = stks->flag;
	stks->flag = 0;
	ra(stks);
	rb(stks);
	stks->flag = stks->buf_a;
	ft_strcpy(stks->last, "rr");
	ft_print_stacks(stks);
}
