/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 23:40:48 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/14 23:40:50 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void		ft_use_commands(int n, t_stack *stks)
{
	void		(*oper[11])(t_stack*);

	oper[1] = &sa;
	oper[2] = &sb;
	oper[3] = &ss;
	oper[4] = &pa;
	oper[5] = &pb;
	oper[6] = &ra;
	oper[7] = &rb;
	oper[8] = &rr;
	oper[9] = &rra;
	oper[0] = &rrb;
	oper[10] = &rrr;
	oper[n](stks);
}

static char		*ft_game_read(void)
{
	char		*argument;
	char		buf[1];

	if (read(0, buf, 1) == -1)
		return (NULL);
	argument = ft_strnew(2);
	ft_memcpy(argument, buf, 1);
	argument[1] = '\0';
	return (argument);
}

static int		ft_check_command(char *str)
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
	else
		return (-1);
}

void			ft_list_of_commands(void)
{
	ft_printf("game mode ON\n");
	ft_printf("- - - - - - - - - - - - - - - \n");
	ft_printf("(l) list of commands\n(q) quit\n");
	ft_printf("(s) sorted - check the order in stack a\n\n");
	ft_printf("Choose number(s) and press RETURN\n");
	ft_printf("You can run multiple commands at one time, "
	"for example: 6534765\\RETURN\n\n");
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
	ft_printf("- - - - - - - - - - - - - - - \n");
}

void			ft_game_mode(t_stack *stks)
{
	char		*argument;
	int			oper;

	ft_print_stacks(stks);
	ft_list_of_commands();
	while (1)
	{
		if ((argument = ft_game_read()) == NULL)
			break ;
		if (*argument == '\n')
		{
			free(argument);
			continue ;
		}
		if ((oper = ft_check_command(argument)) >= 0 && oper < 11)
			ft_use_commands(oper, stks);
		else if (oper == 11)
			break ;
		else if (oper == 12)
			ft_list_of_commands();
		else if (oper == 13)
			ft_printf("1/0 OK/KO\n%d\n", ft_isinorder(stks->stk_a, stks->size));
		free(argument);
	}
	ft_printf("GAME END\n");
}
