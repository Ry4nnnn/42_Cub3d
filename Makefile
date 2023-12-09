
NAME		= cub3d

LIBFLAGS	:= -Llibft -lft

INCLUDES	:= ./includes

MLXFLAG 	:= -I/usr/include -Imlx_linux 

CFLAGS		:= -fcommon -DNO_SHARED_MEMORY=1 -Wall -Wextra -Werror

# LINKS		= -framework OpenGL -framework Appkit

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	MLXFLAGS2	= -Lmlx_linux -lmlx_Linux -L/usr/lib -I/usr/include -Imlx_linux -lXext -lX11 -lm -lz -fsanitize=address -g3
endif
ifeq ($(UNAME), Darwin)
	MLXFLAGS2	= -lmlx -framework OpenGL -framework AppKit -Imlx
endif


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

SRCS_PATH		:= ./src

OBJS_PATH		:= ./obj

LIBFT_PATH		:= libft

#------------------------FILES-------------------------#

MAIN		= main parsing mlx_utils map_check utils init key_hook \
				draw draw_utils error_check exit init_floor_ceiling

#------------------------------------------------------#

SRCS		+= $(addsuffix .c, $(addprefix $(SRCS_PATH)/, $(MAIN)))

OBJS		+= $(addsuffix .o, $(addprefix $(OBJS_PATH)/, $(MAIN)))


#------------------------------------------------------#

# vpath %.c $(SRCS_PATH)/

all: $(NAME)

$(NAME) : $(OBJS)
	@printf "$(NEWLINE)$(RESET)\n"
	@make -C $(LIBFT_PATH)
	@make bonus -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) $(MLXFLAGS2) -I $(INCLUDES) -o $(NAME)
	@echo "$(GREEN) $(NAME) was created$(RESET)"

$(LIBFT) :
	@make -C $(LIBFT_PATH)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(MLXFLAG) -I $(INCLUDES) -c $< -o $@
	@printf "$(NEWLINE)$(CYAN)Creating object file $@ from $<"

clean :
	@make fclean -C $(LIBFT_PATH)
	@rm -rf $(OBJS_PATH)
	@echo "$(BLUE)$(NAME): $(CYAN)object files are cleaned$(RESET)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(BLUE)$(NAME): $(H_RED) $(NAME) was deleted $(RESET)"

re : fclean all
