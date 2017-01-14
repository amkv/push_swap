/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpres_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:52:57 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/11 12:52:59 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

int				ft_atoi_werror(const char *str, int *error)
{
	long long	result;
	long long	sign;

	sign = 1;
	result = 0;
	*error = 0;
	if (str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str == '-')
			sign = -1;
		if (*str == '+' || *str == '-')
			str++;
		while (ft_isdigit(*str))
		{
			result = 10 * result + (*str - '0');
			(*error)++;
			str++;
		}
	}
	result = result * sign;
	if (result < -2147483648 || result > 2147483647)
		return (*error = 0);
	return ((int)result);
}

void			ft_free_all(int *copy_tab, t_stack *stks)
{
	free(copy_tab); // можно ли его почистить прямо в stks (адрес же извествен?)
	if (stks)
	{
		free(stks->stk_b);
		free(stks);
	}
}

void			ft_no_change(t_stack *stks)
{
	if (stks->flag == 0)
		return ;
	ft_printf("%s - - - - - - - - - - - - - %d\n",
			  stks->last, (stks->step)++);
	ft_printf("%10s no change\n", stks->last);
}
