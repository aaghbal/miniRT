/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:13:01 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/20 19:37:01 by aaghbal          ###   ########.fr       */
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


#define epsilon 0.00001

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

double mx(int x);
double my(int x);
int px(double x);
int py(double x);
#endif