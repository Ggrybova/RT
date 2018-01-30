/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:16:47 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 12:35:55 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	info_to_str_par6(t_arr *gl, int k, int flag)
{
	if (flag == 6)
	{
		concat_color(gl, gl->all_obj[gl->menu->par[k].index]->color->arr[0],
			gl->all_obj[gl->menu->par[k].index]->color->arr[1],
			gl->all_obj[gl->menu->par[k].index]->color->arr[2]);
		gl->menu->par[k].info[6] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[6], gl->a);
		free(gl->a);
	}
	else if (flag == 5)
	{
		gl->a = ft_itoa(gl->all_obj[gl->menu->par[k].index]->h);
		gl->menu->par[k].info[5] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[5], gl->a);
		free(gl->a);
	}
}

void	double2str1(t_arr *gl, double d)
{
	int		tmp;
	double	tmp1;

	gl->b = ft_itoa(d);
	tmp = (int)d;
	tmp1 = d - (double)tmp;
	tmp = (int)(tmp1 * 100);
	gl->c = ft_strjoin(gl->b, ".");
	free(gl->b);
	gl->b = ft_itoa(tmp);
	gl->a = ft_strjoin(gl->c, gl->b);
	free(gl->c);
	free(gl->b);
}

void	double2str(double d, char **a)
{
	*a = ft_itoa(d);
}

void	concat_cord(t_arr *gl, t_vec *vec)
{
	gl->b = ft_itoa(vec->x);
	gl->c = ft_strjoin(gl->b, ", ");
	free(gl->b);
	gl->b = ft_itoa(vec->y);
	gl->d = ft_strjoin(gl->c, gl->b);
	free(gl->c);
	free(gl->b);
	gl->b = ft_itoa(vec->z);
	gl->c = ft_strjoin(gl->d, ", ");
	free(gl->d);
	gl->a = ft_strjoin(gl->c, gl->b);
	free(gl->c);
	free(gl->b);
}

void	concat_color(t_arr *gl, int r, int g, int b)
{
	gl->b = ft_itoa(r);
	gl->c = ft_strjoin(gl->b, ", ");
	free(gl->b);
	gl->b = ft_itoa(g);
	gl->d = ft_strjoin(gl->c, gl->b);
	free(gl->c);
	free(gl->b);
	gl->b = ft_itoa(b);
	gl->c = ft_strjoin(gl->d, ", ");
	free(gl->d);
	gl->a = ft_strjoin(gl->c, gl->b);
	free(gl->c);
	free(gl->b);
}
