# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpladet <gpladet.student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 22:23:39 by gpladet           #+#    #+#              #
#    Updated: 2020/10/08 16:54:17 by gpladet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
COMP = nasm
COMP_FLAG = -f macho64

SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS:.s=.o}}

all : ${NAME}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

${OBJS_PATH}%.o : ${SRCS_PATH}%.s
	@mkdir ${OBJS_PATH} 2> /dev/null || true
	${COMP} ${COMP_FLAG} $< -o $@

clean :
	@rm -rf ${OBJS_PATH}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

