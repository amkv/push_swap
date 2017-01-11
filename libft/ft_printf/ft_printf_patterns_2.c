/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_patterns2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:19:00 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/15 16:19:01 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_pat_length(char **holder)
{
	char	*result;
	char	*new_holder;
	size_t	len;

	if (ft_is_length(**holder) == 0)
		return (NULL);
	len = 1;
	if (*(*holder + 1) == 'h' || *(*holder + 1) == 'l')
		len = 2;
	result = ft_strnew(len + 1);
	ft_memcpy(result, *holder, len);
	new_holder = ft_strdel_begn(*holder, len);
	ft_free_and_set(*&holder, &new_holder);
	return (result);
}

char		*ft_pat_modifier(char **holder)
{
	char	*modifier;
	char	*new_holder;

	if (!(*holder) || ft_is_modifier(**holder) == 0)
		return (NULL);
	if (ft_strlen(*holder) == 1)
	{
		modifier = ft_strdup(*holder);
		free(*holder);
		*holder = NULL;
		return (modifier);
	}
	modifier = ft_strnew(2);
	ft_memcpy(modifier, *holder, 1);
	new_holder = ft_strdel_begn(*holder, 1);
	ft_free_and_set(*&holder, &new_holder);
	return (modifier);
}

void		ft_pat_ending(t_com **fresh, char **holder)
{
	if ((*fresh)->modifier == NULL && *holder)
	{
		(*fresh)->scroll = ft_strdup(*holder);
		(*fresh)->len = ft_strlen((*fresh)->scroll);
		free(*holder);
		*holder = NULL;
	}
	else
		(*fresh)->type = '%';
}

void		ft_pat_string(t_com **com, char **copy, char **holder)
{
	t_com	*fresh;

	if (ft_strcmp(*copy, *holder) != 0)
	{
		fresh = ft_tcom_new();
		fresh->scroll = *holder;
		fresh->len = ft_strlen(*holder);
		ft_tcom_list(*&com, fresh);
		free(*copy);
	}
}
