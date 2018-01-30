/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:28:56 by vyastrub          #+#    #+#             */
/*   Updated: 2018/01/20 22:52:56 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "ini.h"
# include "../libft/libft.h"
# include <pthread.h>

# include <SDL2/SDL.h>
# include <SDL2_image/SDL_image.h>
# include <SDL2_mixer/SDL_mixer.h>
# include <SDL2_ttf/SDL_ttf.h>

# define W 1000
# define H 1000
# define DEPTH 7
# define AIR 1
# define BIAS 0.00005
# define BCKG 0x000000
# define AMBI 0.015
# define THREADS 8
# define COLOR_WHITE {255, 255, 255, 255}
# define COLOR_BLACK {0, 0, 0, 255}
# define COLOR_YELLOW {234, 255, 88, 255}
# define COLOR_BLUE {88, 107, 255, 255}

typedef	struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef	struct	s_col
{
	int			r;
	int			g;
	int			b;
	int			arr[3];
}				t_col;

typedef struct	s_ray
{
	t_vec		*org;
	t_vec		*dir;
}				t_ray;

typedef struct	s_pol
{
	int			deg;
	double		s;
	double		p;
	double		q;
	double		r;
	double		f;
	double		x_im[4];
	double		x_re[4];
}				t_pol;

typedef struct	s_cam
{
	int			x_a;
	int			y_a;
	int			z_a;
	double		x_t;
	double		y_t;
	double		z_t;
	double		trans[4][4];
	double		rot_x[4][4];
	double		rot_y[4][4];
	double		rot_z[4][4];
	double		res[4][4];
}				t_cam;

typedef struct	s_lsrc
{
	t_vec		*lgt;
	double		lamb;
	double		fong;
	double		ambi;

}				t_lsrc;

typedef struct	s_obj
{
	t_vec		*c;
	t_vec		*c2;
	t_vec		*v;
	t_col		*color;
	double		r;
	double		r2;
	double		k;
	double		h;
	int			cap;
	double		specular;
	double		diffuse;
	int			flag;
	int			index;
	double		reflection;
	double		refraction;
	int			(*intersect)();
	void		(*normal)();
}				t_obj;

typedef struct	s_current
{
	t_obj		*obj;
	t_col		*col;
	double		dt;
	double		gloss;
	double		ref_c;
	double		n1;
	double		n2;
	int			flag;
	int			i;
	int			cap;
	void		(*normal)();
	int			id;
	int			mirror;
	t_vec		p;
	t_vec		n;
	t_ray		*ray;
	t_ray		*bck;

}				t_current;

typedef struct	s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		event;
}				t_sdl;

typedef struct	s_clr
{
	int			r;
	int			g;
	int			b;
}				t_clr;

typedef	struct	s_flag
{
	int			team;
	int			menu;
	int			d;
	int			pos;
	int			help;
}				t_flag;

typedef	struct	s_sp_menu
{
	SDL_Texture	*texture_text_sp[8];
	SDL_Rect	rect_text_sp[8];
	SDL_Texture	*t_text_sp[8];
	SDL_Rect	r_text_sp[8];
	char		**info;
	int			index;
}				t_sp_menu;

typedef	struct	s_cyl_menu
{
	SDL_Texture	*texture_text_cyl[11];
	SDL_Rect	rect_text_cyl[11];
	SDL_Texture	*t_text_cyl[11];
	SDL_Rect	r_text_cyl[11];
	char		**info;
	int			index;
}				t_cyl_menu;

typedef	struct	s_con_menu
{
	SDL_Texture	*texture_text_con[11];
	SDL_Rect	rect_text_con[11];
	SDL_Texture	*t_text_con[11];
	SDL_Rect	r_text_con[11];
	char		**info;
	int			index;
}				t_con_menu;

typedef	struct	s_tor_menu
{
	SDL_Texture	*texture_text_tor[10];
	SDL_Rect	rect_text_tor[10];
	SDL_Texture	*t_text_tor[10];
	SDL_Rect	r_text_tor[10];
	char		**info;
	int			index;
}				t_tor_menu;

typedef	struct	s_par_menu
{
	SDL_Texture	*texture_text_par[11];
	SDL_Rect	rect_text_par[11];
	SDL_Texture	*t_text_par[11];
	SDL_Rect	r_text_par[11];
	char		**info;
	int			index;
}				t_par_menu;

typedef	struct	s_dsk_menu
{
	SDL_Texture	*texture_text_dsk[9];
	SDL_Rect	rect_text_dsk[9];
	SDL_Texture	*t_text_dsk[9];
	SDL_Rect	r_text_dsk[9];
	char		**info;
	int			index;
}				t_dsk_menu;

typedef struct	s_menu
{
	t_flag		flag;
	SDL_Surface	*surface;
	SDL_Texture	*texture_img[10];
	SDL_Rect	rect_img[10];
	TTF_Font	*font;
	TTF_Font	*font_info;
	SDL_Texture	*texture_text[8];
	SDL_Rect	rect_text[8];
	char		**tab_names;
	char		**names_sp;
	int			cnt_sp;
	t_sp_menu	*sp;
	char		**names_cyl;
	int			cnt_cyl;
	t_cyl_menu	*cyl;
	char		**names_con;
	int			cnt_con;
	t_con_menu	*con;
	char		**names_tor;
	int			cnt_tor;
	t_tor_menu	*tor;
	char		**names_par;
	int			cnt_par;
	t_par_menu	*par;
	char		**names_dsk;
	int			cnt_dsk;
	t_dsk_menu	*dsk;
}				t_menu;

typedef	struct	s_arr
{
	double		s1;
	int			tmp;
	int			res1;
	int			uv;
	int			grey;
	char		*a;
	char		*b;
	char		*c;
	char		*d;
	int			s[3];
	int			j[8];
	double		n;
	t_sdl		*sdl;
	int			running;
	t_menu		*menu;
	t_clr		cl[W][H];
	void		*mlx;
	void		*win;
	void		*img;
	char		*scene_name;
	t_current	***cur;
	t_cam		cam;
	t_lsrc		***src;
	double		amb;
	t_obj		**all_obj;
	t_obj		**spr;
	t_obj		**pln;
	t_obj		**box;
	t_obj		**con;
	t_obj		**tor;
	t_obj		**dsk;
	t_obj		**prb;
	t_vec		arr[H][W];
	t_vec		res[H][W];
	t_vec		eye;
	t_vec		screen;
	int			total;
	int			lights;
	int			planes;
	int			spheres;
	int			cylindres;
	int			cones;
	int			tores;
	int			disks;
	int			parab;
	int			iter[THREADS];
	double		t[THREADS];
	double		t2[THREADS];
}				t_arr;

typedef struct	s_pthr_data
{
	int			max_y;
	int			y;
	int			id;
	t_arr		*gl;
	t_current	**cur;
}				t_pthr_data;

/*
**				after_action.c
*/
void			checking_flags(t_arr *gl, int y, int x);

