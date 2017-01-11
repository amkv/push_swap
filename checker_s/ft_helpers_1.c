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

int		ft_atoi_werror(const char *str, int *error)
{
	int	result;
	int	sign;

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
	return (result * sign);
}
