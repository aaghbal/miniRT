/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:31:08 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/27 17:59:48 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect *intersect(t_shape s, t_ray ray)
{
	t_intersect *res;
	t_data		data;
	double		t1;
	double		t2;
	t_ray		r;

	res = NULL;
	r = transform(ray, inverse_gauss(s.tranform));
	t_vector sph_to_ray = sub_to_point(r.origine, create_point(0, 0, 0));
	data.a = dot_product(r.direction, r.direction);
	data.b = 2 * dot_product(r.direction, sph_to_ray);
	data.c = dot_product(sph_to_ray, sph_to_ray) - 1;
	data.discr = pow(data.b, 2) - 4 * data.a * data.c;
	if (data.discr < 0)
	{
		res = new_intersec(0, s);
		return (res);
	}
	t1 = (-data.b - sqrt(data.discr)) / (2 * data.a); 
	t2 = (-data.b + sqrt(data.discr)) / (2 * data.a);
	if(t1 < t2 && t1 > 0)
		return (new_intersec(t1, s));
	else if (t2 > 0)
		return(new_intersec(t2, s));
	return (new_intersec(0, s)); 
}
t_intersect *intersect_world(t_word w, t_ray r, int n_object)
{
	t_intersect *xs;
	t_intersect *new;
	int i;
	
	i = 0;
	xs = NULL;
	while (i < n_object)
	{
		new = intersect(w.s[i], r);
		if (!xs)
			xs = new;
		else if (new->min < xs->min)
			add_front(&xs, new);
		else
			add_back(&xs, new);
		i++;
	}
	// exit(0);
	return (xs);
}

t_intersection intersection(double t, t_shape s)
{
	t_intersection i;

	i.t = t;
	i.sp = s;
	return(i);
}