cmake_minimum_required(VERSION 3.16)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap push_swap.c push_swap.h ./push_swap-master/includes/libft/libft.h)