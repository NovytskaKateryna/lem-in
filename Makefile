# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 14:34:33 by knovytsk          #+#    #+#              #
#    Updated: 2018/01/24 14:34:35 by knovytsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS_PATH = srcs
OBJS_PATH = objs

SRCS = main.c line_analize.c description.c rooms.c links.c check.c errors.c \
        add_check.c find_path.c queue.c pass_ants.c path.c color_print.c \
        find_ways.c ant_queue.c
OBJS = $(addprefix $(OBJS_PATH)/,$(SRCS:.c=.o))
INCLUDES = -I includes
LIBINC = -I libft
LIBFT = -C libft

CC = gcc -Wall -Wextra -Werror -OFast -O3

all: $(NAME)

$(OBJS): | $(OBJS_PATH)

$(OBJS_PATH):
	@mkdir $(OBJS_PATH)

$(OBJS_PATH)/%.o: %.c
	@$(CC) -c $< $(INCLUDES) $(LIBINC) -o $@

$(NAME): $(OBJS)
	@echo "\033[33;1mCompilation of libft...\033[0m"
	@make $(LIBFT)
	@$(CC) -o $(NAME) $(OBJS) libft/libft.a
	@echo "\033[36;1mProgram is compiled\033[0m"

clean:
	@make clean $(LIBFT)
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf bin objs

fclean: clean
	@rm -f libft/libft.a
	@rm -f $(NAME)
	@echo "\033[32;1mCleaned\033[0m"

re: fclean all

vpath %.c $(SRCS_PATH)

.PHONY: clean fclean re all