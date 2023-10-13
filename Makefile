
NAME		= cub3d

LIB			:= -Llibft -lft

INCLUDE		:= -I./includes -Ilibft/src -Imlx

CFLAGS		:= $(INCLUDE) -fcommon -Wall -Wextra -Werror

LINKS	= -framework OpenGL -framework Appkit

ifeq ($(DB), 1)
	CFLAGS	+= -fsanitize=address -g3
endif

ifeq ($(LK), 1)
	CFLAGS	+= -fsanitize=leak -g3
endif

CC			:= gcc

NEWLINE 	= \e[1K\r

#------------------------COLORS------------------------#

DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
H_RED		= \033[0;101m
RESET		= \033[0m

#------------------------PATH--------------------------#

SRCS_PATH		:= src

OBJS_PATH		:= obj

LIBFT_PATH		:= libft

#------------------------FILES-------------------------#

MAIN		= main

#------------------------------------------------------#

# SRCS		:= $(addsuffix .c, $(addprefix $(SRCS_PATH)/$(BUILTINS_PATH)/, $(BUILTINS))
SRCS		+= $(addsuffix .c, $(addprefix $(SRCS_PATH)/, $(MAIN)))

OBJS		+= $(addsuffix .o, $(addprefix $(OBJS_PATH)/, $(MAIN)))

#------------------------------------------------------#

vpath %.c $(SRCS_PATH)/

$(OBJS_PATH)/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(NEWLINE)$(CYAN)Creating object file $@ from $<"

all:
	@mkdir -p $(OBJS_PATH)
	@make ${NAME}

${NAME} : ${OBJS}
	@printf "$(NEWLINE)$(RESET)\n"
	@make -C $(LIBFT_PATH)
	@${CC} ${CFLAGS} $^ -Lmlx -lmlx ${INCLUDE} ${LIB} ${LINKS} -o $@
	@echo "$(GREEN)$(NAME) was created$(RESET)"

clean :
	@make fclean -C $(LIBFT_PATH)
	@rm -rf $(OBJS_PATH)
	@echo "$(BLUE)$(NAME): $(CYAN)object files are cleaned$(RESET)"

fclean : clean
	@rm -rf ${NAME}
	@echo "$(BLUE)$(NAME): $(H_RED) $(NAME) was deleted $(RESET)"

re : fclean all
