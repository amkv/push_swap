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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAXINT 2147483647
# define MININT -2147483648
# include "../libft/libft/libft.h"

typedef struct	s_stack
{
	int			*stk_a;
	int			*stk_b;
	int			top_a;
	int			top_b;
	int			elems_a;
	int			elems_b;
	int			size;
	int			flag;
	int			operations;
	int			step;
	int			buf_a;
	int			buf_b;
	int			print_flag_a;
	int			print_flag_b;
	int			game;
	int			clear;
	char		last[4];
	int			opnum;
	int			a_max;
	int			a_mxi;
	int			a_min;
	int			a_mni;
	int			b_max;
	int			b_mxi;
	int			b_min;
	int			b_mni;
}				t_stack;

typedef struct	s_oper
{
	char			*oper;
	int				command;
	int				num;
	struct s_oper	*holder;
	struct s_oper	*next;
}				t_oper;

typedef struct	s_history
{
	char				*oper;
	int					index;
	struct s_history	*first;
	struct s_history	*next;
}				t_history;

/*
** shared functions
*/
int				ft_validator(int *argc, char **argv, int **tab, int **flags);
t_stack			*ft_new_stks(int *stack_a, int size, int *flag);
int				ft_isinorder(int *tab, int size);
int				ft_is_stack_in_order(t_stack *stks);
void			ft_free_all(
				int *tab, t_stack *stks, t_oper **commands, int *flags);
void			ft_print_stacks(t_stack *stks);
void			ft_no_change(t_stack *stks);
void			ft_free_commands(t_oper **commands);
int				ft_count_words(const char *str, char c);
int				ft_free_2d_array(char **array, int size);
void			sa(t_stack *stks);
void			sb(t_stack *stks);
void			ss(t_stack *stks);
void			pa(t_stack *stks);
void			pb(t_stack *stks);
void			ra(t_stack *stks);
void			rb(t_stack *stks);
void			rr(t_stack *stks);
void			rra(t_stack *stks);
void			rrb(t_stack *stks);
void			rrr(t_stack *stks);
/*
** push_swap
*/
int				ft_eq_2(t_stack *stks);
int				ft_eq_3(t_stack *stks, t_oper *steps, int incident);
int				ft_eq_5(t_stack *stks, int incident);
int				ft_push_swap(t_stack *stks);
void			ft_make_b_nice(t_stack *stks);
void			ft_make_a_nice(t_stack *stks);
void			ft_return_to_home(t_stack *stks);
t_oper			*ft_add_step(t_oper *step, int oper);
void			ft_free_steps(t_oper **list);
void			ft_use_print_and_free(t_stack *stks, t_oper **answers);
int				ft_candidates(int ua, int da, int ub, int db);
t_oper			*ft_da_ub(int da, int ub);
t_oper			*ft_ua_db(int ua, int db);
t_oper			*ft_da_db(int da, int db);
t_oper			*ft_ua_ub(int ua, int ub);
void			ft_set_min_max_a(t_stack *stks);
void			ft_set_min_max_b(t_stack *stks);
t_oper			*ft_check_push_to_top_b(t_stack *s);
int				ft_up_a(t_stack *stks, int index);
int				ft_down_a(t_stack *stks, int index);
int				ft_up_b(t_stack *s, int i);
int				ft_down_b(t_stack *s, int index);
int				ft_up_b_helper(t_stack *stks, int index);
int				ft_down_b_helper(t_stack *stks, int index);
void			ft_make_nice_a_and_say_bye_to_b(t_stack *stks);
/*
** checker, game mode -g
*/
t_oper			*ft_new_oper(char *str);
void			ft_add_oper(t_oper **commands, t_oper **new);
void			ft_print_commands(t_oper *commands);
void			ft_game_mode(t_stack *stks);
int				ft_game_act(char *argument, t_stack *stks, t_history *history);
void			ft_print_list_of_commands(void);
void			ft_print_history(t_history *history, int flag);
int				ft_check_game_command(char *str);
t_history		*ft_add_history(t_history **history, char *argument);
void			ft_clean_the_game_history(t_history **history);
char			*ft_return_oper_name(char *str);

#endif
