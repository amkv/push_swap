/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:51:21 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/16 14:51:23 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void			ft_print_list_of_commands(void)
{
	ft_printf("NEW GAME started\n- - - - - - - - - - - - - - - \n");
	ft_printf("(l) usage/HELP\n(o) used operators list\n");
	ft_printf("(s) is sorted? - check the stack order\n(=) print stacks\n");
	ft_printf("(h) print history of commands\n(n) new game\n(q) quit\n\n");
	ft_printf("Choose number(s) and press RETURN\n");
	ft_printf("You can run multiple commands at one time, "
					  "for example: 6534765 and hit RETURN\n\n");
	ft_printf("(1) sa   swap a - swap the first 2 elements"
					  " at the top of stack a\n");
	ft_printf("(2) sb   swap b - swap the first 2 elements"
					  " at the top of stack b\n");
	ft_printf("(3) ss   sa and sb at the same time\n");
	ft_printf("(4) pa   push a - take the first element"
					  " at the top of b and put it at the top of a\n");
	ft_printf("(5) pb   push b - take the first element"
					  " at the top of a and put it at the top of b\n");
	ft_printf("(6) ra   rotate a - shift up all elements of stack a by 1\n");
	ft_printf("(7) rb   rotate b - shift up all elements of stack b by 1\n");
	ft_printf("(9) rr   ra and rb at the same time\n");
	ft_printf("(9) rra  reverse rotate a - shift down all"
					  " elements of stack a by 1\n");
	ft_printf("(0) rrb  reverse rotate b - shift down all"
					  " elements of stack b by 1\n");
	ft_printf("(-) rrr  rra and rrb at the same time\n");
//	ft_printf("- - - - - - - - - - - - - - - \n");
}

static char		*ft_return_oper_name2(char *str)
{
	if (*str == 'l')
		return (ft_strdup("list of commands"));
	else if (*str == 's')
		return (ft_strdup("is sorted?"));
	else if (*str == '=')
		return (ft_strdup("print the staks"));
	else if (*str == 'h')
		return (ft_strdup("show log"));
	else if (*str == 'o')
		return (ft_strdup("history of operators"));
	else
		return (NULL);
}

char			*ft_return_oper_name(char *str)
{
	if (*str == '1')
		return (ft_strdup("sa"));
	else if (*str == '2')
		return (ft_strdup("sb"));
	else if (*str == '3')
		return (ft_strdup("ss"));
	else if (*str == '4')
		return (ft_strdup("pa"));
	else if (*str == '5')
		return (ft_strdup("pb"));
	else if (*str == '6')
		return (ft_strdup("ra"));
	else if (*str == '7')
		return (ft_strdup("rb"));
	else if (*str == '8')
		return (ft_strdup("rr"));
	else if (*str == '9')
		return (ft_strdup("rra"));
	else if (*str == '0')
		return (ft_strdup("rrb"));
	else if (*str == '-')
		return (ft_strdup("rrr"));
	else
		return (ft_return_oper_name2(str));
}

int				ft_check_game_command(char *str)
{
	if (*str == '1' || *str == '2' || *str == '3' || *str == '4' ||
		*str == '5' || *str == '6' || *str == '7' || *str == '8' ||
		*str == '9' || *str == '0')
		return (*str - '0');
	else if (*str == '-')
		return (10);
	else if (*str == 'q')
		return (11);
	else if (*str == 'l')
		return (12);
	else if (*str == 's')
		return (13);
	else if (*str == '=')
		return (14);
	else if (*str == 'h')
		return (15);
	else if (*str == 'o')
		return (16);
	else if (*str == 'n')
		return (17);
	else
		return (-1);
}
