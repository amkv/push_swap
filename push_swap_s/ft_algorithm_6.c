/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:19:10 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/25 17:19:11 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
	int 		ua_ub; candidate[0]
	int 		ua_db; candidate[1]
	int 		da_db; candidate[2]
	int 		da_ub; candidate[3]
*/

static t_oper	*ft_ua_ub(int ua, int ub)
{
	t_oper		*steps;
	int 		num;

	steps = NULL;
	if (ua > ub)
		num = ua;
	else
		num = ub;
	while (num)
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
		num--;
	}
	return (steps);
}

static t_oper	*ft_da_db(int da, int db)
{
	t_oper		*steps;
	int 		num;

	steps = NULL;
	if (da > db)
		num = da;
	else
		num = db;
	while (num)
	{
		if (da > 0  && db > 0 )
			steps = ft_add_step(steps, 10);
		else
		{
			if (da > 0 )
				steps = ft_add_step(steps, 8);
			if (db > 0 )
				steps = ft_add_step(steps, 9);
		}
		if (da > 0)
			da--;
		if (db > 0)
			db--;
		num--;
	}
	return (steps);
}

static t_oper	*ft_ua_db(int ua, int db)
{
	t_oper		*steps;
	int 		num;

	steps = NULL;
	num = ua + db;
	while (num)
	{
		if (ua > 0 )
			steps = ft_add_step(steps, 5);
		if (db > 0 )
			steps = ft_add_step(steps, 9);
		if (ua > 0)
			ua--;
		if (db > 0)
			db--;
		num--;
	}
	return (steps);
}

static t_oper	*ft_da_ub(int da, int ub)
{
	t_oper		*steps;
	int 		num;

	steps = NULL;
	num = da + ub;
	while (num)
	{
		if (da > 0)
			steps = ft_add_step(steps, 5);
		if (ub > 0)
			steps = ft_add_step(steps, 9);
		da--;
		ub--;
		num--;
	}
	return (steps);
}

static int		ft_candidates(int ua, int da, int ub, int db)
{
	int 		candidate[4];
	int 		index;
	int 		winner;
	int 		min;

	if (ua > ub)
		candidate[0] = ua;
	else
		candidate[0] = ub;
	if (da > db)
		candidate[1] = da;
	else
		candidate[1] = db;
	candidate[2] = ua + db;
	candidate[3] = da + ub;
	min = candidate[0];
	index = 0;
	winner = 0;
	while (index < 4)
	{
		if (min > candidate[index])
			winner = index;
		index++;
	}
	return (winner);
}

t_oper 			*ft_merge_steps(int ua, int da, int ub, int db)
{
	t_oper		*steps;
	int 		winner;

	steps = NULL;
	winner = ft_candidates(ua, da, ub, db);
	if (winner == 0)
		steps = ft_ua_ub(ua, ub);
	else if (winner == 1)
		steps = ft_da_db(da, db);
	else if (winner == 2)
		steps = ft_ua_db(ua, db);
	else if (winner == 3)
		steps = ft_da_ub(da, ub);
	return (ft_add_step(steps, 4));
}