/*
**				after_action2.c
*/
void			change_menu_tabs3(t_arr *gl, int i, int j);
void			checking_flags_s2(t_arr *gl);
/*
**				additional_conus.c
*/
void			info_to_str_con(t_arr *gl, int k, int flag);

/*
**				additional_conus.c
*/
void			info_to_str_cyl(t_arr *gl, int k, int flag);

/*
**				additional_dsk.c
*/
void			info_to_str_dsk(t_arr *gl, int k, int flag);

/*
**				additional_par.c
*/
void			info_to_str_par(t_arr *gl, int k, int flag);

/*
**				additional_sphere.c
*/
void			info_to_str_sp(t_arr *gl, int k, int flag);

/*
**				additional_tor.c
*/
void			info_to_str_tor(t_arr *gl, int k, int flag);

/*
**				additional_func.c
*/
void			double2str1(t_arr *gl, double d);
void			concat_cord(t_arr *gl, t_vec *vec);
void			concat_color(t_arr *gl, int r, int g, int b);
void			info_to_str_par6(t_arr *gl, int k, int flag);

/*
**				rgb.c
*/
int				getcol(t_arr *gl, t_col *col, t_current *cur);

/*
**				camera.c
*/
void			to_arr(t_arr *gl);
void			cr_res(t_arr *gl, double m1[4][4], double m2[4][4]);
void			multiple(t_arr *gl, t_cam cam, int i, int j);

