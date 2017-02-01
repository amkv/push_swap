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

static void		ft_set_a(t_stack *stks, int *stack_a, int size)
{
	stks->stk_a = stack_a;
	stks->top_a = 0;
	stks->elems_a = size;
	stks->a_max = 0;
	stks->a_min = 0;
	stks->a_mxi = 0;
	stks->a_mni = 0;
}

static void		ft_set_b(t_stack *stks, int size)
{
	stks->stk_b = (int*)malloc(sizeof(int) * size);
	stks->top_b = size - 1;
	stks->elems_b = 0;
	stks->b_max = 0;
	stks->b_min = 0;
	stks->b_mxi = 0;
	stks->b_mni = 0;
}

static void		ft_set_helpers(t_stack *stks, int *flag, int size)
{
	stks->size = size;
	stks->buf_a = 0;
	stks->buf_b = 0;
	stks->flag = flag[0];
	stks->game = flag[1];
	stks->step = 0;
	stks->operations = 0;
	stks->clear = 0;
	stks->print_flag_a = 0;
	stks->print_flag_b = 0;
	ft_bzero(stks->last, 4);
	stks->opnum = -1;
}

t_stack			*ft_new_stks(int *stack_a, int size, int *flag)
{
	t_stack		*stks;

	if (!(stks = (t_stack*)malloc(sizeof(t_stack) * 1)))
		return (NULL);
	ft_set_a(stks, stack_a, size);
	ft_set_b(stks, size);
	if (!stks->stk_b)
	{
		free(stks);
		return (NULL);
	}
	ft_set_helpers(stks, flag, size);
	if (!flag[1])
		ft_print_stacks(stks);
	return (stks);
}
