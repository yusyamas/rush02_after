NAME := rush-02
LIBNAME := libft.a
LIBDIR := ./libft
SRCDIR := ./srcs
OBJDIR := ./srcs
INCDIR := -I ./includes
LIBS := $(wildcard $(LIBDIR)/*.c)
SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
LIBO := $(addprefix $(LIBDIR)/, $(notdir $(LIBS:.c=.o)))
CC := gcc
CFLAG := -Wall -Wextra -Werror
.PHONY: all clean fclean re delete

all: rush-02

rush-02 : $(OBJS) $(LIBNAME)
	$(CC) $(CFLAG) $(INCDIR) -o $@ $^

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAG) $(INCDIR) -c $< -o $@

$(LIBNAME) : $(LIBO)
	ar r $@ $^

$(LIBDIR)/%.o : $(LIBDIR)/%.c
	$(CC) $(CFLAG) $(INCDIR) -c $< -o $@

delete:
	$(RM) $(NAME)
	$(RM) $(LIBNAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBO)

fclean:	clean delete

re:	fclean all
