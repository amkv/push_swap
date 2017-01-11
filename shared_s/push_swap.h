/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:02:23 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/09 16:37:54 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
// delete
# pragma GCC diagnostic ignored "-Wunused-parameter"
# pragma GCC diagnostic ignored "-Wunused-function"


# include "../libft/libft/libft.h"

int		ft_isinorder(int *tab, int size);
void	ft_validator(int argc, char **argv, int *tab);
int		ft_atoi_werror(const char *str, int *error);
void 	ft_error(void);

#endif
