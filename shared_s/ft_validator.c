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
		if (ft_strcmp(argv[0], "-v") == 0 && ft_strcmp(argv[1], "-v") == 0)
			return (-1);
		if (ft_strcmp(argv[0], "-g") == 0 && ft_strcmp(argv[1], "-g") == 0)
			return (-1);
	}
	if (ft_strcmp(argv[0], "-v") == 0)
		(*flags)[0] = 1;
	else if (argc > 2 && ft_strcmp(argv[1], "-v") == 0)
		(*flags)[0] = 1;
	if (ft_strcmp(argv[0], "-g") == 0)
		(*flags)[1] = 1;
	else if (argc > 2 && ft_strcmp(argv[1], "-g") == 0)
		(*flags)[1] = 1;
	*flag = *(flags)[0] + (*flags)[1];
	return (0);
}

static char		**ft_return_string(int *argc, char **argv)
{
	char		**string;
	int			size;
	int			index;

	if (*argc == 1)
	{
		string = ft_strsplit(argv[1], ' ');
		*argc = ft_count_words(argv[1], ' ');
	}
	else
	{
		size = *argc;
		string = (char**)malloc(sizeof(char*) * size);
		index = 0;
		while (index < size)
		{
			string[index] = ft_strnew(ft_strlen(argv[index + 1]));
			ft_strcpy(string[index], argv[index + 1]);
			index++;
		}
	}
	return (string);
}

int				ft_validator(int *argc, char **argv, int **tab, int **flags)
{
	int			index;
	char		**string;
	long long	number;
	int			atoi_error;
	int			flag;

	index = 0;
	*argc = *argc - 1;
	string = ft_return_string(*&argc, argv);
	if (ft_check_flags(*&flags, &flag, string, *argc) == -1)
		return (ft_free_2d_array(string, *argc));
	if (!(*tab = (int*)malloc(sizeof(int) * *argc)))
		return (ft_free_2d_array(string, *argc));
	while (index < *argc - flag)
	{
		number = ft_atoi_werror(string[index + flag], &atoi_error);
		if (number < MININT || number > MAXINT || atoi_error == 0)
			return (ft_free_2d_array(string, *argc));
		(*tab)[index] = (int)number;
		index++;
	}
	if ((ft_isduplicates(*tab, *argc - flag)) == -1)
		return (ft_free_2d_array(string, *argc));
	return (0);
}
