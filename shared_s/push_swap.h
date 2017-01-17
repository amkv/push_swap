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
# define BUFF 4
# include "../libft/libft/libft.h"
//# pragma GCC diagnostic ignored "-Wunused-parameter"
//# pragma GCC diagnostic ignored "-Wunused-function"
//# pragma GCC diagnostic ignored "-Wunused-variable"
//# pragma GCC diagnostic ignored "-Wreturn-type"


typedef struct	s_stack
{
	int			*stk_a;			// стек *a
	int			*stk_b;			// стек *b
	int			top_a;			// номер ячейки вершины стека
	int			top_b;			// номер ячейки вершины стека
	int			elems_a;		// переменное количество элементов в массиве
	int			elems_b;		// переменное количество элементов в массиве
	int			size;			// размер массива (количество элементов всего)
	int			flag; 			// -v индикатор флага (0 - нет, 1 - есть)
	int			operations; 	// количество операций перемещения
	int 		step;			// шагов печати дебаг инфо
	int			buf_a;			// темповый буфер для манипуляций
	int			buf_b;			// темповый буфер для манипуляций
	int 		print_flag_a;	// флаг для печати пустых ячеек
	int 		print_flag_b;	// флаг для печати пустых ячеек
	int 		game;			// флаг для игрового режима
	char 		last[4];		// название последней команды
}				t_stack;

typedef struct	s_oper
{
	char			*oper;
	int 			index;
	int 			command;
	struct s_oper	*next;
}				t_oper;

typedef struct	s_history
{
	char				*oper;
	int 				index;
	struct s_history	*next;
}				t_history;

//int				ft_validator(int argc, char **argv, int *tab, int *flag);
//t_stack			*ft_new_stks(int *stack_a, int size, int flag);

int				ft_validator(int argc, char **argv, int *tab, int **flags);
t_stack			*ft_new_stks(int *stack_a, int size, int *flag);
int				ft_isinorder(int *tab, int size);
int				ft_isduplicates(int *tab, int size);
int				ft_atoi_werror(const char *str, int *error);
int				ft_read_arguments(t_oper **commands);
t_oper			*ft_new_oper(char *str);
void			ft_add_oper(t_oper **commands, t_oper **new);
int				ft_command_index(char *str);
int				ft_get_arg(char **argument);
void			ft_print_commands(t_oper *commands);
void			ft_print_stacks(t_stack *stks);
void			ft_free_all(int *tab, t_stack *stks, t_oper **commands, int *flags);
void			ft_free_commands(t_oper **commands);
void			ft_no_change(t_stack *stks);

void			ft_game_mode(t_stack *stks);
int				ft_game_act(char *argument, t_stack *stks, t_history *history);
void			ft_print_list_of_commands(void);
void			ft_print_history(t_history *history, int flag);
int				ft_check_game_command(char *str);
t_history		*ft_add_history(t_history **history, char *oper);
void			ft_clean_the_game_history(t_history **history);
char			*ft_return_oper_name(char *str);

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

#endif
