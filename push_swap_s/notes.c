/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:03:37 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/23 17:03:40 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int 			*ft_array_copy(int *array, int size)
{
	int 			index;
	int 			*copy;

	if (!array || size <= 0)
		return (NULL);
	if (!(copy = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	index = 0;
	while (index < size)
	{
		copy[index] = array[index];
		index++;
	}
	return (copy);
}

static int 			ft_spec_check_order(t_stack *stks)
{
	int 			index;
	int 			min;
	int 			min_index;

	index = 0;
	min_index = 0;
	min = stks->stk_a[0];
	while (index < stks->elems_a)
	{
		if (stks->stk_a[index] < min)
		{
			min = stks->stk_a[index];
			min_index = index;
		}
		index++;
	}

	return (0);
}

static int			ft_is_stack_in_decrease_order(int *b, int size)
{
	int 	index;

	index = 0;
	while (index < size)
	{
		if (index + 1 > size)
			break ;
		if (b[index] > b[index + 1])
			index++;
		else
			return (0);
	}
	return (1);
}

Инициализированный стэк.
- Проверить, является ли top_a самым большим числов в стеке stk_a
    и stk_b является пустым
    если так, то перенести его в stk_b (одна операция)
- Проверить, можно ли сделать хоть какую-то сортиро
