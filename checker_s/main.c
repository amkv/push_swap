/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:38:47 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/10 15:31:58 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** CHECKER
*/

#include "../shared_s/push_swap.h"

int				ft_command_index(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (0);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ss\n") == 0)
		return (2);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (3);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (4);
	else if (ft_strcmp(str, "ra\n") == 0)
		return (5);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (6);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (7);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (8);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (9);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (10);
	else
		return (-1);
}

static void		ft_use_commands(t_oper *commands, t_stack *stks)
{
	t_oper		*copy;
	void		(*oper[11])(t_stack*);

	copy = commands;
	oper[0] = &sa;
	oper[1] = &sb;
	oper[2] = &ss;
	oper[3] = &pa;
	oper[4] = &pb;
	oper[5] = &ra;
	oper[6] = &rb;
	oper[7] = &rr;
	oper[8] = &rra;
	oper[9] = &rrb;
	oper[10] = &rrr;
	while (copy)
	{
		oper[copy->command](stks);
		copy = copy->next;
	}
	if (ft_isinorder(stks->stk_a, stks->size) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static void		ft_game_mode(t_stack *stks)
{

	return ;
}

int				main(int argc, char **argv)
{
	int			*tab;
	int			flag;
	t_stack		*stks;
	t_oper		*commands;

	if (argc <= 1)
		return (0);
	if (!(tab = (int*)malloc(sizeof(int) * argc - 1)))
		return (-1);
	stks = NULL;
	commands = NULL;
	if (ft_validator(argc - 1, argv, *&tab, &flag) == -1)
		ft_putstr_fd("Error\n", 2);
	else
	{
		stks = ft_new_stks(*&tab, argc - flag - 1, flag);
		if (stks->game == 1)
			ft_game_mode(stks);
		else if (ft_read_arguments(&commands) == -1)
			ft_putstr_fd("Error\n", 2);
		else
			ft_use_commands(commands, stks);
	}
	ft_free_all(tab, stks, &commands);
	return (0);
}
