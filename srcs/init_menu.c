/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 09:58:00 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 10:03:56 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	init_sphere_menu(t_arr *gl, int k, int x, int y)
{
	count_sphere(gl);
	fill_names_sp(gl);
	while (++k < gl->menu->cnt_sp && k < 4)
	{
		if (k == 1 || k == 3)
			x += 400;
		else if (k == 2)
		{
			x -= 400;
			y += 400;
		}
		fill_sp(gl, k, x, y);
		fill_data_sp(gl, k, (x + 150), y);
	}
}

void	init_cyl_menu(t_arr *gl, int k, int x, int y)
{
	count_cylinder(gl);
	fill_names_cyl(gl);
	while (++k < gl->menu->cnt_cyl && k < 4)
	{
		if (k == 1 || k == 3)
			x += 400;
		else if (k == 2)
		{
			x -= 400;
			y += 400;
		}
		fill_cyl(gl, k, x, y);
		fill_data_cyl(gl, k, (x + 150), y);
	}
}

void	init_conus_menu(t_arr *gl, int k, int x, int y)
{
	count_conus(gl);
	fill_names_con(gl);
	while (++k < gl->menu->cnt_con && k < 4)
	{
		if (k == 1 || k == 3)
			x += 400;
		else if (k == 2)
		{
			x -= 400;
			y += 400;
		}
		fill_con(gl, k, x, y);
		fill_data_con(gl, k, (x + 150), y);
	}
}

void	init_torus_menu(t_arr *gl, int k, int x, int y)
{
	count_tor(gl);
	fill_names_tor(gl);
	while (++k < gl->menu->cnt_tor && k < 4)
	{
		if (k == 1 || k == 3)
			x += 400;
		else if (k == 2)
		{
			x -= 400;
			y += 400;
		}
		fill_tor(gl, k, x, y);
		fill_data_tor(gl, k, (x + 150), y);
	}
}

void	init_menu(t_arr *gl)
{
	init_sphere_menu(gl, -1, 200, 100);
	init_cyl_menu(gl, -1, 200, 100);
	init_conus_menu(gl, -1, 200, 100);
	init_torus_menu(gl, -1, 200, 100);
	init_par_menu(gl, -1, 200, 100);
	init_disk_menu(gl, -1, 200, 100);
}
