 ########################################
 #				Makefile			    #
 ########################################

		#		Basics		#

NAME		=	fillit
CC			=	gcc
CFLAGS		+=	-Wall -Wextra -Werror
OFLAGS		=	-c $(CFLAGS)


		#  libs & link cmd	#
LIB_DIR		=	./lib/
LIB_LINKS	=	-lft -llist
LINK_LIBS	=	-L$(LIB_DIR) $(LIB_LINKS)


		#	  files/folders		#
OBJ_DIR		=	./obj
MAIN		=	main.c
CFILES		=	read_create.c	\
				list_pre_check.c
###OFILES		=	$(addprefix $(OBJ_DIR),$(SRC:.c=.o))
OFILES		= $(CFILES:.c=.o)


all: $(OFILES)
	$(CC) $(CFLAGS) $(MAIN) $(OFILES) -o $(NAME).a $(LINK_LIBS)

$(OFILES):
	$(CC) $(OFLAGS) $(CFILES)

clean:
	/bin/rm -rf $(OFILES)

fclean: clean
	/bin/rm -rf $(NAME).a

re: fclean all

.PHONY: all clean re fclean



#link main.c to libft.a
#gcc main.c -o fillmeup -L./libft/ -lft
#gcc main.c -o fillmeup -L./lib/ -lft -llist
