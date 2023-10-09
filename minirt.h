/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:13:01 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/09 20:40:05 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <pthread.h>
# include "MLX42/MLX42.h"
# include "get_next_line.h"
# include "Libft/libft.h"

# define EPSILON 0.00001

# define ADD 0 
# define FREE 1 

# define A 0
# define C 1
# define L 2
# define SP 3
# define PL 4
# define CY 5
# define CO 6
# define ERR_ID 7
# define ERR_CAL 8
# define EXTE 9
# define OP 10
# define WIDTH 500
# define HEIGHT 500

typedef struct s_cal
{
	int	camera;
	int	ambiant;
	int	light;
}t_cal;

typedef struct s_uv
{
	double	u;
	double	v;
}	t_uv;

typedef enum s_obj
{
	sp,
	pl,
	cy,
	co,
	cu
}t_obj;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vector;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_point;

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;

}	t_color;

typedef struct s_canvas
{
	int		width;
	int		height;
	char	**data;
}	t_canvas;

typedef struct s_shearing
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}	t_shearing;

typedef struct s_ray
{
	t_point		origine;
	t_vector	direction;
}	t_ray;

typedef struct s_pattern
{
	t_color		a;
	t_color		b;
	double		**transform;
	double		**inverse;
}	t_pattern;

typedef struct s_material
{
	t_color		color;
	t_color		amb_color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}	t_material;

typedef struct s_data
{
	double	a;
	double	b;
	double	c;
	double	discr;
	double	t0;
	double	t1;
	double	y0;
	double	y1;
}	t_data;

typedef struct s_check
{
	t_color		a;
	t_color		b;
	double		width;
	double		height;
}	t_check;

typedef struct s_texture_map
{
	t_check		uv_pattern;
	t_uv		(*uv_map)(t_point);
}t_texture_map;

typedef struct s_shape
{
	double			**tranform;
	t_material		m;
	t_vector		normal_pl;
	double			**ivers_tran;
	t_obj			obj;
	bool			closed;
	double			raduis;
	double			min;
	double			max;
	t_shearing		shearing;
	bool			has_effects;
	t_check			pattern;
	t_texture_map	mapping;
}	t_shape;

typedef struct t_intersection
{
	double	t;
	t_shape	sp;
}	t_intersection;

typedef struct s_light
{
	t_point	position;
	t_color	intensity;
}	t_light;

typedef struct s_comps
{
	double		t;
	t_shape		obj;
	t_point		point;
	t_vector	eyev;
	t_vector	normalv;
	bool		inside;
	t_point		over_point;
}	t_comps;

typedef struct s_camera
{
	double	hsize;
	double	vsize;
	double	field_of_view;
	double	half_width;
	double	half_height;
	double	pixel_size;
	double	**trans;
	double	**inverse;
}	t_camera;

typedef struct s_word
{
	t_shape	*s;
	t_light	*l;
	t_color	ambiant;
}	t_word;

typedef struct s_intersec
{
	double				min;
	double				max_cube;
	t_shape				s;
	struct s_intersec	*next;
}	t_intersect;

typedef struct s_thread
{
	int	start_x;
	int	start_y;
}	t_thread;

typedef struct s_r_of_pixel
{
	double		xoffset;
	double		yoffset;
	double		word_x;
	double		word_y;
	double		**inv;
}t_pixel;

typedef struct s_variable_lighting
{
	t_point		point;
	t_vector	eyev;
	t_vector	normalv;
	t_light		l;
	t_color		effective_color;
	t_vector	lightv;
	t_color		ambient;
	t_color		defuse;
	t_color		specular;
	t_vector	reflectv;
	t_color		res;
	t_color		am_rati;
}	t_var_light;

typedef struct s_cube
{
	double	min;
	double	max;
}	t_cube;

typedef struct s_free
{
	void			*add;
	struct s_free	*last;
	struct s_free	*next;
}	t_free;

typedef struct s_data_parsing
{
	int		num_shap;
	int		num_ligh;
}	t_d_pars;

typedef struct s_data_am
{
	double	ratio;
	double	*res;
}	t_d_am;

typedef struct s_data_bonus
{
	t_color	c;
	double	nb;
	char	*path;
}t_d_bonus;

typedef struct s_norm_word
{
	char		*line;
	char		**spl;
	int			i;
	int			j;
	t_camera	c;
	t_word		w;

}	t_norm;

t_vector		create_vector(double x, double y, double z);
t_point			create_point(double x, double y, double z);
bool			equal(double a, double b);
t_vector		add_to_vector(t_vector v1, t_vector v2);
t_point			add_point_vector(t_point p, t_vector v);
t_vector		sub_to_point(t_point p1, t_point p2);
t_point			sub_point_vect(t_point p, t_vector v);
t_vector		sub_to_vector(t_vector v1, t_vector v2);
t_vector		negating_vect(t_vector v);
t_point			negating_point(t_point p);
t_vector		scaler_vect(t_vector v, double s);
t_point			scaler_point(t_point p, double s);
t_vector		div_scaler_vect(t_vector v, double s);
t_point			div_scaler_point(t_point p, double s);
double			magnitude(t_vector v);
t_vector		normalize(t_vector v);
double			dot_product(t_vector v1, t_vector v2);
t_vector		cross_product(t_vector a, t_vector b);

// color

t_color			create_color(double r, double g, double b);
t_color			adding_color(t_color c1, t_color c2);
t_color			sub_color(t_color c1, t_color c2);
t_color			mul_by_scaler(t_color c1, double s);
t_color			mul_color(t_color c1, t_color c2);
unsigned int	conv_color(double r, double g, double b);
unsigned char	float_to_char(float n);

