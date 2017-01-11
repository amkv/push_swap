cmake_minimum_required(VERSION 3.6)
project(checker)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -Wall -Wextra -Werror")

set(SOURCE_FILES
		main.c
		)


add_executable(checker ${SOURCE_FILES})
target_link_libraries(
		checker
		/nfs/2016/a/akalmyko/Documents/work/push_swap/libft/libft.a
		/nfs/2016/a/akalmyko/Documents/work/push_swap/shared_s/slib.a
)