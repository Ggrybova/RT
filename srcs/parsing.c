/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:25:14 by ggrybova          #+#    #+#             */
/*   Updated: 2018/01/20 17:09:22 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INI_IMPLEMENTATION
#include "../includes/rt.h"

static void	set_obj_continue(t_obj *obj, ini_t *ini, int i)
{
	char *a;
	char *b;
	char *c;

	a = get_data(ini, i, "color", -1);
	set_col(obj->color, ft_atoi(a), ft_atoi(cut_str(a, ',')),
				ft_atoi(cut_str(cut_str(a, ','), ',')));
	b = get_data(ini, i, "centre", -1);
	create_v(obj->c, ration_n(b), ration_n(cut_str(b, ',')),
				ration_n(cut_str(cut_str(b, ','), ',')));
	if (obj->flag != 2 && (c = get_data(ini, i, "direct", -1)) != NULL)
		create_v(obj->v, ration_n(c), ration_n(cut_str(c, ',')),
					ration_n(cut_str(cut_str(c, ','), ',')));
	obj->r = (obj->flag != 1 && obj->flag != 4 && obj->flag != 7) ?
		ration_n(get_data(ini, i, "radius1", -1)) : 0;
	obj->r2 = (obj->flag == 5 || obj->flag == 7) ?
		ration_n(get_data(ini, i, "radius2", -1)) : 0;
}

t_obj		*set_obj(t_obj *obj, ini_t *ini, int i)
{
	set_obj_continue(obj, ini, i);
	if (obj->flag == 3 || obj->flag == 4 || obj->flag == 7)
	{
		obj->h = ration_n(get_data(ini, i, "height", -1));
		obj->cap = ft_atoi(get_data(ini, i, "caps", -1));
		obj->k = (obj->flag == 4) ? ration_n(get_data(ini, i, "angle", -1)) *
			M_PI / 180 : 0;
		(obj->flag == 4) ? obj->r = obj->h * obj->k : obj->r;
	}
	obj->diffuse = ration_n(get_data(ini, i, "diffuse", -1));
	obj->specular = ration_n(get_data(ini, i, "specular", -1));
	obj->reflection = ration_n(get_data(ini, i, "reflection", -1));
	obj->refraction = ration_n(get_data(ini, i, "refraction", -1));
	if (obj->refraction > 1 || obj->reflection >= 1)
		set_col(obj->color, 0, 0, 0);
	return (obj);
}

static void	parsing_continue(t_arr *gl, ini_t *ini, char *c)
{
	int i;

	i = -1;
	while (++i < THREADS)
	{
		gl->src[i] = (t_lsrc**)malloc(sizeof(t_lsrc*) * gl->lights);
		gl->s[0] = -1;
		while (++gl->s[0] < gl->lights &&
			(c = get_data(ini, gl->s[2], 0, gl->s[0])) != NULL)
		{
			gl->src[i][gl->s[0]] = (t_lsrc*)malloc(sizeof(t_lsrc));
			gl->src[i][gl->s[0]]->lgt = (t_vec*)malloc(sizeof(t_vec));
			create_v(gl->src[i][gl->s[0]]->lgt, ration_n(c), ration_n(cut_str(c,
				',')), ration_n(cut_str(cut_str(c, ','), ',')));
		}
	}
}

void		parsing(t_arr *gl, ini_t *ini)
{
	char	*a;
	char	*b;
	char	*c;

	gl->s[1] = ini_find_section(ini, "scene\0", 6);
	gl->s[2] = ini_find_section(ini, "lights\0", 7);
	gl->scene_name = get_data(ini, gl->s[1], "name", -1);
	init(gl);
	a = get_data(ini, gl->s[1], "cam_orig", -1);
	create_v(&gl->eye, ration_n(a), ration_n(cut_str(a, ',')),
			ration_n(cut_str(cut_str(a, ','), ',')));
	b = get_data(ini, gl->s[1], "cam_dir", -1);
	create_v(&gl->screen, ration_n(b), ration_n(cut_str(b, ',')),
			ration_n(cut_str(cut_str(b, ','), ',')));
	gl->amb = ration_n(get_data(ini, gl->s[1], "ambient", -1));
	gl->lights = ini_property_count(ini, gl->s[2]);
	gl->src = (t_lsrc***)malloc(sizeof(t_lsrc**) * THREADS);
	parsing_continue(gl, ini, c);
	parse_objects(gl, ini, ini_section_count(ini));
}
