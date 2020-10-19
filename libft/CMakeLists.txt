cmake_minimum_required(VERSION 3.14)

project(libft)

set(CMAKE_C_STANDARD 99)

add_library(libft STATIC ft_atoi.c ft_bzero.c ft_error.c ft_intcpy.c ft_memalloc.c ft_quicksort.c ft_strchr.c
        ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlen ft_memdel.c ft_strncpy.c ft_strdel.c ft_strsub.c ft_strnew.c
        ft_strsplit.c ft_swap.c get_next_line.c)