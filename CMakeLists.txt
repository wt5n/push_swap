cmake_minimum_required(VERSION 3.16)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap checker.c validation.c inc/*.c libft/ft_quicksort.c inc/libft.h)