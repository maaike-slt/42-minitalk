# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msloot <msloot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 19:19:04 by msloot            #+#    #+#              #
#    Updated: 2024/04/25 21:54:20 by msloot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
CC = 	cc
RM = 	rm -rf

CFLAGS =	-Wall -Werror -Wextra
# CFLAGS +=	-g
# CFLAGS +=	-fsanitize=address

UNAME = $(shell uname)

# **************************************************************************** #
#	MAKEFILE	#

MAKEFLAGS += --silent

SHELL := bash

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	 LIB	#

LIBPATH =	./libft/
LIBNAME =	$(LIBPATH)libft.a
LIBINC =	-I$(LIBPATH)

# **************************************************************************** #
#	SOURCE	#

SRC_PATH =	./src/
OBJ_PATH =	./obj/
INC =		./inc/

SRC_NAME_SERVER = server.c
SRC_NAME_CLIENT = client.c

SRC_SERVER = $(addprefix $(SRC_PATH), $(SRC_NAME_SERVER))
SRC_CLIENT = $(addprefix $(SRC_PATH), $(SRC_NAME_CLIENT))

OBJ_NAME_SERVER =	$(SRC_NAME_SERVER:.c=.o)
OBJ_SERVER =		$(addprefix $(OBJ_PATH), $(OBJ_NAME_SERVER))
OBJ_NAME_CLIENT =	$(SRC_NAME_CLIENT:.c=.o)
OBJ_CLIENT =		$(addprefix $(OBJ_PATH), $(OBJ_NAME_CLIENT))

# *************************************************************************** #

define	progress_bar
	i=0
	while [[ $$i -le $(words $(SRC)) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	printf "$(B)]\r[$(GRE)"
endef

# *************************************************************************** #
#	RULES	#

all:		$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJ_SERVER) $(LIBNAME)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBNAME) $(LDFLAGS) -o $(NAME_SERVER)
	@printf "$(B)$(MAG)$(NAME_SERVER) compiled$(D)\n"

$(NAME_CLIENT):	$(OBJ_CLIENT) $(LIBNAME)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBNAME) $(LDFLAGS) -o $(NAME_CLIENT)
	@printf "$(B)$(MAG)$(NAME_CLIENT) compiled$(D)\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@) # 2> /dev/null || true
	$(CC) $(CFLAGS) $(LIBINC) -I$(INC) -c $< -o $@

$(LIBNAME):
	@$(MAKE) -C $(LIBPATH)
	@printf "\n"

clean:
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	@$(MAKE) clean -C $(LIBPATH)
	@echo "$(B)cleared$(D)"

fclean:		clean
	@$(RM) $(OBJ_PATH)
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) fclean -C $(LIBPATH)

re:			fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