/*
**				color.c
*/
void			light(t_current *cur, t_lsrc *src);
void			normal_spr_pln(t_current *cur);
void			normal_con_cyl(t_current *cur);
void			normal_tor(t_current *cur);
void			normal_prb(t_current *cur);

/*
**				conus_menu.c
*/
void			count_conus(t_arr *gl);
void			fill_names_con(t_arr *gl);
void			fill_con(t_arr *gl, int k, int x, int y);
void			get_data_from_con(t_arr *gl, int k);

/*
**				cylinder_menu.c
*/
void			count_cylinder(t_arr *gl);
void			fill_names_cyl(t_arr *gl);
void			fill_cyl(t_arr *gl, int k, int x, int y);
void			get_data_from_cyl(t_arr *gl, int k);

/*
**				disk_menu.c
*/
void			count_dsk(t_arr *gl);
void			fill_names_dsk(t_arr *gl);
void			fill_dsk(t_arr *gl, int k, int x, int y);
void			get_data_from_dsk(t_arr *gl, int k);

/*
**				parab_menu.c
*/
void			count_par(t_arr *gl);
void			fill_names_par(t_arr *gl);
void			fill_par(t_arr *gl, int k, int x, int y);
void			get_data_from_par(t_arr *gl, int k);

/*
**				sphere_menu.c
*/
void			count_sphere(t_arr *gl);
void			fill_names_sp(t_arr *gl);
void			fill_sp(t_arr *gl, int k, int x, int y);
void			get_data_from_sp(t_arr *gl, int k);

/*
**				torus_menu.c
*/
void			count_tor(t_arr *gl);
void			fill_names_tor(t_arr *gl);
void			fill_tor(t_arr *gl, int k, int x, int y);
void			get_data_from_tor(t_arr *gl, int k);

/*
**				cylinder_cone.c
*/
double			caps(t_ray *ray, t_obj *obj);
double			find_t(double t, t_ray *ray, t_obj *obj);
void			limit_obj(t_arr *gl, t_ray *ray, t_obj *obj, int i);
int				cylin_inter(t_arr *gl, t_ray *ray, t_obj *box, int thread);
int				conus_inter(t_arr *gl, t_ray *ray, t_obj *con, int thread);

/*
**				errors.c
*/
void			ft_error(int flag);

/*
**				events.c
*/
void			events(t_arr *gl);

/*
**				events2.c
*/
void			move_cam(t_arr *gl);
void			keydown_actions3(t_arr *gl);
void			keydown_actions2(t_arr *gl);

/*
**				extra.c
*/
char			*cut_str(char *str, char c);
double			ration_n(char *a);

/*
**				fill_data.c
*/
void			fill_tab_names(t_arr *gl);
void			fill_data_con(t_arr *gl, int k, int x, int y);
void			fill_data_tor(t_arr *gl, int k, int x, int y);
void			fill_data_par(t_arr *gl, int k, int x, int y);
void			fill_data_dsk(t_arr *gl, int k, int x, int y);

/*
**				fill_data2.c
*/
void			fill_data_sp(t_arr *gl, int k, int x, int y);
void			fill_data_cyl(t_arr *gl, int k, int x, int y);
void			detection(t_arr *gl, t_ray *ray, t_current **cur, int ind);
void			render(t_arr *gl, t_current *cur, t_lsrc *src);

