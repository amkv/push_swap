/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_9.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:48:54 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/01 10:48:55 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** challenge for up and down variations
*/

t_oper			*ft_ua_ub(int ua, int ub)
{
	t_oper		*steps;
	int			num;

	steps = NULL;
	if (ua > ub)
		num = ua;
	else
		num = ub;
	while (num--)
	{
		if (ua > 0 && ub > 0)
		{
			steps = ft_add_step(steps, 7);
		}
		else
		{
			if (ua > 0)
				steps = ft_add_step(steps, 5);
			if (ub > 0)
				steps = ft_add_step(steps, 6);
		}
		ua--;
		ub--;
	}
	return (ft_add_step(steps, 4));
}

t_oper			*ft_da_db(int da, int db)
{
	t_oper		*steps;
	int			num;

	steps = NULL;
	if (da > db)
		num = da;
	else
		num = db;
	while (num--)
	{
		if (da > 0 && db > 0)
			steps = ft_add_step(steps, 10);
		else
		{
			if (da > 0)
				steps = ft_add_step(steps, 8);
			if (db > 0)
				steps = ft_add_step(steps, 9);
		}
		if (da > 0)
			da--;
		if (db > 0)
			db--;
	}
	return (ft_add_step(steps, 4));
}

t_oper			*ft_ua_db(int ua, int db)
{
	t_oper		*steps;
	int			num;

	steps = NULL;
	num = ua + db;
	while (num)
	{
		if (ua > 0)
			steps = ft_add_step(steps, 5);
		if (db > 0)
			steps = ft_add_step(steps, 9);
		if (ua > 0)
			ua--;
		if (db > 0)
			db--;
		num--;
	}
	return (ft_add_step(steps, 4));
}

t_oper			*ft_da_ub(int da, int ub)
{
	t_oper		*steps;
	int			num;

	steps = NULL;
	num = da + ub;
	while (num)
	{
		if (da > 0)
			steps = ft_add_step(steps, 8);
		if (ub > 0)
			steps = ft_add_step(steps, 6);
		da--;
		ub--;
		num--;
	}
	return (ft_add_step(steps, 4));
}

int				ft_candidates(int ua, int da, int ub, int db)
{
	int			candidate[5];
	int			index;
	int			winner;

	candidate[0] = ua - ub;
	if (candidate[0] < 0)
		candidate[0] = -candidate[0];
	candidate[1] = da - db;
	if (candidate[1] < 0)
		candidate[1] = -candidate[1];
	candidate[2] = ua + db;
	candidate[3] = da + ub;
	candidate[4] = candidate[0];
	index = 0;
	winner = 0;
	while (index < 4)
	{
		if (candidate[index] <= candidate[4])
		{
			candidate[4] = candidate[index];
			winner = index;
		}
		index++;
	}
	return (winner);
}
