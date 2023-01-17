# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 13:01:59 by bloisel           #+#    #+#              #
#    Updated: 2023/01/17 17:39:45 by bloisel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFTNAME = libft.a
MLXNAME = libmlx.a
PTFNAME = libftprintf.a

CFLAGS =-Wall -Werror -Wextra
MLXFLAGS = -framework AppKit -framework OpenGL -L ./minilibx -lmlx -Imlx
DEBUG = -g -O0

SRCS = srcs/main.c \
		srcs/read_map.c \
		srcs/check_ber.c \
		srcs/check_ber1.c \
		srcs/check_ber2.c \
		srcs/p_pictures.c \
		srcs/p_mouvement.c \
		srcs/ft_exit.c \
		srcs/init_window.c 

OBJS	= $(SRCS:.c=.o)


LIBFTPATH = ./libft/
MLXPATH = ./minilibx/
PTFPATH = ./ft_printf/

.c.o :
	@echo "${_BOLD}${_BLUE}to > .o :${_YELLOW} ${<:.c=.o} ${_END}"
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

all: $(NAME)

${NAME} : $(OBJS)
	@echo "${_BOLD}${_BLUE}make de : ${LIBFNAME} ${MLXNAME} ${PTFNAME} ${_END}"
	@make -C ${LIBFTPATH}
	@make -C ${MLXPATH}
	@make -C ${PTFPATH}
	@echo "${_BOLD}${_GREEN}Done${_END}"
	@echo "${_BOLD}${_BLUE}Depacement des *.a to ./${_END}"
	@mv $(LIBFTPATH)${LIBFTNAME} ./ 
	@mv $(MLXPATH)${MLXNAME} ./
	@mv $(PTFPATH)${PTFNAME} ./
	@echo "${_BOLD}${_GREEN}Done${_END}"
	@echo "${_BOLD}${_BLUE}Comilation ...${_END}"
	@${CC} ${CFLAGS} ${MLXFLAGS} ${OBJS} ${LIBFTNAME} ${PTFNAME} ${MLXNAME} -o ${NAME}
	@echo "${_BOLD}${_GREEN}Done 🙈${_END}"

clean:
	@echo "${_BOLD}${_BLUE}rm *.o${_END}"
	@rm -rf *.o
	@echo "${_BOLD}${_GREEN}Done${_END}"

fclean:clean
	@echo "${_BOLD}${_BLUE}fclean de : ${_YELLOW}libft / printf / minilibx${_END}"
	@make fclean -C ${LIBFTPATH}
	@make fclean -C ${PTFPATH}
	@echo "${_BOLD}${_GREEN}Done${_END}"
	@echo "${_BOLD}${_BLUE} rm de : ${_YELLOW}$(MLXNAME) $(LIBFTNAME) $(PTFNAME) $(OBJS) $(NAME) ${_END}"
	@rm -rf $(MLXNAME) $(LIBFTNAME) $(PTFNAME) $(OBJS) $(NAME)
	@echo "${_BOLD}${_GREEN}Done${_END}"

fclean_all:clean
	rm -rf $(MLXNAME) $(LIBFTNAME) $(OBJS) $(NAME)

re: fclean all

ree: fclean all
	./so_long maps/map_ok_huge.ber


# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m