############################## COMPILE VAR #####################################

CC			=	gcc
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-g
HDIR		=	includes
SRCDIR		=	src
SUB1D		=	libft
HFLAGS		=	-I $(HDIR) -I $(SRCDIR)/$(SUB1D)/$(HDIR)
LIBS		=	$(SRCDIR)/$(SUB1D)/libft.a
NAME		=	ft_select

############################## SOURCES #########################################

SRCC			=	fts_init.c\
					fts_load_argv.c\
					fts_print.c\
					load_colors.c\
					main.c\
					print_list.c\
					ring.c\
					terminal_mode.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(SRCC))

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.h	$(SRCDIR)/$(SUB1D)/$(HDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): $(SRCDIR)/$(SUB1D)/libft.a $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ)) $(LIBS) -ltermcap

$(SRCDIR)/$(SUB1D)/libft.a:
	make -C $(SRCDIR)/$(SUB1D)

fts_init.o: libft.h t_ftsdata.h terminal_mode.h load_colors.h
fts_load_argv.o: ring.h t_ftsdata.h libft.h
fts_print.o: terminal_mode.h libft.h print_list.h t_ftsdata.h
load_colors.o: libft.h t_ftsdata.h c_colors.h
main.o: libft.h fts_init.h t_ftsdata.h fts_load_argv.h fts_print.h
print_list.o: libft.h t_ftsdata.h terminal_mode.h c_colors.h
ring.o: t_ftsdata.h libft.h
terminal_mode.o: libft.h fts_init.h t_ftsdata.h
%.o: %.c
	$(CC) -c $(CFLAGS) $< $(HFLAGS) -o $(ODIR)/$@

$(ODIR):
	mkdir -p $@

############################## CLEANUP #########################################

clean:
	rm -rf $(ODIR)
	make -C $(SRCDIR)/$(SUB1D) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
