#	Makefile for ft_printf program. 
#
#	Variables
#
	#	File name

NAME=libftprintf.a

	# Libft files
LIB=./libft
LIBFT = $(LIB)/libft.a

	# Source files
SRC=./format_char.c \
	./format_hexa_l.c \
	./format_hexa_u.c \
	./format_int.c \
	./format_ptr.c \
	./format_str.c \
	./format_unsigned.c \
	./ft_printf.c 
	# Objects
OBJECTS=$(SRC:.c=.o)
# Compiler 
CC=gcc

# Flags
FLAGS=-Wall -Wextra -Werror

#
# Compilation itself
#

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@cp $(LIBFT) $@
	@ar rcs $(NAME) $(OBJECTS)
	@echo "\033[0;31m$(NAME) created\033[0m"

$(LIBFT):
	@make -C $(LIB)

%.o: %.c %.h
	@$(CC) $(FLAGS) $< -c -o $@

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all

so: $(OBJECTS)
	@$(CC) $(FLAGS) -shared -fpic $(OBJECTS) -o $(NAME:.a=.so)
