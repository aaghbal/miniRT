/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:08:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/09 11:50:03 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_matrice(double **m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%.5f  ", m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_shape	*create_shape(void)
{
	t_shape	*s;

	s = malloc(sizeof(t_shape) * 2);
	s[0] = default_shape();
	s[0].m.color = create_color(0, 1, 1);
	s[0].m.specular = 0.0;
	s[0].obj = pl;
	 /////////////////////////////////////////
	s[1] = default_shape();
	s[1].min = 0;
	s[1].max = 1;
	s[1].m.color = create_color(1, 1, 0);
	s[1].obj = co;

	// /////////////////////////////////////////
	// s[2] = default_shape();
	// s[2].tranform = multiple_matrice(translation(1.5, 0.5, -2) ,scaling(0.5, 0.5, 0.5));
	// s[2].tranform = multiple_matrice(s[2].tranform, rotation_x(M_PI/2));
	// s[2].tranform = multiple_matrice(s[2].tranform, rotation_y(0.87266));
	// s[2].closed = true;
	// s[2].min = -2;
	// s[2].max = 2;
	// s[2].m.color = create_color(0.5, 1, 0.1);
	// s[2].obj = cy;
	// /////////////////////////
	// s[3] = default_shape();
	// s[3].closed = true;
	// s[3].tranform = multiple_matrice(translation(-1.5, 0.33, -0.75) ,scaling(0.33, 0.33, 0.33));
	// s[3].m.color = create_color(1, 0.8, 0.1);
	// s[3].min = -2;
	// s[3].max = 1;
	// s[3].obj = cy;

	// /////////////////////////
	// s[4] = default_shape();
	// s[4].tranform = multiple_matrice(translation(0, 4, 0) ,scaling(1, 1, 1));
	// s[4].m.color = create_color(1, 0, 0);
	// s[4].obj = sp;
	return (s);
}
int	main(int ac, char **av)
{
	// c = camera(201, 101, M_PI/2);
	// t_ray	r;
	// r = ray_for_pixel(c, 0, 0);
	// printf("%.5f, %.5f, %.5f\n", r.origine.x,r.origine.y,r.origine.z);
	// printf("%.5f, %.5f, %.5f\n", r.direction.x,r.direction.y,r.direction.z);
	
	// if (ac == 2)
	// {
	// 	read_file(av[1]);
	// }
	// s = malloc(sizeof(t_shape));

	(void)ac;
	(void)av;
	// t_shape		s;
	// s = default_shape();
	// s.obj = co;
	// t_ray r = ray(create_point(0,0,-5), normalize(create_vector(1,1,1)));
	// t_intersect *xs = cone_intersect(s, r);
	// printf("%f\n", xs->min); 
	t_shape *s;
	s = create_shape();
	s[1].raduis = 1;
	s[1].closed = true;
	t_d_pars p = {2, 1};
	t_light		*l;
	t_word		w;
	s = create_shape();
	l = malloc(sizeof(t_light) * 1);
	ft_free(ADD, l);
	l[0] = point_light(create_point(0, 2, -5), create_color(1, 1, 1));
	// l[1] = point_light(create_point(0, 20, 0), create_color(1, 1, 1));
	w = word(s, l);
	w.ambiant = mul_by_scaler(create_color(1, 1, 1), 0.1);
	t_camera c = camera(500, 500, M_PI/ 3);
	c.trans = view_transformation(create_point(0, 2, -5), create_point(0,
				0, 1), create_vector(0, 1, 0));
	render(w, c, p);
	// t_shape s = default_shape();
	// t_intersect *xs = cube_intersect(s, ray(create_point(-2, 0, 0), create_vector(0.2673, 0.5345, 0.8018)));
	// printf ("%f  \n", xs->min);
	// t_word w = default_word();
	// t_point point = create_point(-2, 2, -2);
	// printf("is %d\n", is_shadowed(w, point, 2));
	// render(c, w);
	// t_ray r = ray_for_pixel(c, 100, 50);
	// t_intersect *xs = intersect_world(w, r);
	// int i = 0;
	// while (xs)
	// {
	// 	printf("%d : %f  %f\n",i,  xs->min, xs->max);
	// 	xs = xs->next;
	// 	i++;
	// }
	// int main()
	// {
	// double **m = identity();
	// m[0][0] =  -5;
	// m[0][1] =  2;
	// m[0][2] =  6;
	// m[0][3] =  -8;
	// m[1][0] =  1;
	// m[1][1] =  -5;
	// m[1][2] =  1;
	// m[1][3] =  8;
	// m[2][0] =  7;
	// m[2][1] =  7;
	// m[2][2] =  -6;
	// m[2][3] =  -7;
	// m[3][0] =  1;
	// m[3][1] =  -3;
	// m[3][2] =  7;
	// m[3][3] =  4;
	// // double **n = identity();
	// // for (int i = 0; i < 4; i++)
	// // 	for (int j = 0; j < 4; j++)
	// // 		n[i][j] = m[i][j];
	// double **res = inverse_gauss(m);
	// print_matrice(res);
	// puts("---------------------");
	// print_matrice(m);
}
