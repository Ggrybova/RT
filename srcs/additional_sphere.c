/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:46:41 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 07:54:32 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	info_to_str_sp4(t_arr *gl, int k, int flag)
{
	if (flag == 6)
	{
		double2str1(gl, gl->all_obj[gl->menu->sp[k].index]->refraction);
		gl->menu->sp[k].info[6] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->sp[k].info[6], gl->a);
		free(gl->a);
	}
	else if (flag == 7)
	{
		gl->a = ft_itoa(gl->menu->sp[k].index);
		gl->menu->sp[k].info[7] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->sp[k].info[7], gl->a);
		free(gl->a);
	}
}

static void	info_to_str_sp3(t_arr *gl, int k, int flag)
{
	if (flag == 4)
	{
		double2str1(gl, gl->all_obj[gl->menu->sp[k].index]->specular);
		gl->menu->sp[k].info[4] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->sp[k].info[4], gl->a);
		free(gl->a);
	}
	else if (flag == 5)
	{
		double2str1(gl, gl->all_obj[gl->menu->sp[k].index]->reflection);
		gl->menu->sp[k].info[5] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->sp[k].info[5], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp4(gl, k, flag);
}

static void	info_to_str_sp2(t_arr *gl, int k, int flag)
{
	if (flag == 2)
	{
		concat_color(gl, gl->all_obj[gl->menu->sp[k].index]->color->arr[0],
			gl->all_obj[gl->menu->sp[k].index]->color->arr[1],
			gl->all_obj[gl->menu->sp[k].index]->color->arr[2]);
		gl->menu->sp[k].info[2] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->sp[k].info[2], gl->a);
		free(gl->a);
	}
	else if (flag == 3)
	{
		double2str1(gl, gl->all_obj[gl->menu->sp[k].index]->diffuse);
		gl->menu->sp[k].info[3] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->sp[k].info[3], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp3(gl, k, flag);
}

void		info_to_str_sp(t_arr *gl, int k, int flag)
{
	if (flag == 0)
	{
		concat_cord(gl, gl->all_obj[gl->menu->sp[k].index]->c);
		gl->menu->sp[k].info[0] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->sp[k].info[0], gl->a);
		free(gl->a);
	}
	else if (flag == 1)
	{
		gl->a = ft_itoa(gl->all_obj[gl->menu->sp[k].index]->r);
		gl->menu->sp[k].info[1] = (char *)malloc(sizeof(char) *
			(int)ft_strlen(gl->a));
		ft_strcpy(gl->menu->sp[k].info[1], gl->a);
		free(gl->a);
	}
	else
		info_to_str_sp2(gl, k, flag);
}
