/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:19:59 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/16 15:20:00 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void					ft_print_history(t_history *history, int flag)
{
	t_history			*copy;

	if (!history)
		return ;
	copy = history;
	ft_printf("HISTORY of operators:\n");
	while (copy)
	{
		if (copy->index == -1 && flag == 1)
		{
			if (copy->oper)
				ft_printf("   ");
		}
		else if (flag == 1)
			ft_printf("%d. ", copy->index);
		if (flag == 1 && copy->index == -1)
		{
			if (copy->oper)
				ft_printf("%s\n", copy->oper);
		}
		else if (copy->index != -1)
			ft_printf("%s\n", copy->oper);
		copy = copy->next;
	}
}

void					ft_clean_the_game_history(t_history **history)
{
	t_history			*copy;
	t_history			*holder;

	if (*history == NULL)
		return ;
	copy = *history;
	while (copy)
	{
		holder = copy->next;
		free(copy->oper);
		free(copy);
		copy = NULL;
		copy = holder;
	}
	*history = NULL;
	return ;
}

static t_history		*ft_new_history(char *argument)
{
	t_history			*new;
	static int			index;
	int					command;

	new = (t_history*)malloc(sizeof(t_history) * 1);
	new->oper = ft_return_oper_name(argument);
	command = ft_check_game_command(argument);
	if (command >= 0 &&  command <= 10)
		new->index = ++index;
	else
		new->index = -1;
	new->next = NULL;
	return (new);
}

t_history				*ft_add_history(t_history **history, char *argument)
{
	static t_history	*holder;
	t_history			*new;
	static int			flag;

	new = ft_new_history(argument);
	if (*history != NULL)
	{
		if (flag == 0)
			holder = *history;
		if (flag > 0)
		{
			holder->next = new;
			holder = new;
		}
		else
			(*history)->next = new;
		flag = 1;
	}
	else
		*history = new;
	return (*history);
}
