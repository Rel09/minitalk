#make && make client
CC = gcc
RM = rm -rf
FLAG = -Wall -Wextra -Werror
############################################################################
################################### Main ###################################
NAME = server
FILES :=	main tools functions sendping

SRCS_DIR = ./server_files/
OBJS_DIR = ./s_obj/

############################################################################
################################## Bonus ###################################
BONUS_NAME = client
BONUS_FILE :=	main tools sendping

BONUS_DIR = ./client_files/
BONUS_OBJS_DIR = ./c_obj/

############################################################################
############################################################################
############################################################################
############################# Colors & Prompt ###############################
RED="\033[1;31m";
CYAN="\033[1;36m"
GREEN="\033[1;32m"
ENDCOLOR="\033[0m"
CLEANING := $(GREEN)[+] Cleaning Completed$(ENDCOLOR)
SUCCESS := $(GREEN)[+] $(NAME) Successfully Compiled!$(ENDCOLOR)
BONUS_SUCCESS := $(GREEN)[+] $(BONUS_NAME) Successfully Compiled!$(ENDCOLOR)
############################ Compilation Main ###############################
#SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAG) $(OBJS) -o $(NAME)
	@echo $(SUCCESS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAG) -c $< -o $@
	@echo $(CYAN)[-] Compiling: $@$(ENDCOLOR)
########################### Compilation Bonus ###############################
BONUS_OBJS = $(addprefix $(BONUS_OBJS_DIR), $(addsuffix .o, $(BONUS_FILE)))
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(FLAG) $(BONUS_OBJS) -o $(BONUS_NAME)
	@echo $(BONUS_SUCCESS)

$(BONUS_OBJS_DIR)%.o: $(BONUS_DIR)%.c
	@mkdir -p $(BONUS_OBJS_DIR)
	@$(CC) $(FLAG) -c $< -o $@
	@echo $(CYAN)[-] Compiling Bonus: $@$(ENDCOLOR)

################################# Cleaning ##################################
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo $(CLEANING)

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME) $(OBJS_DIR) $(BONUS_OBJS_DIR)

re: fclean all

################################## Phony ####################################
.PHONY: all clean fclean re client
