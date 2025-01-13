CC := cc
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wpedantic -fPIE #-flto #-O3 -fPIE -flto # -g #-fsanitize=address,bounds,undefined

SRCDIR := src
SRCS := $(addprefix $(SRCDIR)/, ft_stdlib/ft_allocations.c ft_stdlib/ft_atoi.c ft_ext/ft_strtrim.c ft_ext/ft_strmapi.c ft_ext/ft_split.c ft_ext/ft_strjoin.c ft_ext/ft_putendl_fd.c ft_ext/ft_putchar_fd.c ft_ext/ft_strjoin_all.c ft_ext/ft_putstr_fd.c ft_ext/ft_striteri.c ft_ext/ft_putnbr_fd.c ft_ext/ft_substr.c ft_ext/ft_itoa.c ft_unistd/ft_write.c ft_libgen.c ft_type/ft_toupper.c ft_type/ft_isdigit.c ft_type/ft_iscntrl.c ft_type/ft_isalpha.c ft_type/ft_isascii.c ft_type/ft_isblank.c ft_type/ft_tolower.c ft_type/ft_islower.c ft_type/ft_ispunct.c ft_type/ft_isxdigit.c ft_type/ft_isalnum.c ft_type/ft_isprint.c ft_type/ft_isgraph.c ft_type/ft_isupper.c ft_type/ft_isspace.c ft_string/ft_strcpy_strncpy.c ft_string/ft_strlen.c ft_string/ft_strcat_strncat.c ft_string/ft_strnstr.c ft_string/ft_strdup.c ft_string/ft_stpcpy_stpncpy.c ft_string/ft_strchr_strrchr.c ft_string/ft_strchrnul_strrchrnul.c ft_string/ft_strlcpy_strlcat.c ft_string/ft_strcmp_strncmp_strcasecmp_strncasecmp.c ft_string/ft_bstring/ft_memfrob.c ft_string/ft_bstring/ft_memcpy_memmove.c ft_string/ft_bstring/ft_bzero.c ft_string/ft_bstring/ft_memcmp.c ft_string/ft_bstring/ft_memset.c ft_string/ft_bstring/ft_memchr_memchrr.c ft_string/ft_bstring/ft_memccpy_memccpyr.c ft_string/ft_bstring/ft_memmem.c ft_rb_tree/ft_rb_rotations.c ft_rb_tree/ft_insert_rb_item.c ft_rb_tree/ft_rb_node_access.c ft_rb_tree/ft_balance_rb_tree_insert.c ft_rb_tree/ft_create_rb_node.c ft_rb_tree/ft_rb_find_node.c ft_rb_tree/ft_balance_rb_tree_delete.c ft_vector/ft_vector.c ft_vector/ft_vector_elem.c ft_lst/ft_lstlast.c ft_lst/ft_lstclear.c ft_lst/ft_lstadd_back.c ft_lst/ft_lstdelone.c ft_lst/ft_lstadd_front.c ft_lst/ft_lstmap.c ft_lst/ft_lstiter.c ft_lst/ft_lstnew.c ft_lst/ft_lstsize.c ft_get_next_line.c ft_read_file.c)

OBJDIR := obj
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

DIRS := $(sort $(dir $(OBJS)))

INCLUDEDIR := include
INCLUDES := $(addprefix $(INCLUDEDIR)/, ft_string.h ft.h ft_lst.h ft_printf.h ft_ext.h ft_stdlib.h ft_type.h ft_unistd.h ft_rb_tree.h ft_libgen.h ft_data_structs.h ft_vector.h ft_get_next_line.h ft_read_file.h)

NAME := libft.a

INCLUDE_FLAGS := -I$(INCLUDEDIR)

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $@ $?

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER) | $(DIRS)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(DIRS):
	mkdir -p $@

.PHONY: all clean fclean re bonus
