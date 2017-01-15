/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 19:52:31 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/13 19:52:33 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

int					ft_command_index(char *str)
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

t_oper				*ft_new_oper(char *str)
{
	t_oper			*new;
	static int		index;

	new = (t_oper*)malloc(sizeof(t_oper) * 1);
	new->oper = str;
	new->command = 0;
	new->index = ++index;
	new->next = NULL;
	return (new);
}

void				ft_add_oper(t_oper **commands, t_oper **new)
{
	static t_oper	*holder;
	static int		flag;

	if (*commands != NULL)
	{
		if (flag == 0)
			holder = *new;
		if (flag > 0)
		{
			holder->next = *new;
			holder = *new;
		}
		else
			(*commands)->next = *new;
		flag = 1;
	}
	else
		*commands = *new;
}

int					ft_get_arg(char **argument)
{
	char			buf[BUFF];

	ft_bzero(buf, BUFF);
	if (read(0, buf, BUFF) == -1)
		return (-1);
	if (buf[0] != '\n' && buf[2] != '\n' && buf[3] != '\n')
		return (-1);
	if (buf[0] == '\n')
		return (0);
	*argument = ft_strnew(BUFF);
	ft_memcpy(*argument, buf, BUFF);
	return (1);
}

int					ft_read_arguments(t_oper **commands)
{
	t_oper			*new;
	char			*argument;
	int				error;

	*commands = NULL;
	while (1)
	{
		error = ft_get_arg(&argument);
		if (error == -1)
		{
			ft_free_commands(*&commands);
			return (-1);
		}
		if (error == 0)
			break ;
		new = ft_new_oper(argument);
		new->command = ft_command_index(argument);
		if (new->command == -1)
		{
			ft_free_commands(*&commands);
			return (-1);
		}
		ft_add_oper(*&commands, &new);
	}
	return (1);
}
