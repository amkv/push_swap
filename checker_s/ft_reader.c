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

t_oper		*ft_new_oper(char *str)
{
	t_oper	*new;

	new = (t_oper*)malloc(sizeof(t_oper) * 1);
	new->oper = str;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_oper		*ft_add_oper(t_oper *oper, t_oper *next)
{
	if (oper == NULL)
		oper = ft_new_oper(NULL);
	else
		oper->next = next;
	return (oper);
}

void		ft_read_arguments(void)
{
	char 	buf[BUFF];
	char 	*res;
	ssize_t num;
	t_oper	*operators;

	ft_bzero(buf, BUFF);
	while (1)
	{
		if ((num = read(0, buf, BUFF)) == -1)
		{
			ft_putstr_fd("Error", 2);
			break ;
		}
//		if (num > 4)
//			continue ;
		res = ft_strnew(BUFF);
		ft_memcpy(res, buf, BUFF);
		ft_printf("len: %d",  ft_strlen(buf));
		ft_bzero(buf, BUFF);
		if (ft_strcmp(res, "\n") == 0)
		{
			free(res);
			break ;
		}
		else
			res[3] = '\0';

		ft_printf("%s\n", res);
		res = NULL;
	}
}
