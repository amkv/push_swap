cmake_minimum_required(VERSION 3.6)
project(push_swap)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -Wall -Wextra -Werror")

set(SOURCE_FILES
		main.c
		ft_algorithm_1.c
		/nfs/2016/a/akalmyko/Documents/work/push_swap/shared_s/ft_commands.c
		)


add_executable(push_swap ${SOURCE_FILES})
target_link_libraries(
		push_swap
		/nfs/2016/a/akalmyko/Documents/work/push_swap/libft/libft.a
		/nfs/2016/a/akalmyko/Documents/work/push_swap/shared_s/slib.a
		)