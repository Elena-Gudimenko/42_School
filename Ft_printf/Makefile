# Name of the programa or library

NAME = libftprintf.a

# flags and Compilers

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Archives .c

SRCS =	$(SRCDIR)/ft_printf.c\
		$(SRCDIR)/print_char.c\
		$(SRCDIR)/parse_format.c\
		$(SRCDIR)/handle_specifier.c\
		$(SRCDIR)/ft_strlen.c\
		$(SRCDIR)/print_str.c\
		$(SRCDIR)/convert_int_to_str.c\
		$(SRCDIR)/convert_hex_to_str.c\
		$(SRCDIR)/convert_unsigned_to_str.c\
		$(SRCDIR)/convert_ptr_to_str.c\
		$(SRCDIR)/print_percentage.c

# Archives .o

OBJS = $(SRCS:$(SRCDIR)/%.c=%.o)

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# .c -> .o

%.o: $(SRCDIR)/%.c
		$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# clear

clean:
	rm -f $(OBJS)

# Full clean

fclean: clean
	rm -f $(NAME) 

# restart

re: fclean $(NAME)

.PHONY: all fclean clean re