/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:51:28 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/11 12:51:29 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

int		ft_isinorder(int *tab, int size)
{
	int 		index;
	int 		number;

	if (size <= 1)
		return (0);
	index = 0;
	number = tab[index];
	index++;
	while (index < size)
	{
		if (number < tab[index])
			number = tab[index];
		else
			return (-1);
		size--;
		index++;
	}
	return (1);
}

void 	ft_error(void)
{
	ft_putstr_fd("Error", 2);
}

void	ft_validator(int argc, char **argv, int *tab)
{
	int			index;
	long long	number;
	int			result;
	int			error;

	index = 0;
	tab = (int*)malloc(sizeof(int) * argc);
	while (index < argc)
	{
		number = ft_atoi_werror(argv[index + 1], &error);
		if (number < -2147483648 || number > 2147483647)
			return (ft_error());
		if (error == 0)
			return (ft_error());
		tab[index] = (int)number;
		index++;
	}
	if ((result = ft_isinorder(tab, argc)) < 0)
		ft_printf("KO\n");
	else if (result > 0)
		ft_printf("OK\n");
	else if (result == 0)
		return (ft_error());
}
