cmake_minimum_required(VERSION 3.6)
project(push_swap)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES
		main.c
		ft_1_algorithm.c
		ft_2_if_3_numbers.c
		ft_3_if_5_numbers.c
		ft_5_main_functions_1.c
		ft_4_steps_manipulations.c
		ft_8_a_stack_rotation.c
		ft_9_b_stack_up_rotation.c
		ft_10_b_stack_down_rotation.c
		ft_6_index_checker.c
		ft_7_alternative_checker.c
		/nfs/2016/a/akalmyko/Documents/work/push_swap/shared_s/ft_operations_2.c
		)


add_executable(push_swap ${SOURCE_FILES})
target_link_libraries(
		push_swap
		/nfs/2016/a/akalmyko/Documents/work/push_swap/libft/libft.a
		/nfs/2016/a/akalmyko/Documents/work/push_swap/shared_s/slib.a
		)