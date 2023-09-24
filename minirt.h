/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:13:01 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/23 22:16:53 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINIRT_H
#define MINIRT_H

#include "/Users/aaghbal/Desktop/miniRT/MLX42/include/MLX42/MLX42.h"
#include "/Users/aaghbal/Desktop/miniRT/MLX42/include/MLX42/MLX42_Int.h"
#include "/Users/aaghbal/Desktop/miniRT/MLX42/include/MLX42/MLX42_Keys.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


#define EPSILON 0.00001

#define WIDTH 1000
#define HEIGHT 1000

typedef struct s_vector
{
	double x;
	double y;
	double z;
	double w;
}t_vector;

typedef struct s_point
{
	double x;
	double y;
	double z;
	double w;
}t_point;

typedef struct s_color
{
	double red;
	double green;
	double blue;

}t_color;

typedef struct s_canvas
{
	int width;
	int height;
	char **data;
}t_canvas;

typedef struct  s_shearing
{
	double xy;
	double xz;
	double yx;
	double yz;
	double zx;
	double zy;
	
}t_shearing;

typedef struct s_ray
{
	t_point origine;
	t_vector direction;
}t_ray;

typedef struct s_material
{
	t_color color;
	double ambient;
	double diffuse;
	double specular;
	double shininess;
}t_material;

typedef struct s_sphere
{
	double **trans;
	t_material m;
}t_sphere;

typedef struct s_intersec
{
	double min;
	t_sphere s;
	struct s_intersec *next;
}t_intersect;

typedef struct s_data
{
	double a;
	double b;
	double c;
	double discr;
}t_data;

typedef struct t_intersection
{
	double t;
	t_sphere sp;
}t_intersection;


typedef struct s_light
{
	t_point position;
	t_color intensity;
}t_light;

typedef struct s_word
{
	t_sphere *s;
	t_light l;
}t_word;

typedef struct s_comps
{
	double t;
	t_sphere obj;
	t_point point;
	t_vector eyev;
	t_vector normalv;
	bool inside;
	t_point over_point;
}t_comps;

typedef struct s_camera
{
	double hsize;
	double vsize;
	double field_of_view;
	double half_width;
	double half_height;
	double pixel_size;
	double **trans;
}t_camera;

// vector_point

t_vector create_vector(double x, double y, double z);
t_point create_point(double x, double y, double z);
bool equal(double a, double b);
t_vector add_to_vector(t_vector v1, t_vector v2);
t_point add_point_vector(t_point p, t_vector v);
t_vector sub_to_point(t_point p1, t_point p2);
t_point sub_point_vect(t_point p, t_vector v);
t_vector sub_to_vector(t_vector v1, t_vector v2);
t_vector negating_vect(t_vector v);
t_point negating_point(t_point p);
t_vector scaler_vect(t_vector v, double s);
t_point scaler_point(t_point p, double s);
t_vector div_scaler_vect(t_vector v, double s);
t_point div_scaler_point(t_point p, double s);
double magnitude(t_vector v);
t_vector normalize(t_vector v);
double dot_product(t_vector v1, t_vector v2);
t_vector cross_product(t_vector a, t_vector b);

// color

t_color create_color(double r, double g, double b);
t_color adding_color(t_color c1, t_color c2);
t_color sub_color(t_color c1, t_color c2);
t_color mul_by_scaler(t_color c1, double s);
t_color mul_color(t_color c1, t_color c2);
unsigned int conv_color(double r, double g, double b);
unsigned char float_to_char(float n);

// canvas

t_canvas create_canvas(int w, int e);

// matrix
bool comparaison_matrix(double **m1, double **m2);
double **multiple_matrice(double **m1, double **m2);
t_vector mul_mat_vector(double **m, t_vector v);
t_point mul_mat_point(double **m, t_point p);
double **identity(void);
double **transposing(double **m);
double **inverse_matrix(double **m);
double determinant_4(double **M, int row, int col);

// tranformation

double **translation(double x, double y, double z);
double **scaling(double x, double y, double z);
double **rotation_x(double rad);
double **rotation_y(double rad);
double **rotation_z(double rad);
double **shearing(t_shearing data);

/// utils 
bool equal(double a, double b);
double mx(int x);
double my(int x);
int px(double x);
int py(double x);

/// ray

t_ray ray(t_point origine, t_vector direc);
t_point position(t_ray ray, double t);

// sphere

t_sphere sphere();
t_intersect *new_intersec(double min, t_sphere sp);
t_intersect *intersect_world(t_word w, t_ray r, int n_object);
void	add_back(t_intersect **lst, t_intersect *new);
void	add_front(t_intersect **lst, t_intersect *new);
t_intersect *intersect(t_sphere sp, t_ray r);
t_intersection intersection(double t, t_sphere s);

// transform 

t_ray transform(t_ray r, double **m);
void	set_transform(t_sphere *s, double **t);

// normal
t_vector normal_at(t_sphere *sp, t_point word_point);
t_vector reflect(t_vector in, t_vector normal);

//light

t_light point_light(t_point pos, t_color intensit);
t_material material(void);
t_color lighting(t_material m, t_light light, t_point point, t_vector eyev, t_vector normalv, bool shadowed);

// word 
t_word default_word();
t_word word(t_sphere *s, t_light l);
t_comps prepare_computations(t_intersection i, t_ray ray);
t_color shade_hit(t_word w, t_comps com, int n_obj);
t_intersect hit(t_intersect *res);
t_color color_at(t_word w, t_ray r, int n_object);
double **view_transformation(t_point from, t_point to, t_vector up);
t_ray ray_for_pixel(t_camera camera, double px, double py);
t_camera camera(double hsize, double vsize, double field_view);
void render(t_camera c, t_word w);

/////////////
bool is_shadowed(t_word w, t_point point, int n_obj);

#endif