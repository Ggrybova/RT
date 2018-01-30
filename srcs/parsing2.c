/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 13:49:10 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 15:19:31 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

char		*get_data(ini_t *ini, int i, char *name_prop, int prop)
{
	char	*a;
	int		len;

	if (i < 0)
		ft_error(1);
	if (prop == -1)
	{
		len = (int)ft_strlen(name_prop);
		prop = ini_find_property(ini, i, name_prop, len + 1);
		if (prop == -1)
			ft_error(1);
		a = (char*)ini_property_value(ini, i, prop);
		return (a);
	}
	a = (char*)ini_property_value(ini, i, prop);
	return (a);
}

static void	parse_objects_continue(t_arr *gl, ini_t *ini, int n, int s)
{
	while (++s < n)
	{
		if (ft_strcmp(ini_section_name(ini, s), "object") != 0)
			ft_error(1);
		if (ft_strcmp(ini_property_value(ini, s, 0), "plane") == 0)
			gl->all_obj[gl->j[7]++] = set_obj(gl->pln[gl->j[0]++], ini, s);
		else if (ft_strcmp(ini_property_value(ini, s, 0), "sphere") == 0)
			gl->all_obj[gl->j[7]++] = set_obj(gl->spr[gl->j[1]++], ini, s);
		else if (ft_strcmp(ini_property_value(ini, s, 0), "cylinder") == 0)
			gl->all_obj[gl->j[7]++] = set_obj(gl->box[gl->j[2]++], ini, s);
		else if (ft_strcmp(ini_property_value(ini, s, 0), "cone") == 0)
			gl->all_obj[gl->j[7]++] = set_obj(gl->con[gl->j[3]++], ini, s);
		else if (ft_strcmp(ini_property_value(ini, s, 0), "torus") == 0)
			gl->all_obj[gl->j[7]++] = set_obj(gl->tor[gl->j[4]++], ini, s);
		else if (ft_strcmp(ini_property_value(ini, s, 0), "disk") == 0)
			gl->all_obj[gl->j[7]++] = set_obj(gl->dsk[gl->j[5]++], ini, s);
		else if (ft_strcmp(ini_property_value(ini, s, 0), "paraboloid") == 0)
			gl->all_obj[gl->j[7]++] = set_obj(gl->prb[gl->j[6]++], ini, s);
		else
			ft_error(1);
	}
}

void		parse_objects(t_arr *gl, ini_t *ini, int n)
{
	int	s;

	s = 2;
	ft_memset(gl->j, 0, sizeof(int) * 8);
	create_objects(gl, ini, n);
	parse_objects_continue(gl, ini, n, s);
}

static void	create_objects_continue(t_arr *gl, ini_t *ini, int j)
{
	gl->pln = new_obj(gl->planes, gl, 1);
	gl->spr = new_obj(gl->spheres, gl, 2);
	gl->box = new_obj(gl->cylindres, gl, 3);
	gl->con = new_obj(gl->cones, gl, 4);
	gl->tor = new_obj(gl->tores, gl, 5);
	gl->dsk = new_obj(gl->disks, gl, 6);
	gl->prb = new_obj(gl->parab, gl, 7);
}

void		create_objects(t_arr *gl, ini_t *ini, int j)
{
	while (--j > 2)
	{
		if (ft_strcmp(ini_property_value(ini, j, 0), "plane\0") == 0)
			gl->planes++;
		else if (ft_strcmp(ini_property_value(ini, j, 0), "sphere\0") == 0)
			gl->spheres++;
		else if (ft_strcmp(ini_property_value(ini, j, 0), "cylinder\0") == 0)
			gl->cylindres++;
		else if (ft_strcmp(ini_property_value(ini, j, 0), "cone\0") == 0)
			gl->cones++;
		else if (ft_strcmp(ini_property_value(ini, j, 0), "torus\0") == 0)
			gl->tores++;
		else if (ft_strcmp(ini_property_value(ini, j, 0), "disk\0") == 0)
			gl->disks++;
		else if (ft_strcmp(ini_property_value(ini, j, 0), "paraboloid\0") == 0)
			gl->parab++;
		else
			ft_error(1);
	}
	create_objects_continue(gl, ini, j);
}
