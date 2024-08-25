NAME = cub3d
CC = cc
CFLAG = -MMD -g3 -Wall -Wextra -Werror 
LDFLAG = -lreadline -lncurses -lm
LIBFTDIR = ./libft

FILES = main.c init.c init_utils.c mlx_main.c

SRCS_DIR := ./src
OBJS_DIR := ./poubelle

SRCS := $(addprefix $(SRCS_DIR)/, $(FILES)) 
OBJS := $(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))
DEPS := $(OBJS:.o=.d)

HEADERS := ./include

# COLOR #
GREEN	:= \033[38;5;76m
RED		:= \033[38;5;160m
YELLOW	:= \033[38;5;226m
ORANGE	:= \033[38;5;202m
PURPLE	:= \033[38;5;213m
LBLUE	:= \033[38;5;51m
BLUE	:= \033[38;5;117m
INDI	:= \033[38;5;99m
RESET	:= \033[00m

# List of subdirectories in which to create object files
OBJ_SUBDIRS := $(sort $(dir $(OBJS)))

all : $(NAME)

$(NAME): $(OBJS)
	@make --silent -C ${LIBFTDIR}
	@$(CC)  -I$(HEADERS) -o $@ $(OBJS) -L$(LIBFTDIR) -lft $(LDFLAG) $(CFLAG)
	@printf "$(RED)"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠹⢿⡿⠏⢻⢿⠉⣿⣰⡟⠈⠘⠀⠀⠀⠀⠀⠰⠁⠘⠀⠘⠀⣿⠏⠀⢸⠃⢁⡛⣼⣿⣿⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣯⣿⣿⣿⠿⣿⣿⣿⡽⠝⢿⣿⡄⠘⠃⠀⠟⠀⠀⠘⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠁⠀⠀⢁⡟⢃⠁⣻⣿⡿⣿⡏⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣧⡀⢻⣿⠇⠀⠈⠃⠇⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⢧⠙⢐⣿⣿⡿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⢏⠔⣹"
	@echo "⣿⣿⣿⣿⣿⡟⢿⡈⠑⡀⠂⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⣼⡟⡻⣷⣿⣿⣿⣿⣿⣿⣿⣿⡿⠣⢁⣮⡟"
	@echo "⣿⣿⣿⣿⣿⣦⡕⢷⢁⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢀⣿⢋⣾⣿⣿⣿⣿⣿⣿⡟⡀⠁⣶⠋⠀"
	@echo "⣿⣿⣟⢿⢿⣷⣕⣌⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠁⣽⢯⣾⣿⣿⣿⡟⡴⠰⠗⠸⠁⠀⠀"
	@echo "⣏⠿⣿⡧⡀⠢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⢀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣬⣿⣿⣿⣿⢸⡇⡻⡁⠀⠀⠀⠀"
	@echo "⣿⢧⠈⣿⠘⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⡠⠂⠀⠀⠀⠀⠀⠀⠁⠐⠀⠀⡀⠤⠀⠀⠀⠀⠀⠀⠉⠈⠀⠁⢀⠤⠀⠀⠘⠏⢸⢏⣽⣿⣞⢡⠃⡀⠀⠄⠀⠀"
	@echo "⣿⡆⠀⠈⠅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠄⡤⠆⠀⠀⠀⢠⠀⢀⠂⠀⠀⠀⠀⠀⠀⢀⠀⠀⢀⡀⠀⠀⠄⠀⠀⠀⠀⠀⢠⣄⠀⠰⢫⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣮⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠜⠀⠀⠀⠀⠂⠂⠀⠀⠀⠀⠀⠀⠂⠀⠐⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠋⠀⠀⠀⢰⢷⠿⡿⡄⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠉⠉⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⡇⠠⢠⠋⠀⠀⠀⠀⠆⠀⢠⣴⣾⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠏⠠⠈⡄⠀⠘⢈⢰⢃⡌⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣷⣢⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⡠⢠⢃⣀⡾⠀⠀⠀⠀⠃⢀⣴⣿⣿⡿⠛⠀⢀⣀⣠⢤⡄⢀⣀⣀⠀⠀⠄⠀⠀⢀⠀⠀⠚⠀⠀⠀⠻⡀⠸⠘⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⡥⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠁⠇⠀⡂⠁⠀⠀⠀⠀⠁⠀⣿⡿⠟⠉⢀⡴⢚⣋⡩⠅⡀⡀⡀⠉⠉⠙⠀⠀⡀⠑⠄⠀⠀⠀⠀⢠⡄⣠⡇⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠀⠀"
	@echo "⠤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠈⠢⠀⠂⠁⠀⠀⠀⠠⢄⠀⠀⠋⠀⠀⣠⣤⣶⣿⣮⣭⣗⣺⠶⠶⠦⣤⣄⡂⠀⠈⠤⠀⠂⠀⠀⡫⡀⠈⠁⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣤⣍⠑⠀⠀⠀⠀⠀⠀⠀⠤⣤⠐⠀⠀⠁⠀⠀⠀⡀⠔⡈⠐⢐⠂⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⡟⠻⢫⠔⣤⡉⠻⣄⢄⠀⠀⠀⠁⠐⠀⠀⠀⡈⠀⠀⢀⠠⡀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣟⣃⣀⠀⠀⠀⠀⠀⠀⢰⠔⠊⠋⠀⠀⠀⢀⢠⡠⢄⣨⣵⡴⠪⠴⡾⠿⠛⢿⣿⣟⡛⡛⠛⡭⠛⢛⡷⢦⡁⠈⠙⡢⡈⠑⢄⠠⠀⡀⠐⡀⠀⠀⠀⠀⠀⠸⣧⡱⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣷⣶⣁⣤⡠⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣴⣤⣈⣙⣛⣁⣀⡁⠁⣤⣶⣾⣿⣿⣿⡿⠆⠂⠀⠀⠀⠈⠑⠪⠳⣄⠈⠂⣀⠈⠳⣔⠔⠀⠐⠀⠀⠀⠀⠁⠀⠹⣷⣷⠆⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⣿⣯⡤⠤⠀⠀⠀⠀⢀⣀⠤⣄⣤⡸⣿⡿⡏⢉⠉⠉⠉⢀⣸⣿⣿⠿⠟⠛⢁⣄⡀⠠⡠⡀⠀⠀⠀⢠⠐⠢⡑⡄⡈⠡⡀⠈⢎⠁⠀⢣⠐⡈⠀⠀⠀⠀⠘⡏⠀⠀⠀⠀⠀⠠⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣶⡀⠀⠀⣤⣶⣿⠟⠁⠀⠰⡑⠌⠁⠀⠒⠾⢿⡿⠛⣁⠌⣠⣤⣜⢿⣿⡆⠊⢪⣦⠑⠄⠀⠁⠈⠈⠪⣠⠂⡈⢀⠈⢢⢦⡡⢣⠡⠀⠀⣿⡄⢀⠡⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣋⣀⠀⢐⡻⡇⠰⠐⣠⣧⠡⠀⠄⢀⢀⠔⠁⠀⣠⣵⣦⡻⣿⣿⡦⠙⠮⢂⡁⠈⠀⠀⠀⠀⠀⠀⠢⠈⠩⠢⣀⠡⡀⢣⠀⠀⢂⠄⠀⠘⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣶⣿⣷⣌⠉⠰⣰⣱⣿⡏⠀⣾⣾⠟⠁⠀⣠⣄⢿⣿⣿⣷⠈⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⢮⣦⡑⠠⢣⠀⢀⠈⠀⠀⠠⠇⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠅⣿⣿⡇⠰⣿⠁⠀⢄⡸⣿⣿⣦⠙⠃⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡄⠀⠑⢄⢻⣯⡀⠈⢆⡀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠿⣿⠇⠁⠃⠀⠀⢸⣷⡝⠟⠦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⣀⣄⠁⠈⣥⡀⠐⠠⠙⣿⡀⠀⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠛⢈⠄⡀⠀⠀⢡⡻⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠠⡀⢔⣶⣿⣶⠊⢻⠁⠀⣤⣙⢢⠀⠀⠘⢯⡄⠈⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠢⠈⠀⠀⠀⠡⠂⠀⣀⡀⡀⠀⠀⠀⠢⡀⡀⠀⢄⢀⣼⣿⣿⣏⠀⢀⠀⢸⣭⡙⠷⡁⠀⠀⠀⢻⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠈⠢⠀⠀⠀⠁⠈⠁⠀⠀⠀⠈⠀⠨⣮⣶⣤⣿⣿⣿⣿⡷⠀⠀⢲⣭⣛⢿⡀⠗⠀⠀⠀⠐⡁⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⢠⢠⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣀⠈⠐⠠⠀⠀⠀⠀⠀⠀⠀⠀⢢⣿⣿⣿⣿⣿⣿⠙⠁⠀⠀⣯⠻⣿⣷⡡⡀⠀⠀⢀⢁⠀⠀⠀⢈⠀⠀⠀⠀⠀⠀⠀⠀⡆⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠓⢄⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⡿⠛⢋⠂⢀⣄⠺⣿⣷⡘⣟⠃⠀⡀⠀⠠⠀⢀⠀⠀⠸⡀⠀⠀⠀⠀⠀⠀⠀⡇⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⣿⣦⡀⠡⠀⢀⠀⠀⠐⢄⢄⡉⠁⠅⢀⣠⡐⢿⣿⣦⠈⢿⠇⢀⣀⢢⠁⠀⠄⠀⠀⠀⠀⠘⡇⡀⠀⠀⠀⠀⠀⢰⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⢁⠙⣻⡿⠛⢛⣶⣄⠀⠀⡔⢄⠀⠳⣄⢆⡳⣤⡙⢿⣦⢙⠛⠈⢀⣴⣿⠿⠃⠀⠀⠀⠀⠂⠀⠀⢠⡇⠅⠀⠀⠀⠀⠀⡄⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣵⣿⣿⣿⣿⣿⣿⠃⠀⡌⡸⠟⠑⠀⢈⠁⠀⡰⢁⠈⢄⠃⢢⡈⠳⠝⢶⡩⠔⠉⢉⣤⣿⠿⠛⠁⠀⠀⣀⣴⡆⠨⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠃⠂⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⢰⠏⣽⣿⣿⣿⡿⡡⠀⠀⠀⠆⠃⠀⠀⢂⠀⠀⠃⠀⠀⠠⡙⢄⠝⢆⠀⠀⠁⢀⣴⡿⠟⠁⠀⠀⣀⣤⣼⣿⡿⠿⠀⠀⠀⠀⢀⢡⡌⠀⠀⠀⠀⠄⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⡸⠏⣿⠋⢁⠄⠃⠀⠈⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠁⠀⠀⠉⠁⠀⠀⠀⣀⣼⣿⠿⠻⠉⠃⠀⠀⠀⠀⠀⠈⣡⠀⠀⠀⠀⡸⠁⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠂⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣿⢻⠋⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡏⠀⠀⠀⠀⠁⠀⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⡟⡾⠟⡀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⡀⠈⠢⣀⠀⠈⠀⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠈⠻⢯⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⡠⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⡵⡀⠞⡁⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠄⡀⠠⢀⠁⠠⢀⠀⠁⠂⠄⢂⠤⢀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠂⢄⡀⠀⠀⠀⠀⠀⠀⢠⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀"

# Create object directories
$(OBJS_DIR) $(OBJ_SUBDIRS):
	@mkdir -p $@

-include $(DEPS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_SUBDIRS)
	@printf "$(LBLUE)[Compilation]$(RESET) In progress... $(GREEN)$<" && \
	$(CC) $(CFLAG) -I$(HEADERS) -c $< -o $@ && \
	printf "\r$(LBLUE)[Compilation]$(RESET) Completed   ... $(GREEN)$<" && \
	printf " $(LBLUE)[$(RESET)$(CC)$(LBLUE)/]$(RESET)\n"

clean :
	@echo "\033[0;31m\nObjects files will be destroyed[...]\n"
	@make --silent clean -C ${LIBFTDIR}
	@rm -rf $(OBJS_DIR)
	@echo "\033[0;32m\nDONE!\n"

fclean : clean
	@echo "\033[0;31m\nExecutes files will be destroyed[...]\n"
	@rm -f $(LIBFTDIR)/libft.a
	@rm -f $(NAME) 
	@echo "\033[0;32m\nDONE!\n"

re : fclean all

.PHONY: all clean fclean re