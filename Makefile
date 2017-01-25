# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 14:54:07 by akalmyko          #+#    #+#              #
#    Updated: 2017/01/24 12:47:36 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re push_swap checker

NAME1 = checker
NAME2 = push_swap
RMS = /bin/rm -rf
LIBFT_F = libft/
SHARED_F = shared_s/
PUSH_SWAP_F = push_swap_s/
CHECKER_F = checker_s/
CHECKER = $(NAME1)
PUSH_SWAP = $(NAME2)

all:
	@make -C $(LIBFT_F)
	@make -C $(SHARED_F)
	@make -C $(PUSH_SWAP_F)
	@make -C $(CHECKER_F)

$(NAME1):
	@if [ -e $(CHECKER) ]; then \
		make silent_re -C $(CHECKER_F); \
	else \
		make -C $(CHECKER_F); \
	fi

$(NAME2):
	@if [ -e $(PUSH_SWAP) ]; then \
		make silent_re -C $(PUSH_SWAP_F); \
	else \
		make -C $(PUSH_SWAP_F); \
	fi

clean:
	@echo "$(LIBFT_F) folder:\c"
	@make clean -C $(LIBFT_F)
	@echo "$(SHARED_F) folder:\c"
	@make clean -C $(SHARED_F)
	@echo "$(PUSH_SWAP_F) folder:\c"
	@make clean -C $(PUSH_SWAP_F)
	@echo "$(CHECKER_F) folder:\c"
	@make clean -C $(CHECKER_F)

fclean: clean
	@#echo "$(LIBFT_F) folder:\c"
	@make fclean -C $(LIBFT_F)
	@#echo "$(SHARED_F) folder:\c"
	@make fclean -C $(SHARED_F)
	@#echo "$(PUSH_SWAP_F) folder:\c"
	@make fclean -C $(PUSH_SWAP_F)
	@#echo "$(CHECKER_F) folder:\c"
	@make fclean -C $(CHECKER_F)
	@$(RMS) $(PUSH_SWAP) $(CHECKER)

re: fclean all