/*
**				hyperboloid.c
*/
int				parab_inter(t_arr *gl, t_ray *ray, t_obj *hprb, int thread);

/*
**				init.c
*/
void			init_img(t_arr *gl);
void			init_flags_menu(t_arr *gl);
void			init_sdl(t_arr *gl);
void			init_all(t_arr *gl);

/*
**				init2.c
*/
void			init_font(t_arr *gl);

/*
**				init_menu.c
*/
void			init_menu(t_arr *gl);
void			init_torus_menu(t_arr *gl, int k, int x, int y);
void			init_conus_menu(t_arr *gl, int k, int x, int y);
void			init_cyl_menu(t_arr *gl, int k, int x, int y);
void			init_sphere_menu(t_arr *gl, int k, int x, int y);

/*
**				init_menu2.c
*/
void			init_par_menu(t_arr *gl, int k, int x, int y);
void			init_disk_menu(t_arr *gl, int k, int x, int y);

/*
**				intersection.c
*/
int				disc(t_arr *gl, double a[3], int thread);
int				plane_inter(t_arr *gl, t_ray *ray, t_obj *pln, int thread);
int				spher_inter(t_arr *gl, t_ray *ray, t_obj *spr, int thread);
int				disk_inter(t_arr *gl, t_ray *ray, t_obj *dsk, int thread);

/*
**				mtx_op.c
*/
void			mmul(t_arr *gl);

/*
**				operations.c
*/
t_vec			add(t_vec *a, t_vec *b, int flag);
t_vec			mul(t_vec *a, double d, int flag);
void			write_sum(t_vec *dest, t_vec *src1, t_vec *src2);
void			write_sub(t_vec *dest, t_vec *src1, t_vec *src2);
void			write_mul(t_vec *dest, t_vec *src1, double a);

/*
**				parsing.c
*/
t_obj			*set_obj(t_obj *obj, ini_t *ini, int i);
void			parsing(t_arr *gl, ini_t *ini);

/*
**				parsing2.c
*/
char			*get_data(ini_t *ini, int i, char *name_prop, int prop);
void			parse_objects(t_arr *gl, ini_t *ini, int n);
void			create_objects(t_arr *gl, ini_t *ini, int j);

/*
**				polynomials.c
*/
t_pol			polinom_2_degr(double a, double b, double c);
void			negative_discr(t_pol *res, double a, double b);
void			pozitive_discr(t_pol *res, double a, double b);
t_pol			polinom_3_degr(double a, double b, double c, double d);
t_pol			*polinom_4_degr(double b, double c, double d, double e);

/*
**				raytracing.c
*/
void			*raytrace(void *thread_data);
void			make_pthreads(t_arr *gl);
void			set_distance(t_arr *gl, t_current *current, t_obj *obj);
int				inshadow(t_arr *gl, t_obj **all, t_current *cur, double dist);
void			tracing(t_arr *gl, t_current **cur, int x, t_pthr_data *data);

/*
**				recursion.c
*/
void			refracting(t_arr *gl, t_current *src, t_current *cur, int i);
void			reflecting(t_arr *gl, t_current **cur, int i);
void			universal(t_arr *gl, t_current **cur, int i);

/*
**				scene.c
*/
t_ray			*new_ray(void);
void			init(t_arr *gl);
t_obj			*fill_obj(int fl, int i, int (*in)(), void (*n)());
t_obj			**new_obj(int c, t_arr *gl, int fl);

/*
**				tools.c
*/
double			dot(t_vec *a, t_vec *b);
void			norm(t_vec *a);
void			create_v(t_vec *vec, double x, double y, double z);
void			set_col(t_col *c, int r, int g, int b);

/*
**				tortus.c
*/
int				torus_inter(t_arr *gl, t_ray *ray, t_obj *tor, int thread);

#endif
