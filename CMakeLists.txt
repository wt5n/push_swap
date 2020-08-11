cmake_minimum_required(VERSION 3.14)

project(push_swap)

set(CMAKE_C_STANDARD 99)

include_directories(inc)

set(SRC_OPERATIONS init.c operations_2.c operations.c sorting_2.c sorting.c validation.c)


add_executable(push_swap push_swap.c inc/push_swap.h ${SRC_OPERATIONS})
add_executable(checker checker.c inc/push_swap.h ${SRC_OPERATIONS})
add_subdirectory(libft)
target_link_libraries(push_swap libft)
target_link_libraries(checker libft)
