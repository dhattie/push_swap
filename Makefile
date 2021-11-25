NAME		= push_swap

BONUS_NAME	= checker

OPTFLAGS =	-O2
FLAGS =		-Wall -Wextra -Werror

LIST	= 		main.c	ft_atoi_modifed.c	ft_butterfly.c	ft_check_argv.c\
				ft_operations_stack.c	ft_push_stack.c	ft_sort_small_stack.c\
				ft_stack_rules.c	ft_stack_utils1.c	ft_stack_utils2.c	ft_validation_functions.c\
				ft_stack_utils3.c\

BONUS_LIST	= 	ft_atoi_modifed.c	ft_butterfly.c	ft_check_argv.c\
              	ft_operations_stack.c	ft_push_stack.c	ft_sort_small_stack.c\
              	ft_stack_rules.c	ft_stack_utils1.c	ft_stack_utils2.c	ft_validation_functions.c\
				ft_checker.c	ft_checker_commands.c\
				ft_stack_utils3.c\

OBJ			= $(patsubst %.c,%.o,$(LIST))

BONUS_OBJ	= $(patsubst %.c,%.o,$(BONUS_LIST))

D_FILES =	$(patsubst %.c,%.d,$(LIST))

DB_FILES =	$(patsubst %.c,%.d,$(BONUS_LIST))

HEAD =		push_swap.h

LIBFT =		libft/libft.a

%.o: %.c	$(HEAD) $(LIST)
	$(CC) $(FLAGS) -c $< -o $@

 include $(wildcard $(D_FILES))

$(NAME):	$(OBJ) $(HEAD)
			$(MAKE) -C libft
			gcc $(FLAGS) $(LIBFT) $(OBJ) -o $(NAME)

bonus:	$(BONUS_OBJ) $(HEAD)
			$(MAKE) -C libft
			gcc $(FLAGS) $(LIBFT) $(BONUS_OBJ) -o $(BONUS_NAME)

all:		$(NAME)

clean:
			$(MAKE) clean -C libft
			rm -f $(OBJ) $(BONUS_OBJ)

fclean:		clean
			$(MAKE) clean -C libft
			rm -f $(NAME) $(BONUS_NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus
