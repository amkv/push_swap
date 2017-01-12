/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:02:23 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/09 16:37:54 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# define MAXINT 2147483647
# define MININT -2147483648
# include "../libft/libft/libft.h"
# pragma GCC diagnostic ignored "-Wunused-parameter"
# pragma GCC diagnostic ignored "-Wunused-function"

int		ft_validator(int argc, char **argv, int *tab, int *flag);
int		ft_isinorder(int *tab, int size);
int		ft_isduplicates(int *tab, int size);
int		ft_atoi_werror(const char *str, int *error);

void	ft_print_stacks(int *stack_a, int *stack_b, int *points, int flag);
void	sa(int *stack_a, int *points);
void	sb(int *stack_b, int *points);
void	ss(int *stack_a, int *stack_b, int *points);
void	pa(int *stack_a, int *stack_b, int *points);
void	pb(int *stack_a, int *stack_b, int *points);
void	ra(int *stack_a, int *points);
void	rb(int *stack_b, int *points);
void	rr(int *stack_a, int *stack_b, int *points);
void	rra(int *stack_a, int *points);
void	rrb(int *stack_b, int *points);
void	rrr(int *stack_b, int *points);

#endif
