/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_conus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:40:43 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 07:46:49 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	info_to_str_sp5(t_arr *gl, int k, int flag)
{
	if (flag == 9)
	{
		double2str1(gl, gl->all_obj[gl->menu->con[k].index]->refraction);
		gl->menu->con[k].info[9] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->con[k].info[9], gl->a);
		free(gl->a);
	}
	else if (flag == 8)
	{
		double2str1(gl, gl->all_obj[gl->menu->con[k].index]->reflection);
		gl->menu->con[k].info[8] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->con[k].info[8], gl->a);
		free(gl->a);
	}
	else if (flag == 10)
	{
		gl->a = ft_itoa(gl->menu->con[k].index);
		gl->menu->con[k].info[10] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->con[k].info[10], gl->a);
		free(gl->a);
	}
}

static void	info_to_str_sp4(t_arr *gl, int k, int flag)
{
	if (flag == 6)
	{
		double2str1(gl, gl->all_obj[gl->menu->con[k].index]->diffuse);
		gl->menu->con[k].info[6] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->con[k].info[6], gl->a);
		free(gl->a);
	}
	else if (flag == 7)
	{
		double2str1(gl, gl->all_obj[gl->menu->con[k].index]->specular);
		gl->menu->con[k].info[7] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->con[k].info[7], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp5(gl, k, flag);
}

static void	info_to_str_sp3(t_arr *gl, int k, int flag)
{
	if (flag == 4)
	{
		gl->a = ft_itoa(gl->all_obj[gl->menu->con[k].index]->cap);
		gl->menu->con[k].info[4] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->con[k].info[4], gl->a);
		free(gl->a);
	}
	else if (flag == 5)
	{
		concat_color(gl, gl->all_obj[gl->menu->con[k].index]->color->arr[0],
			gl->all_obj[gl->menu->con[k].index]->color->arr[1],
			gl->all_obj[gl->menu->con[k].index]->color->arr[2]);
		gl->menu->con[k].info[5] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->con[k].info[5], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp4(gl, k, flag);
}

static void	info_to_str_sp2(t_arr *gl, int k, int flag)
{
	if (flag == 2)
	{
		double2str1(gl, gl->all_obj[gl->menu->con[k].index]->k);
		gl->menu->con[k].info[2] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->con[k].info[2], gl->a);
		free(gl->a);
	}
	else if (flag == 3)
	{
		gl->a = ft_itoa(gl->all_obj[gl->menu->con[k].index]->h);
		gl->menu->con[k].info[3] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->con[k].info[3], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp3(gl, k, flag);
}

void		info_to_str_con(t_arr *gl, int k, int flag)
{
	if (flag == 0)
	{
		concat_cord(gl, gl->all_obj[gl->menu->con[k].index]->c);
		gl->menu->con[k].info[0] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->con[k].info[0], gl->a);
		free(gl->a);
	}
	else if (flag == 1)
	{
		concat_cord(gl, gl->all_obj[gl->menu->con[k].index]->v);
		gl->menu->con[k].info[1] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->con[k].info[1], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp2(gl, k, flag);
}
