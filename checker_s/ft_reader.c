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

t_oper			*ft_new_oper(char *str)
{
	t_oper		*new;
	static int	index;

	new = (t_oper*)malloc(sizeof(t_oper) * 1);
	new->oper = str;
	new->index = ++index;
	new->next = NULL;
	return (new);
}

void			ft_add_oper(t_oper **commands, t_oper **new)
{
	if (*commands != NULL)
	{
		(*commands)->next = *new;
		*new = *commands;
	}
	else
		*commands = *new;
}

static int		ft_get_arg(char **argument)
{
	char 		buf[BUFF];

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

int				ft_read_arguments(t_oper *commands)
{
	t_oper		*new;
	char		*argument;
	int			error;

	commands = NULL;
	while (1)
	{
		error = ft_get_arg(&argument);
		if (error == -1)
			return (-1);
		if (error == 0)
			break ;
		if (error == 1)
		{
			new = ft_new_oper(argument);
			ft_add_oper(&commands, &new);
		}
	}
	return (1);
}
