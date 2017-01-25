/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:15:15 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/23 13:15:18 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void			ft_use_print_and_free(t_stack *stks, t_oper **answers)
{
	t_oper		*copy;
	t_oper		*holder;
	void		(*oper[11])(t_stack*);

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
	copy = (*answers)->holder;
	while (copy)
	{
		holder = copy->next;
		oper[copy->command](stks);
		if (stks->flag != 1)
			ft_printf("%s\n", copy->oper);
		free(copy->oper);
		free(copy);
		copy = NULL;
		copy = holder;
	}
	*answers = NULL;
}

static char		*ft_return_step_name(int oper)
{
	if (oper == 0)
		return (ft_strdup("sa"));
	else if (oper == 1)
		return (ft_strdup("sb"));
	else if (oper == 2)
		return (ft_strdup("ss"));
	else if (oper == 3)
		return (ft_strdup("pa"));
	else if (oper == 4)
		return (ft_strdup("pb"));
	else if (oper == 5)
		return (ft_strdup("ra"));
	else if (oper == 6)
		return (ft_strdup("rb"));
	else if (oper == 7)
		return (ft_strdup("rr"));
	else if (oper == 8)
		return (ft_strdup("rra"));
	else if (oper == 9)
		return (ft_strdup("rrb"));
	else if (oper == 10)
		return (ft_strdup("rrr"));
	else
		return (NULL);
}

static t_oper	*ft_new_step(int oper)
{
	t_oper		*new;

	new = (t_oper*)malloc(sizeof(t_oper) * 1);
	if (!new)
		return (NULL);
	new->oper = ft_return_step_name(oper);
	if (!new->oper)
	{
		free(new);
		return (NULL);
	}
	new->command = oper;
	new->num = 1;
	new->holder = NULL;
	new->next = NULL;
	return (new);
}

t_oper			*ft_add_step(t_oper *step, int oper)
{
	t_oper		*new;

	if (!(new = ft_new_step(oper)))
		return (NULL);
	if (step)
	{
		step->next = new;
		new->holder = step->holder;
		step->holder->num = ++(step->holder->num);
		step = new;
	}
	else
	{
		new->holder = new;
		step = new;
	}
	return (step);
}

void			ft_free_steps(t_oper **list)
{
	t_oper		*copy;
	t_oper		*holder;

	copy = (*list)->holder;
	if (!copy)
		return ;
	while (copy)
	{
		holder = copy->next;
		free(copy->oper);
		free(copy);
		copy = holder;
	}
	*list = NULL;
}
