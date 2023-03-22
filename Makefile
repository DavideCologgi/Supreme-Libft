# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 09:01:51 by dcologgi          #+#    #+#              #
#    Updated: 2023/03/22 09:25:35 by dcologgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variabili di compilazione
NAME = lib/liblibft.a
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

# Directories
SOURCES_DIR = src
OBJECTS_DIR = obj
INCLUDES_DIR = includes
LIB_DIR = lib

# Sources & objects
SOURCES = ${wildcard ${SOURCES_DIR}/*.c}
OBJECTS = ${patsubst ${SOURCES_DIR}/%.c, ${OBJECTS_DIR}/%.o, ${SOURCES}}

all : ${OBJECTS_DIR} ${NAME}
	${CC} -o ft_libft -L./lib/ -llibft

# Crea directory per gli oggetti
${OBJECTS_DIR} :
	mkdir -p ${OBJECTS_DIR}

# Regola per la library
${NAME} : ${OBJECTS}
	@if [ ! -d ${LIB_DIR} ]; then mkdir -p ${LIB_DIR}; fi
	ar rcs ${NAME} ${OBJECTS}

# Compilazione oggetti
${OBJECTS_DIR}/%.o: ${SOURCES_DIR}/%.c
	${CC} -c -o $@ $< ${CFLAGS} -I${INCLUDES_DIR}

clean :
	${RM} ${OBJECTS_DIR}

fclean :
	${RM} ${NAME} libft
	@if [ -d ${OBJECTS_DIR} ]; then ${RM} ${OBJECTS_DIR}; fi

re : clean
	@if [ -d ${OBJECTS_DIR} ]; then ${RM} ${OBJECTS_DIR}; fi
	mkdir -p ${OBJECTS_DIR}
	${MAKE} all
