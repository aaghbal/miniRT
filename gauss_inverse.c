/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gauss_inverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:00:48 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/27 18:58:04 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// double  **inverse_gauss(double **n)
// {
//     double **s;
	
// 	double **m = identity();
// 	for (int i = 0; i < 4; i++)
// 		for (int j = 0; j < 4; j++)
// 			m[i][j] = n[i][j];

// 	if (!determinant_4(m, 4, 4))
// 		return (m);
//     s = identity();
//     for (int i = 0; i < 3; i++) {
//         int pivot = i;
//         double pivotsize = m[i][i];

//         if (pivotsize < 0)
// 			pivotsize = -pivotsize;

//         for (int j = i + 1; j < 4; j++) {
//             double tmp = m[j][i];

//             if (tmp < 0)
// 				tmp = -tmp;

//             if (tmp > pivotsize) {
//                 pivot = j;
//                 pivotsize = tmp;
//             }
//         }

//         if (pivotsize == 0) {
//             double **result = identity();
//             for (int j = 0; j < 4; j++) {
//                 result[j][j] = 1.0f;
//             }
//             return result;
//         }

//         if (pivot != i) {
//             for (int j = 0; j < 4; j++) {
//                 double tmp;

//                 tmp = m[i][j];
//                 m[i][j] = m[pivot][j];
//                 m[pivot][j] = tmp;

//                 tmp = s[i][j];
//                 s[i][j] = s[pivot][j];
//                 s[pivot][j] = tmp;
//             }
//         }
//         for (int j = i + 1; j < 4; j++) {
//             double f = m[j][i] / m[i][i];

//             for (int k = 0; k < 4; k++) {
//                 m[j][k] -= f * m[i][k];
//                 s[j][k] -= f * s[i][k];
//             }
//             m[j][i] = 0.f;
//         }
//     }
//     for (int i = 0; i < 4; i++) {
//         double divisor = m[i][i];
//         for (int j = 0; j < 4; j++) {
//             m[i][j] = m[i][j] / divisor;
//             s[i][j] = s[i][j] / divisor;
//         }
//         m[i][i] = 1.f;
//     }
//     for (int i = 0; i < 3; i++) {
//         for (int j = i + 1; j < 4; j++) {
//             double constant = m[i][j];
//             for (int k = 0; k < 4; k++) {
//                 m[i][k] -= m[j][k] * constant;
//                 s[i][k] -= s[j][k] * constant;
//             }
//             m[i][j] = 0.f;
//         }
//     }
//     return s;
// }

// // int main()
// // {
// // 	double **m = identity();
// // 	m[0][0] =  -5;
// // 	m[0][1] =  2;
// // 	m[0][2] =  6;
// // 	m[0][3] =  -8;
// // 	m[1][0] =  1;
// // 	m[1][1] =  -5;
// // 	m[1][2] =  1;
// // 	m[1][3] =  8;
// // 	m[2][0] =  7;
// // 	m[2][1] =  7;
// // 	m[2][2] =  -6;
// // 	m[2][3] =  -7;
// // 	m[3][0] =  1;
// // 	m[3][1] =  -3;
// // 	m[3][2] =  7;
// // 	m[3][3] =  4;

// // 	double **res = inverse_gauss(m);
// // 	print_matrice(res);
// // }

double	**join_matr_ind(double **m)
{
	int i = 0;
	int j = 0;
	int l = 0;
	double **mat;
	double **id = identity();
	mat = malloc(sizeof(double *) * 4);
	while (i < 4)
	{
		j = 0;
		l = 0;
		mat[i] = malloc(sizeof(double) * 8);
		while (j < 8)
		{
			if (j < 4)
				mat[i][j] = m[i][j];
			else
			{
				mat[i][j] = id[i][l];
				l++;
			}
			j++;
		}
		i++;
	}
	return(mat);
}

// double **inverse_gauss(double **m) 
// {
// 	int i = 0;
// 	int j = 0;
// 	double **n = identity();
// 	for (int i = 0; i < 4; i++)
// 		for (int j = 0; j < 4; j++)
// 			n[i][j] = m[i][j];
// 	double **mat = join_matr_ind(n);
//     while(i < 4)
// 	{
//         double diagElem = mat[i][i];
// 		j = 0;
//         while(j < 8)
// 		{
//             mat[i][j] /= diagElem;
// 			j++;
//         }
// 		int k = 0;
//         while(k < 4)
// 		{
//             if (k != i)
// 			{
//                 double factor = mat[k][i];
// 				j = 0;
//                  while(j < 8)
// 				 {
//                     mat[k][j] -= factor * mat[i][j];
// 					j++;
//                 }
//             }
// 			k++;
//         }
// 		i++;
//     }
// 	int r = 0;
// 	i = 0;
// 	int a;
// 	while (r < 4)
// 	{
// 		a = 4;
// 		i = 0;
// 		while(a < 8)
// 		{
// 			n[r][i] = mat[r][a];
// 			i++;
// 			a++;
// 		}
// 		r++;
// 	}
// 	return (n);
// }

double **inverse_gauss(double **m) 
{
    int i = 0;
    int j = 0;
	// if (!determinant_4(m, 4, 4))
	// 	return (identity());
    double **n = identity();
    
    // Copy the input matrix 'm' to 'n'
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            n[i][j] = m[i][j];
    
    double **mat = join_matr_ind(n);

    while(i < 4)
    {
        double diagElem = mat[i][i];
        
        // Check if the diagonal element is close to zero
        if (fabs(diagElem) < EPSILON) {
            // Find a row below with a nonzero diagonal element and swap them
            int swapRow = -1;
            for (int k = i + 1; k < 4; k++) {
                if (fabs(mat[k][i]) >= EPSILON) {
                    swapRow = k;
                    break;
                }
            }
            if (swapRow == -1) {
                // Matrix is singular, cannot proceed
                // Handle the error or return an appropriate value
                return NULL;
            }
            
            // Swap rows i and swapRow in 'mat' and 'n'
            for (int j = 0; j < 8; j++) {
                double temp = mat[i][j];
                mat[i][j] = mat[swapRow][j];
                mat[swapRow][j] = temp;
            }
            
            // Also swap rows in 'n'
            for (int j = 0; j < 4; j++) {
                double temp = n[i][j];
                n[i][j] = n[swapRow][j];
                n[swapRow][j] = temp;
            }
            
            diagElem = mat[i][i]; // Update the diagonal element
        }
        
        j = 0;
        
        // Perform row operations to make the diagonal element 1
        while(j < 8)
        {
            mat[i][j] /= diagElem;
            j++;
        }
        
        int k = 0;
        while(k < 4)
        {
            if (k != i)
            {
                double factor = mat[k][i];
                j = 0;
                while(j < 8)
                {
                    mat[k][j] -= factor * mat[i][j];
                    j++;
                }
            }
            k++;
        }
        
        i++;
    }
    
    int r = 0;
    i = 0;
    int a;
    while (r < 4)
    {
        a = 4;
        i = 0;
        while(a < 8)
        {
            n[r][i] = mat[r][a];
            i++;
            a++;
        }
        r++;
    }
    
    return n;
}