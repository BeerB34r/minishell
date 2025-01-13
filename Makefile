# **************************************************************************** #
#                                                                              #
#                                                        ::::::::              #
#    Makefile                                          :+:    :+:              #
#                                                     +:+                      #
#    By: mde-beer <mde-beer@student.codam.nl>        +#+                       #
#                                                   +#+                        #
#    Created: 2025/01/13 14:04:20 by mde-beer     #+#    #+#                   #
#    Updated: 2025/01/13 14:13:26 by mde-beer     ########   odam.nl           #
#                                                                              #
# **************************************************************************** #

.PHONY			:	all re clean fclean run libclean

MAIN			=	$(addprefix $(SRCDIR)/,main.c)
SRCFILES		=	environment.c environment_touchers.c environment_utils.c \
					error.c
SRCSUBDIR		=	env
SRCDIR			=	src
SRCDIRS			=	$(SRCDIR) $(addprefix $(SRCDIR)/, $(SRCSUBDIR))

OBJFILES		=	$(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))
OBJDIR			=	bin

# for some reason the linker sucks absolute dick and balls, so the order matters
LIBNAMES		=	libftprintf/libftprintf.a libft/libft.a
LIBDIR			=	lib
LIBINC			=	$(dir $(LIBS))
LIBS			=	$(addprefix $(LIBDIR)/, $(LIBNAMES))
# runs a command inside all library submakes
define libscmd
for dir in $(dir $(LIBS)); do \
	echo $$dir; \
	$(MAKE) -C $$dir $(1); done ;
endef
# runs a command inside specified library submake
define libcmd
echo $(1)
$(MAKE) -C $(1) $(2)
endef

HEADERS			=	ft_env.h
INCSUBDIR		=	env
INCDIR			=	inc
INCDIRS			=	$(INCDIR) $(addprefix $(INCDIR)/, $(INCSUBDIR))
INCLUDE			=	$(addprefix -I, $(INCDIRS) $(LIBINC))

VPATH			=	$(SRCDIRS) $(INCDIRS)
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

MAKEFLAGS		+=	-j$(shell nproc) --output-sync=target --no-print-directory
.DEFAULT_GOAL	=	all

NAME			=	minishell

all				:	$(NAME)
$(OBJDIR)		: ;	mkdir $(OBJDIR)
re				:	fclean all
run				:	$(NAME) ;	./$(NAME) $(PARAMS)

$(NAME)			:	$(OBJFILES) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(MAIN) $^ 

$(OBJDIR)/%.o	:	%.c $(HEADERS)	| $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

%.a				:
	+@$(call libcmd, $(dir $@), all)

clean			:
	rm -rf $(OBJDIR)
	+@$(call libscmd, clean)

fclean			:	clean
	rm -f $(NAME)
	+@$(call libscmd, fclean)
# canceling the implicit rules
%.o				:	%.c
