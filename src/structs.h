#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_rgb
{
	char	*tmp;
	int		red;
	int		green;
	int		blue;
}	t_rgb;

typedef struct s_node
{
	struct s_node	*next_node;
	char			*line;
}	t_node;

typedef struct s_pnt
{
	double		x;
	double		y;
}	t_pnt;

typedef struct s_pnt_int
{
	int			x;
	int			y;
}	t_pnt_int;

typedef struct s_cell
{
	int		start_x;
	int		start_y;
	int		stop_x;
	int		stop_y;
	int		start_collider_x;
	int		start_collider_y;
	int		stop_collider_x;
	int		stop_collider_y;
}	t_cell;

typedef struct s_crcmfrnc
{
	t_pnt	draw_point;
	int		x;
	int		y;
	int		delta;
	int		error;
}	t_crcmfrnc;

typedef struct s_line
{
	int		deltaX;
	int		deltaY;
	int		signX;
	int		signY;
	int		error;
	int		error2;
}	t_line;

typedef struct s_rotated
{
	void			*rot_img;
	void			*rot_data_addr;
	unsigned int	*_data_addr;
	unsigned int	*_rot_data_addr;
	unsigned int	*rot_pxl;
	int				r_img_x;
	int				r_img_y;
	int				i;
}	t_rotated;

typedef struct s_screenshot
{
	int			fd;
	int			corrected_width;
	char		*filename;
	void		*tmp;
}	t_sceenshot;

typedef struct s_slice
{
	double			yscale;
	double			xscale;
	int				y_texture;
	double			x_texture;
	unsigned int	*texture;
}	t_slice;

typedef struct s_map
{
	char		**map;
	int			map_height;
	int			map_width;
	int			mini_map_size;
	int			fd;
	double		cell_size;
	double		plr_square;
	t_node		*head;
	t_node		*node;
}	t_map;

typedef struct s_ray
{
	double	ray_angle;
	double	dist2screen;
	double	tan_ray_angle;
	int		isRayFacingDown;
	int		isRayFacingLeft;
	double	h_xstep;
	double	h_ystep;
	double	v_xstep;
	double	v_ystep;
	t_pnt	horz_intrcpt;
	t_pnt	vert_intrcpt;
	int		found_horz_wall;
	int		found_vert_wall;
	double	x_projection;
	double	y_projection;
	double	Vdistance;
	double	Hdistance;
	double	real_distance;
	int		wall_color;
	int		Projected_Slice_Height;
}	t_ray;

typedef struct s_plr
{
	t_pnt	old_position;
	t_pnt	pos;
	double	delta_x;
	double	delta_y;
	int		radius;
	int		turn_direction;
	int		walk_direction;
	int		strafe_direction;
	double	rotation_angle;
	double	move_speed;
	double	normal_speed;
	double	diagonal_speed;
}	t_plr;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	void	*win2;
	void	*img2;
	void	*addr2;
	void	*tmp_img;
	void	*tmp_addr;
	void	*mini_map_img;
	void	*mini_map_addr;
	void	*back_img;
	void	*back_addr;
	int		floor_color;
	int		ceiling_color;
	int		mini_map_line_length;
	int		bits_per_pixel;
	int		line_length;
	int		line_length_ints;
	int		endian;
	int		all_pxls;
	int		half_all_pxls;
	int		half_width;
	int		half_height;
	int		width;
	int		height;
	double	ratio;
}	t_win;

typedef struct s_txtr
{
	void	*n_textrure_img;
	void	*n_textrure_addr;
	int		*n_texture_attr;
	char	*n_texture_path;
	void	*s_textrure_img;
	void	*s_textrure_addr;
	int		*s_texture_attr;
	char	*s_texture_path;
	void	*w_textrure_img;
	void	*w_textrure_addr;
	int		*w_texture_attr;
	char	*w_texture_path;
	void	*e_textrure_img;
	void	*e_textrure_addr;
	int		*e_texture_attr;
	char	*e_texture_path;
}	t_txtr;

typedef struct s_sprt
{
	double	dist;
	void	*sprite_img;
	void	*sprite_addr;
	int		*sprite_attr;
	t_pnt	position;
	double	dir;
	double	diff_angle;
	double	h_offset;
	double	v_offset;
	long	sprite_h;
	long	sprite_w;
	int		i;
	int		j;
	double	step;
	int		color;
	double	sprt_ratio;
}	t_sprt;

typedef struct s_all
{
	t_plr		plr;
	t_win		win;
	t_map		map;
	t_txtr		txtr;
	t_sprt		*sprt;
	t_ray		rays;
	t_crcmfrnc	circumference;
	t_rotated	rot_img;
	t_sceenshot	screenshot;
	t_cell		cell;
	t_slice		slice;
	t_rgb		rgb;
	t_line		line;
	double		*ray_distances;
	int			*sprt_indexies;
	char		*sprite_texture_path;
	int			nbr_sprt;
	int			key_flags;
}	t_all;

#endif