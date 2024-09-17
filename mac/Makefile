NAME = cub3d
CC = cc
CFLAG = -MMD -g3 -O3 -ffast-math
LIBFTDIR = ./libft
MLXDIR = ./minilibx-linux

# Detect operating system
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    MLXFLAG = -L$(MLXDIR) -lmlx -L/usr/lib -lXext -lX11 -lm
    MLXINC = -I$(MLXDIR)
else ifeq ($(UNAME_S),Darwin)
    MLXDIR = ./minilibx_opengl_20191021
    MLXFLAG = -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib -lX11
    MLXINC = -I$(MLXDIR) -I/usr/X11/include
endif

FILES = main.c init.c init_utils.c mlx_main.c raycasting.c controls.c utils.c \
		algorithms.c

SRCS_DIR := ./src
OBJS_DIR := ./poubelle

SRCS := $(addprefix $(SRCS_DIR)/, $(FILES)) 
OBJS := $(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))
DEPS := $(OBJS:.o=.d)

HEADERS := ./include

# List of subdirectories in which to create object files
OBJ_SUBDIRS := $(sort $(dir $(OBJS)))

all : $(NAME)

$(NAME): $(OBJS)
	@make --silent -C ${LIBFTDIR}
	@make --silent -C ${MLXDIR}
	@$(CC) -I$(HEADERS) $(MLXINC) -o $@ $(OBJS) -L$(LIBFTDIR) -lft $(MLXFLAG) $(LDFLAG) $(CFLAG)

# Create object directories
$(OBJS_DIR) $(OBJ_SUBDIRS):
	@mkdir -p $@

-include $(DEPS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_SUBDIRS)
	@printf "$(LBLUE)[Compilation]$(RESET) In progress... $(GREEN)$<" && \
	$(CC) $(CFLAG) -I$(HEADERS) $(MLXINC) -c $< -o $@ && \
	printf "\r$(LBLUE)[Compilation]$(RESET) Completed   ... $(GREEN)$<" && \
	printf "\n"

clean:
	@make clean -C ${LIBFTDIR}
	@make clean -C ${MLXDIR}
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C ${LIBFTDIR}
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
