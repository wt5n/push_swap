NAME1	= push_swap

NAME2	= checker

CFLAGS 	= -Wall -Wextra -Werror

SRC1 	= push_swap.c validation.c operations.c operations_2.c sorting.c sorting_2.c init.c

SRC2 	= checker.c validation.c operations.c operations_2.c init.c

OBJSFD 	= temporary

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))

OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))

HDR 		= -I./inc

LIBFT_HDR 	= -I./libft

LIB_BINARY	= -L./libft -lft

LIBFT		= ./libft/libft.a

all: $(LIBFT) ./libft/libft.a $(NAME1) $(NAME2)


LIBFT		= ./libft/libft.a

$(LIBFT):
			make -C ./libft

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(NAME1): $(OBJS1) $(LIBFT) ./inc/push_swap.h
	gcc -g $(OBJS1) $(LIB_BINARY) -o $@

$(NAME2): $(OBJS2) $(LIBFT) ./inc/push_swap.h
	gcc -g $(OBJS2) $(LIB_BINARY) -o $@

clean:
	/bin/rm -f $(OBJS)
	rm -rf $(OBJSFD)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)
	make -C ./libft fclean

re: fclean all