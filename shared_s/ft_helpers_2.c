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

int				ft_free_2d_array(char **array, int size)
{
	int			index;

	index = 0;
	if (!array)
		return (-1);
	while (index < size)
	{
		if (array[index])
			free(array[index]);
		index++;
	}
	free(array);
	return (-1);
}
