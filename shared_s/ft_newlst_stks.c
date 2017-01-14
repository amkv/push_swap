/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlst_stks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:28:00 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/12 18:28:01 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

t_stack			*ft_new_stks(int *stack_a, int size, int flag)
{
	t_stack		*stks;

	stks = (t_stack*)malloc(sizeof(t_stack) * 1);
	stks->stk_a = stack_a;
	stks->top_a = 0;
	stks->elems_a = size;
	stks->buf_a = 0;
	stks->stk_b = (int*)malloc(sizeof(int) * size);
	stks->top_b = size - 1;
	stks->elems_b = 0;
	stks->buf_b = 0;
	stks->flag = flag;
	stks->size = size;
	stks->step = 0;
	stks->operations = 0;
	stks->print_flag_a = 0;
	stks->print_flag_b = 0;
	ft_bzero(stks->last, 4);
	ft_print_stacks(stks);
	return (stks);
}
