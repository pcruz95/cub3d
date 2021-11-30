NAME = cub3D

SRCDIR = ./src/
SRCLIST =  	main.c map_check.c calculate_scale_txtr.c \
		calculate_sprite_angle_and_distance.c mem_alloc_for_sprite_attr.c \
		cast_all_rays.c my_free.c check_key.c my_mlx_pixel_put2.c \
		circumference.c my_mlx_pixel_put.c close_win.c player_init.c \
		convert_txtr_to_xpm.c player_update.c copy_img.c put_cell.c \
		cub_parser.c put_slice.c draw_all_sprites.c put_sprite.c \
		draw.c release_key.c draw_map.c resolution_and_textures_path.c \
		floor_and_ceiling_color.c rotate_img.c ft_atoi.c save_to_bmp.c \
		ft_itoa.c set_black.c ft_memset.c set_resolution.c ft_strncmp.c \
		set_texture_path.c get_next_line.c singly_linked_list.c \
		get_next_line_utils.c sprts_init.c horizontal_intersection.c strjoin.c \
		images_init.c textures_init.c init.c trgb.c insertion_sort.c \
		vertical_intersection.c line.c

HEADER = main.h

SRC = $(addprefix $(SRCDIR), $(SRCLIST))

OSRC = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(OSRC)

$(NAME): $(SRC)
	@gcc $(FLAGS) -lmlx -framework OpenGl -framework AppKit $(SRC) -o $(NAME)

clean:
	@rm -rf $(OSRC)

fclean: clean
	@rm -rf ./src/libmlx.a
	@rm -rf $(NAME)

re: fclean all