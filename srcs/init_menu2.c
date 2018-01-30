/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:01:56 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 10:04:05 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	init_par_menu(t_arr *gl, int k, int x, int y)
{
	count_par(gl);
	fill_names_par(gl);
	while (++k < gl->menu->cnt_par && k < 4)
	{
		if (k == 1 || k == 3)
			x += 400;
		else if (k == 2)
		{
			x -= 400;
			y += 400;
		}
		fill_par(gl, k, x, y);
		fill_data_par(gl, k, (x + 150), y);
	}
}

void	init_disk_menu(t_arr *gl, int k, int x, int y)
{
	count_dsk(gl);
	fill_names_dsk(gl);
	while (++k < gl->menu->cnt_dsk && k < 4)
	{
		if (k == 1 || k == 3)
			x += 400;
		else if (k == 2)
		{
			x -= 400;
			y += 400;
		}
		fill_dsk(gl, k, x, y);
		fill_data_dsk(gl, k, (x + 150), y);
	}
}
