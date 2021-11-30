#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "constants.h"
# include "get_next_line.h"
# include "key_codes.h"
# include "constants.h"
# include "flags.h"
# include "structs.h"

void			mini_map_and_back_init(t_all *all);
void			window_and_map_init(t_all *all);
void			set_sprt_indexes(t_all *all);
void			rotate_textures(t_all *all);
void			convert_n_texture(t_all *all);
void			convert_s_texture(t_all *all);
void			convert_w_texture(t_all *all);
void			convert_e_texture(t_all *all);
void			calculate_sprite_ratio(t_all *all);
void			convert_sprt_to_img(t_all *all);
void			mem_alloc_for_sprite_attr(t_all *all);
void			calc_scale_n_txtr(t_all *all);
void			calc_scale_s_txtr(t_all *all);
void			calc_scale_w_txtr(t_all *all);
void			calc_scale_e_txtr(t_all *all);
void			draw_all_sprites(t_all *all);
void			calculate_sprite_angle_and_distance(t_all *all);
void			textures_init(t_all *all);
void			draw_map(t_all *all);
void			insertion_sort(int *array, int length, t_all *all);
void			sprts_init(t_all *all);
void			set_sprite_texture(char **line, t_all *all, int *sttngs);
void			set_north_texture(char **line, t_all *all, int *sttngs);
void			set_west_texture(char **line, t_all *all, int *sttngs);
void			set_east_texture(char **line, t_all *all, int *sttngs);
void			set_south_texture(char **line, t_all *all, int *sttngs);
void			set_resolution(char **line, t_all *all, int *sttngs);
void			ceiling_color(char **line, t_all *all, int *sttngs);
void			floor_color(char **line, t_all *all, int *sttngs);
int				trgb(int t, int r, int g, int b);
void			resolution_and_textures_path(int *fd, t_all *all);
void			save_to_bmp(t_all *all);
void			put_sprite(t_all *all, int sprt_id);
void			rotate_img(t_all *all, void **img_ptr,
					void **data_addr, int **img_attr);
void			map_check(t_all *all);
int				close_win(t_all *all);
void			put_slice(int slice_number, int slice_half_height, t_all *all);
void			player_line_pixel_put(t_all *all, t_pnt_int point, int color);
void			player_line(t_pnt_int p1, t_pnt_int p2, t_all *all, int color);
void			copy_map(void *dst, void *src, t_all *all);
void			copy_mini_map(void *dst, void *src, t_all *all);
void			set_background(void	*addr, t_all *all);
int				add_shade2(double distance, unsigned int color);
void			set_black(void	*addr, int size);
int				my_free(int i, char **ptr1, char **ptr2);
void			my_mlx_pixel_put2(t_all *all, t_pnt point, int color);
unsigned int	*calculate_address2(t_all *all, int x, int y);
void			my_mlx_pixel_put3(t_all *all, t_pnt point, int color);
unsigned int	*calculate_address3(t_all *all, int x, int y);
unsigned int	*calculate_map_address(t_all *all, int x, int y);
t_pnt			horizontal_intersection(t_all *all);
t_pnt			vertical_intersection(t_all *all);
void			cast_all_rays(t_all *all);
void			normalized(double *vector_x, double *vector_y);
int				draw(t_all *all);
void			player_update(t_plr *plr, int key_flags);
void			collision(t_all *all, t_pnt *old_position);
int				release_key(int keycode, t_all *all);
int				check_key(int keycode, t_all *all);
void			player_init(t_plr *plr, int cell_size);
void			init(t_all *all);
void			put_cell(t_all *all, t_pnt point, int color);
void			my_mlx_pixel_put(t_all *all, t_pnt point, int color);
unsigned int	*calculate_address(t_all *all, int x, int y);
void			copy_img(void *dst, void *src, int size);
void			cub_parser(char *str, t_all *all);
t_node			*init_list(char *line);
void			append_to_list(t_node *head_node, char *line);
t_node			*remove_head_node(t_node *head_node);
void			clear_list(t_node *head);
void			clear_map(t_all *all, int i);
void			circumference(t_all *all, t_pnt center, int radius, int color);
int				ft_atoi(const char *str);
char			*strjoin(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_itoa(int n);

#endif