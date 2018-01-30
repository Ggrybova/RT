/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_par.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:18:23 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 12:36:10 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	info_to_str_sp5(t_arr *gl, int k, int flag)
{
	if (flag == 10)
	{
		double2str1(gl, gl->all_obj[gl->menu->par[k].index]->refraction);
		gl->menu->par[k].info[10] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[10], gl->a);
		free(gl->a);
	}
	else if (flag == 11)
	{
		gl->a = ft_itoa(gl->menu->par[k].index);
		gl->menu->par[k].info[11] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[11], gl->a);
		free(gl->a);
	}
	else
		info_to_str_par6(gl, k, flag);
}

static void	info_to_str_sp4(t_arr *gl, int k, int flag)
{
	if (flag == 8)
	{
		double2str1(gl, gl->all_obj[gl->menu->par[k].index]->specular);
		gl->menu->par[k].info[8] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[8], gl->a);
		free(gl->a);
	}
	else if (flag == 9)
	{
		double2str1(gl, gl->all_obj[gl->menu->par[k].index]->reflection);
		gl->menu->par[k].info[9] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[9], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp5(gl, k, flag);
}

static void	info_to_str_sp3(t_arr *gl, int k, int flag)
{
	if (flag == 4)
	{
		double2str1(gl, gl->all_obj[gl->menu->par[k].index]->k);
		gl->menu->par[k].info[4] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[4], gl->a);
		free(gl->a);
	}
	else if (flag == 7)
	{
		double2str1(gl, gl->all_obj[gl->menu->par[k].index]->diffuse);
		gl->menu->par[k].info[7] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[7], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp4(gl, k, flag);
}

static void	info_to_str_sp2(t_arr *gl, int k, int flag)
{
	if (flag == 2)
	{
		gl->a = ft_itoa(gl->all_obj[gl->menu->par[k].index]->r2);
		gl->menu->par[k].info[2] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[2], gl->a);
		free(gl->a);
	}
	else if (flag == 3)
	{
		gl->a = ft_itoa(gl->all_obj[gl->menu->par[k].index]->cap);
		gl->menu->par[k].info[3] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[3], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp3(gl, k, flag);
}

void		info_to_str_par(t_arr *gl, int k, int flag)
{
	if (flag == 0)
	{
		concat_cord(gl, gl->all_obj[gl->menu->par[k].index]->c);
		gl->menu->par[k].info[0] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[0], gl->a);
		free(gl->a);
	}
	else if (flag == 1)
	{
		concat_cord(gl, gl->all_obj[gl->menu->par[k].index]->v);
		gl->menu->par[k].info[1] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->par[k].info[1], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp2(gl, k, flag);
}
