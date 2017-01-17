/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:42:02 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/17 14:42:03 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_is_stack_in_order(t_stack *stks)
{
	if (stks->elems_b == 0)
	{
		if (ft_isinorder(stks->stk_a, stks->size) == 1)
			return (1);
		else
			return (-1);
	}
	else
		return (-1);
}
