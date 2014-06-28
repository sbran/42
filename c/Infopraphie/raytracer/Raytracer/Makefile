CC		= gcc -g

RM		= rm -f

CFLAGS		= -Wextra -Wall
CFLAGS		+= -IIncludes

NAME		= raytracer

MAIN		= Sources/Main/

INIT		= Sources/Init/

INTER		= Sources/Inter_obj/

CONF		= Sources/File_conf/

ROTATE		= Sources/Rotate/

LIGHT		= Sources/Lights/

PERLIN		= Sources/Bruitdeperlin/

EFFECTS		= Sources/Effects/

SRC		= $(MAIN)main.c \
		$(EFFECTS)texture.c \
		$(EFFECTS)chess.c \
		$(EFFECTS)ring.c \
		$(EFFECTS)perturb.c \
		$(MAIN)rempli_img.c \
		$(MAIN)count_obj.c \
		$(MAIN)calc.c \
		$(MAIN)check_k.c \
		$(MAIN)hooks.c \
		$(MAIN)mlx_ppti.c \
		$(MAIN)aff_percent.c \
		$(MAIN)free_list.c \
		$(INIT)init_basics.c \
		$(INIT)init_struct.c \
		$(INTER)inter_cylindre.c \
		$(INTER)inter_sphere.c \
		$(INTER)inter_cone.c \
		$(INTER)inter_plan.c \
		$(INTER)inter_paraboloide.c \
		$(INTER)inter_hyperboloide.c \
		$(INTER)utils_to_inter.c \
		$(CONF)get_scene.c \
		$(CONF)get_next_line.c \
		$(CONF)get_all_obj.c \
		$(CONF)get_obj.c \
		$(CONF)get_general.c \
		$(CONF)get_spot.c \
		$(CONF)get_elem.c \
		$(CONF)get_eye.c \
		$(CONF)extract_elem.c \
		$(CONF)extract_elem_spot.c \
		$(CONF)check_limit_while.c \
		$(CONF)put_obj_in_list.c \
		$(CONF)my_strncmp.c \
		$(CONF)init_token.c \
		$(CONF)check_errors.c \
		$(ROTATE)rotate.c \
		$(ROTATE)each_rotate.c \
		$(ROTATE)mat_rot.c \
		$(ROTATE)trans.c \
		$(LIGHT)init_struct_norm.c \
		$(LIGHT)luminosite.c \
		$(LIGHT)shadow.c \
		$(PERLIN)rand_bruit.c \
		$(PERLIN)interpolation2d.c

OBJ		= $(SRC:.c=.o)

LIB		= -L/usr/X11/lib -lmlx $(HOSTTYPE) -lXext -lX11

all: lib $(NAME)

lib:
	make -C Library

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIB) -L Library/ -lmy -lm

clean:
	make -C Library clean
	$(RM) $(OBJ)

fclean:	clean
	make -C Library fclean
	$(RM) $(NAME)

re:	fclean all
	make -C Library re

.PHONY:		re fclean all
