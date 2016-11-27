 ########################################
 #				Makefile			    #
 ########################################

		#		Basics		#

NAME		=	fillit
CC			=	gcc
CFLAGS		+=	-Wall -Wextra -Werror -I headers/
OFLAGS		=	-c $(CFLAGS)


		#  libs & link cmd	#
LIB_DIR		=	./lib/
LIB_LINKS	=	-lftjoanna -llist
LINK_LIBS	=	-L $(LIB_DIR) $(LIB_LINKS)


		#	  files/folders		#
OBJ_DIR		=	./obj
MAIN		=	main.c
CFILES		=	read_create.c 
				# list_pre_check.c
###OFILES		=	$(addprefix $(OBJ_DIR),$(SRC:.c=.o))
OFILES		= $(CFILES:.c=.o)


all: $(NAME)


$(NAME): $(OFILES)
	$(CC) $(CFLAGS)  -o $(NAME) $(MAIN) $(OFILES) $(LINK_LIBS)

clean:
	/bin/rm -rf $(OFILES)

fclean: clean
	/bin/rm -rf $(NAME).a
re: fclean all

.PHONY: all clean re fclean



#link main.c to libft.a
#gcc main.c -o fillmeup -L./libft/ -lft
#gcc main.c -o fillmeup -L./lib/ -lft -llist
