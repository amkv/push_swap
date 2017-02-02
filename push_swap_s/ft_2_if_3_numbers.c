/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:15:15 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/23 13:15:18 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** if 3 numbers
*/

//int				ft_eq_3(t_stack *stks)
//{
//	t_oper		*steps;
//
//	ft_set_min_max_a(stks);
//	steps = NULL;
//	if (stks->a_mxi == 1 && stks->a_mni == 0)
//	{
//		steps = ft_add_step(steps, 8);
//		steps = ft_add_step(steps, 0);
//	}
//	else if (stks->a_mxi == 0 && stks->a_mni == 2)
//	{
//		steps = ft_add_step(steps, 5);
//		steps = ft_add_step(steps, 0);
//	}
//	else if (stks->a_mxi == 0 && stks->a_mni == 1)
//		steps = ft_add_step(steps, 5);
//	else if (stks->a_mxi == 2 && stks->a_mni == 1)
//		steps = ft_add_step(steps, 0);
//	else if (stks->a_mxi == 1 && stks->a_mni == 2)
//		steps = ft_add_step(steps, 8);
//	ft_use_print_and_free(stks, &steps);
//	return (1);
//}

int				ft_eq_3(t_stack *stks)
{
	t_oper		*steps;

	ft_set_min_max_a(stks);
	steps = NULL;
	if (stks->a_mxi == stks->top_a + 1 && stks->a_mni == stks->top_a)
	{
		steps = ft_add_step(steps, 8);
		steps = ft_add_step(steps, 0);
	}
	else if (stks->a_mxi == stks->top_a && stks->a_mni == stks->top_a + 2)
	{
		steps = ft_add_step(steps, 5);
		steps = ft_add_step(steps, 0);
	}
	else if (stks->a_mxi == stks->top_a && stks->a_mni == stks->top_a + 1)
		steps = ft_add_step(steps, 5);
	else if (stks->a_mxi == stks->top_a + 2 && stks->a_mni == stks->top_a + 1)
		steps = ft_add_step(steps, 0);
	else if (stks->a_mxi == stks->top_a + 1 && stks->a_mni == stks->top_a + 2)
		steps = ft_add_step(steps, 8);
//	else if (stks->a_mxi == stks->top_a + 2 && stks->a_mni == stks->top_a)
//		steps = ft_add_step(steps, 8);
	ft_use_print_and_free(stks, &steps);
	return (1);
}
