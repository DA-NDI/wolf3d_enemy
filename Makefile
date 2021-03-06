#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolgin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 18:42:23 by avolgin           #+#    #+#              #
#    Updated: 2018/07/20 09:03:57 by avolgin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

SRC_WOLF =./init.c \
	./main.c \
	validate.c \
	player_coordinates.c \
	raycasting.c \
	weapon.c \
	skybox.c \
	mainloop.c \
	loaders.c \
	drawers.c \
	start_screen.c \
	extra_keys.c \
	sprite.c \
	weapon_extra.c \
	drawers_extra.c

OBJECT_WOLF = $(SRC_WOLF:.c=.o)

FLAGS = -Wall -Wextra

INCLUDES_WOLF = -I ./includes/

INCLUDES_LIBFT = -I ./src/libft/includes

INCLUDES_SDL2 = -I ./src/SDL/SDL2.framework/Headers

INCLUDES_SDL2_IMAGE = -I ./src/SDL/SDL2_image.framework/Headers

INCLUDES_SDL2_MIXER = -I ./src/SDL/SDL2_mixer.framework/Headers

LIBFT = ./src/libft/libft.a

INCLUDES_SDL2_TTF = -I ./src/SDL/SDL2_ttf.framework/Headers

FRAMEWORK_SDL2 = -F ./src/SDL -framework SDL2 \
	-framework SDL2_image \
	-framework SDL2_ttf \
	-framework SDL2_mixer

FRAMEWORK_MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(OBJECT_WOLF)
	make -C ./src/libft
	@echo "\033[0;32mWolf compiled\033[0;0m"
	@gcc -o $(NAME) $(FLAGS) $(LIBFT) $(INCLUDES_SDL2) $(INCLUDES_SDL2_IMAGE) -rpath @loader_path/src/sdl $(FRAMEWORK_SDL2) $(OBJECT_WOLF) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

%.o: %.c includes/*.h
	gcc -g $(FLAGS) -o $@ -c $< $(INCLUDES_WOLF) $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

%.o: %.c
	gcc -g 	$(FLAGS) -o $@ -c $< $(INCLUDES_WOLF) $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

clean:
	make -C ./src/libft clean
	/bin/rm -f $(OBJECT_WOLF)
	rm -f TAGS

fclean: clean
	/bin/rm -f ./src/libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all tags

tags:
	etags -R *.c *.h
