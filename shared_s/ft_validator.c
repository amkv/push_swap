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

static int		ft_atoi_werror(const char *str, int *error)
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

static int		ft_isduplicates(int *tab, int size)
{
	int			number;
	int			index1;
	int			index2;

	if (size <= 1)
		return (-1);
	index1 = 0;
	number = tab[index1];
	while (index1 < size)
	{
		number = tab[index1];
		index2 = index1;
		while (index2 < size)
		{
			if ((index2 + 1) < size)
			{
				if (tab[index2 + 1] == number)
					return (-1);
			}
			index2++;
		}
		index1++;
	}
	return (0);
}

static int		ft_check_flags(int **flags, int *flag, char **argv, int argc)
{
	*flags = (int*)malloc(sizeof(int) * 2);
	(*flags)[0] = 0;
	(*flags)[1] = 0;
	*flag = 0;
	if (argc > 2)
	{
		if (ft_strcmp(argv[1], "-v") == 0 && ft_strcmp(argv[2], "-v") == 0)
			return (-1);
		if (ft_strcmp(argv[1], "-g") == 0 && ft_strcmp(argv[2], "-g") == 0)
			return (-1);
	}
	if (ft_strcmp(argv[1], "-v") == 0)
		(*flags)[0] = 1;
	else if (argc > 2 && ft_strcmp(argv[2], "-v") == 0)
		(*flags)[0] = 1;
	if (ft_strcmp(argv[1], "-g") == 0)
		(*flags)[1] = 1;
	else if (argc > 2 && ft_strcmp(argv[2], "-g") == 0)
		(*flags)[1] = 1;
	*flag = *(flags)[0] + (*flags)[1];
	return (0);
}

int				ft_validator(int argc, char **argv, int *tab, int **flags)
{
	int			index;
	long long	number;
	int			atoi_error;
	int			flag;

	index = 0;
	if (ft_check_flags(*&flags, &flag, argv, argc) == -1)
		return (-1);
	while (index < argc - flag)
	{
		number = ft_atoi_werror(argv[index + flag + 1], &atoi_error);
		if (number < MININT || number > MAXINT || atoi_error == 0)
			return (-1);
		tab[index] = (int)number;
		index++;
	}
	if ((ft_isduplicates(tab, argc - flag)) == -1)
		return (-1);
	return (0);
}
