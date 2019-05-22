############################## COMPILE VAR #####################################

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		=	-g
HDIR		=	includes
SRCDIR		=	src
SUB1D		=	libft
HFLAGS		=	-I $(HDIR) -I $(SRCDIR)/$(SUB1D)/$(HDIR)
LIBS		=	$(SRCDIR)/$(SUB1D)/libft.a
NAME		=	ft_select

############################## SOURCES #########################################

INITDIR			=	init
INPUTDIR		=	input
PRINTDIR		=	print

SRCC			=	main.c\

INITC			=	fts_init.c\
					fts_load_argv.c\
					load_colors.c\
					ring.c\
					terminal_mode.c\

INPUTC			=	char_functions_1.c\
					char_functions_2.c\
					fts_getchar.c\
					g_charfunc.c\

PRINTC			=	cursor.c\
					fts_print.c\
					print_list.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(INITC))\
					$(patsubst %.c,%.o,$(INPUTC))\
					$(patsubst %.c,%.o,$(PRINTC))\
					$(patsubst %.c,%.o,$(SRCC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.h	$(SRCDIR)/$(SUB1D)/$(HDIR)
vpath			%.c	$(SRCDIR)/$(INITDIR)
vpath			%.c	$(SRCDIR)/$(INPUTDIR)
vpath			%.c	$(SRCDIR)/$(PRINTDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): $(SRCDIR)/$(SUB1D)/libft.a $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ)) $(LIBS) -ltermcap

$(SRCDIR)/$(SUB1D)/libft.a:
	make -C $(SRCDIR)/$(SUB1D)

fts_init.o: libft.h t_ftsdata.h terminal_mode.h load_colors.h
fts_load_argv.o: ring.h t_ftsdata.h libft.h
load_colors.o: libft.h t_ftsdata.h c_colors.h
ring.o: t_ftsdata.h libft.h
terminal_mode.o: libft.h fts_init.h t_ftsdata.h
char_functions_1.o: charfunc.h t_ftsdata.h ring.h fts_print.h cursor.h
char_functions_2.o: charfunc.h t_ftsdata.h ring.h fts_print.h cursor.h
fts_getchar.o: libft.h charfunc.h t_ftsdata.h
g_charfunc.o: charfunc.h t_ftsdata.h
main.o: libft.h fts_init.h t_ftsdata.h fts_load_argv.h fts_print.h charfunc.h
cursor.o: t_ftsdata.h
fts_print.o: terminal_mode.h libft.h print_list.h t_ftsdata.h
print_list.o: libft.h t_ftsdata.h terminal_mode.h c_colors.h
%.o: %.c
	@mkdir -p $(ODIR)
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
