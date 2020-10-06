NAME = cub3D

HEAD = cub3d.h

SRCS = main.c get_next_line.c get_next_line_utils.c \
		parser.c ft_move.c put_window.c \
		put_text.c ft_setfloorcollor.c setdata.c \
		parser_utils.c parser_check_map.c put_sprite.c \
		setdata_utils.c put_window_utils.c my_pixel_put.c \
		put_sprite_utils_1.c put_sprite_utils_2.c \
		parser_utils_1.c ft_putsprite.c inittexture.c \
		error1.c error2.c error3.c error4.c error5.c \
		ft_setfloorcollor_utils.c somefree.c mybmp.c \
		mybmp_utils.c put_screen.c mapcheck.c stepdda.c \
		parser_utils_0.c 

SRCO = main.o get_next_line.o get_next_line_utils.o \
		parser.o ft_move.o put_window.o \
		put_text.o ft_setfloorcollor.o setdata.o \
		parser_utils.o parser_check_map.o put_sprite.o \
		setdata_utils.o put_window_utils.o my_pixel_put.o \
		put_sprite_utils_1.o put_sprite_utils_2.o \
		parser_utils_1.o ft_putsprite.o inittexture.o \
		error1.o error2.o error3.o error4.o error5.o \
		ft_setfloorcollor_utils.o somefree.o mybmp.o \
		mybmp_utils.o put_screen.o mapcheck.o stepdda.o \
		parser_utils_0.o 


all: $(SRCO) $(HEAD)
	cd ./libft && make bonus && cd ..
	cd minilibx_mms && make && mv libmlx.dylib ../ && cd ..
	gcc $(SRCO) -o $(NAME) libmlx.dylib -g -framework OpenGL -framework Appkit libft/libft.a

$(SRCO): %.o:%.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	/bin/rm -f $(SRCO)
	cd ./libft && make fclean && cd ..
	/bin/rm -f libmlx.dylib

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f screenshot.bmp

re: fclean all

.PHONY: $(NAME) clean fclean re all