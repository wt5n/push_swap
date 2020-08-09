cmake_minimum_required(VERSION 3.16)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap ft_intcpy.c ./libft/get_next_line.c ./libft/ft_strcmp.c operations.c checker.c validation.c push_swap.h)