// canvas

t_canvas		create_canvas(int w, int e);

// matrix
bool			comparaison_matrix(double **m1, double **m2);
double			**multiple_matrice(double **m1, double **m2);
t_vector		mul_mat_vector(double **m, t_vector v);
t_point			mul_mat_point(double **m, t_point p);
double			**identity(void);
double			**transposing(double **m);
double			**inverse_matrix(double **m);
double			determinant_4(double **M, int row, int col);

// tranformation

double			**translation(double x, double y, double z);
double			**scaling(double x, double y, double z);
double			**rotation_x(double rad);
double			**rotation_y(double rad);
double			**rotation_z(double rad);
double			**shearing(t_shearing data);

/// ray

t_ray			ray(t_point origine, t_vector direc);
t_point			position(t_ray ray, double t);

// sphere

t_shape			default_shape(void);
t_intersect		*new_intersec(double min, t_shape sp);
t_intersect		*intersect_world(t_word w, t_ray r, int n_object);
void			add_back(t_intersect **lst, t_intersect *new);
void			add_front(t_intersect **lst, t_intersect *new);
t_intersect		*sphere_intersect(t_shape s, t_ray ray);
t_intersection	intersection(double t, t_shape s);

// transform 

t_ray			transform(t_ray r, double **m);
void			set_transform(t_shape *s, double **t);

// normal
t_vector		sphere_normal_at(t_shape *sp, t_point word_point);
t_vector		reflect(t_vector in, t_vector normal);

//light

t_light			point_light(t_point pos, t_color intensit);
t_material		material(void);
t_color			lighting(t_shape s, t_light light, t_var_light v,
					bool shadowed);
// word 
t_word			default_word(void);
t_word			word(t_shape *s, t_light *l);
t_comps			prepare_computations(t_intersection i, t_ray ray);
t_color			shade_hit(t_word w, t_comps com, t_d_pars p);
t_intersect		hit(t_intersect *res);
t_color			color_at(t_word w, t_ray r, t_d_pars p);
double			**view_transformation(t_point from, t_point to, t_vector up);
t_ray			ray_for_pixel(t_camera camera, double px, double py);
t_camera		camera(double hsize, double vsize, double field_view);
void			render(t_word w, t_camera c, t_d_pars p);

/////////////
bool			is_shadowed(t_word w, t_point point, int n_obj, t_light l);
double			**inverse_gauss(double **n);
void			print_matrice(double **m);

//inverse matrix

double			**join_matr_ind(double **m);
int				swap_diagonal_element(double **mat, int i);
void			swap_row(double **mat, int swaprow, int i);
double			**copy_result(double **mat);

// plan

double			plan_intersect(t_shape s, t_ray ray);
t_vector		plan_normal_at(t_shape *sp, t_point word_point);

// cyl

t_intersect		*cyl_intersect(t_shape s, t_ray ray);
t_vector		cyl_normal_at(t_shape s, t_point point);
t_intersect		*intersect_caps(t_shape s, t_ray r, t_intersect **xs);
void			ft_swap(double *t0, double *t1);

// cone  
t_intersect		*cone_intersect(t_shape s, t_ray ray);
t_vector		cone_normal_at(t_shape s, t_point word_point);

// cube
t_intersect		*cube_intersect(t_shape s, t_ray ray);
t_vector		cube_normal_at(t_shape s, t_point word_point);

// free
t_free			*new_addr(void *address);
void			ft_free(int flag, void *addr);
void			add_addr(t_free **lst, t_free *new);
void			free_doublep(char **tab);

// parsing 
void			read_file(char *file);
int				check_exten(char *argv);
char			**ft_split(char const *s, char c);
t_shape			check_ident_shap(char **elem);
t_color			rgb_color(char *str, double ratio, int flag);
double			ft_itod(char *str);
t_color			parsing_am_light(char **elem);
t_shape			parsing_sphere(char **elem, int n);
t_shape			parsing_plan(char **elem, int n);
t_point			parse_origine(char *elem, int flag);
t_vector		parse_vector(char *elem, int flag);
t_light			parsing_light(char	**elem);
t_camera		parsing_camera(char **elem);
double			conver_ratio_number(char *rat, int flag);
double			conver_color_number(char *rat, int flag);
double			conver_normal_number(char *rat, int flag);
t_shape			parsing_cyl(char **elem, int n);
double			**orient(t_vector orie);
double			radiane(double deg);
t_shape			parsing_cone(char **elem, int n);
int				count_elem(char **elem);
int				check_exten(char *argv);
void			check_element(char *line);
int				count_shape(char *line);
t_d_pars		data_shape(int fd);

// pattern

void			pattern_set_transform(t_pattern *p, double **m);
t_check			uv_checkers(int w, int h, t_color a, t_color b);
t_pattern		stripe_pattern(t_color a, t_color b);

t_color			stripe_at(t_pattern p, t_point point);
t_color			stripe_at_shape(t_pattern p, t_shape s, t_point point);
t_color			uv_checkers_at(t_check ch, double u, double v);
t_color			checkers_at(t_texture_map tm, t_point p);
t_uv			sphere_uv_map(t_point p);
t_uv			plan_uv_map(t_point p);
t_uv			cyl_uv_map(t_point p);
t_texture_map	texture_map(t_check pattern, t_uv (*map)(t_point));
// syntax
void			syntax_color(char *elem, int flag);
void			syntax_ratio(char *elem, int flag);
void			print_error(int flag);
double			conver_origine_number(char *rat, int flag);
int				ft_strcmp(const char *s1, const char *s2);
#endif