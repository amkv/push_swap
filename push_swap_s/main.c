/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:39:12 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/10 16:44:46 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
 * PUSH_SWAP
 */

//static void		ft_print_list(void)
//{
//	while (index < num_com)
//	{
//		ft_printf("%s\n", commands[index]);
//		index++;
//	}
//}

void			ft_print_stacks(int *stack_a, int *stack_b, int *points, int flag)
{
	int 		size_index;
	int 		top_a;
	int 		elem_a;
	int 		top_b;
	int 		elem_b;

	if (flag == 0)
		return ;
	size_index = points[4] - 1;
	top_a = points[0];
	elem_a = points[1];
	top_b = points[2];
	elem_b = points[3];
	while (size_index > -1)
	{
		if (top_a < size_index)
			ft_printf("%d", stack_a[size_index]);

		ft_printf("%d   %d\n", stack_a[size_index], stack_b[size_index]);
		size_index--;
	}
	ft_printf("_   _\na   b\n");
}

static char 	**ft_find_best_way(int *stack_a, int size, int *num_com, int flag)
{
	int 		*stack_b;
	int 		*points;

	stack_b = (int*)malloc(sizeof(int) * size);
	points = (int*)malloc(sizeof(int) * 5);
	points[0] = 0;
	points[1] = size;
	points[2] = 0;
	points[3] = 0;
	points[4] = size;

	ft_print_stacks(stack_a, stack_b, points, flag);

//	sa(stack_a, points);
//	sb(stack_b, points);
//	ss(stack_a, stack_b, points);
//	pa(stack_a, stack_b, points);
//	pb(stack_a, stack_b, points);
//	ra(stack_a, points);
//	rb(stack_b, points);
//	rr(stack_a, stack_b, points);
//	rra(stack_a, points);
//	rrb(stack_b, points);
//	rrr(stack_b, points);

	free(stack_b);
	free(points);
	return (NULL);
}

int		main(int argc, char **argv)
{
	int *tab;
	int *copy_tab;
	int flag;
	char 	**commands;
	int 	num_com;

	if (argc <= 1)
		return (0);
	if (!(tab = (int*)malloc(sizeof(int) * argc - 1)))
		return (-1);
	copy_tab = tab;
	if (ft_validator(argc - 1, argv, *&tab, &flag) == -1)
		ft_putstr_fd("Error\n", 2);
	else if (ft_isinorder(tab, argc - flag - 1) == 1)
		ft_printf("");
	else
	{
		ft_printf("с этим надо что-то делать\n");
		commands = ft_find_best_way(*&copy_tab, argc - flag - 1, &num_com, flag);
	}
	free(copy_tab);
	return (0);
}