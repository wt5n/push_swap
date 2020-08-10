cmake_minimum_required(VERSION 3.16)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(checker operations.c operations_2.c checker.c validation.c init.c ./libft/libft.h push_swap.h)

add_executable(push_swap operations.c operations_2.c push_swap.c validation.c sorting.c sorting_2.c init.c ./libft/libft.h push_swap.h)
