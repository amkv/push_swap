# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 13:38:35 by akalmyko          #+#    #+#              #
#    Updated: 2017/01/12 18:30:46 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re silent_clean silent_fclean silent_re

NAME = push_swap
RM = /bin/rm -rfv
RMS = /bin/rm -rf
SHARED_F = ../shared_s/
SLIB = slib.a
LIBFT_F = ../libft/
LIBFT = libft.a
OUT = ../
CFILES = main.c ft_operations_1.c ft_operations_2.c ft_operations_3.c ft_print_stacks.c ft_newlst_stks.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@if [ ! -e $(SHARED_F)$(SLIB) ]; then \
		make silent_re -C $(SHARED_F); \
	fi
	@if [ ! -e $(LIBFT_F)$(LIBFT) ]; then \
		make silent_re -C $(LIBFT_F); \
	fi
	@if [ -e $(SHARED_F)$(SLIB) -a -e $(LIBFT_F)$(LIBFT) ]; then \
		echo "$(NAME) compiling... \c"; \
		gcc -Wall -Wextra -Werror -c $(CFILES); \
		gcc -Wall -Wextra -Werror $(OFILES) $(SHARED_F)$(SLIB) $(LIBFT_F)$(LIBFT) -o $(NAME); \
		cp $(NAME) $(OUT); \
		echo "$(NAME) compiled"; \
	else \
		echo "something wrong with $(LIBFT) or/and $SLIB) libraries"; \
	fi

clean:
	@$(RM) $(OFILES) | wc -l | tr '\n' ' ' && echo ft_*.o files deleted

fclean: clean
	@$(RM) $(NAME) | wc -l | tr '\n' ' ' && echo $(NAME) deleted

re: fclean all

silent_clean:
	@$(RMS) $(OFILES)

silent_fclean: silent_clean
	@$(RMS) $(NAME)

silent_re: silent_fclean all

