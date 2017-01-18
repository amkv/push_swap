cmake_minimum_required(VERSION 3.6)
project(checker)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -Wall -Wextra -Werror")

set(SOURCE_FILES
		main.c
		ft_game_1.c
		ft_game_2.c
		ft_game_3.c
		ft_game_4.c
		)


add_executable(checker ${SOURCE_FILES})
target_link_libraries(
		checker
		/nfs/2016/a/akalmyko/Documents/work/push_swap/libft/libft.a
		/nfs/2016/a/akalmyko/Documents/work/push_swap/shared_s/slib.a
)