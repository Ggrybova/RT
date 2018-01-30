/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_dsk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 06:40:38 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 07:49:36 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	info_to_str_sp4(t_arr *gl, int k, int flag)
{
	if (flag == 7)
	{
		double2str1(gl, gl->all_obj[gl->menu->dsk[k].index]->refraction);
		gl->menu->dsk[k].info[7] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->dsk[k].info[7], gl->a);
		free(gl->a);
	}
	else if (flag == 6)
	{
		double2str1(gl, gl->all_obj[gl->menu->dsk[k].index]->reflection);
		gl->menu->dsk[k].info[6] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->dsk[k].info[6], gl->a);
		free(gl->a);
	}
	else if (flag == 8)
	{
		gl->a = ft_itoa(gl->menu->dsk[k].index);
		gl->menu->dsk[k].info[8] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->dsk[k].info[8], gl->a);
		free(gl->a);
	}
}

static void	info_to_str_sp3(t_arr *gl, int k, int flag)
{
	if (flag == 4)
	{
		double2str1(gl, gl->all_obj[gl->menu->dsk[k].index]->diffuse);
		gl->menu->dsk[k].info[4] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->dsk[k].info[4], gl->a);
		free(gl->a);
	}
	if (flag == 5)
	{
		double2str1(gl, gl->all_obj[gl->menu->dsk[k].index]->specular);
		gl->menu->dsk[k].info[5] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->dsk[k].info[5], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp4(gl, k, flag);
}

static void	info_to_str_sp2(t_arr *gl, int k, int flag)
{
	if (flag == 2)
	{
		gl->a = ft_itoa(gl->all_obj[gl->menu->dsk[k].index]->r);
		gl->menu->dsk[k].info[2] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->dsk[k].info[2], gl->a);
		free(gl->a);
	}
	if (flag == 3)
	{
		concat_color(gl, gl->all_obj[gl->menu->dsk[k].index]->color->arr[0],
			gl->all_obj[gl->menu->dsk[k].index]->color->arr[1],
			gl->all_obj[gl->menu->dsk[k].index]->color->arr[2]);
		gl->menu->dsk[k].info[3] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->dsk[k].info[3], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp3(gl, k, flag);
}

void		info_to_str_dsk(t_arr *gl, int k, int flag)
{
	if (flag == 0)
	{
		concat_cord(gl, gl->all_obj[gl->menu->dsk[k].index]->c);
		gl->menu->dsk[k].info[0] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->dsk[k].info[0], gl->a);
		free(gl->a);
	}
	else if (flag == 1)
	{
		concat_cord(gl, gl->all_obj[gl->menu->dsk[k].index]->v);
		gl->menu->dsk[k].info[1] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->dsk[k].info[1], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp2(gl, k, flag);
}
