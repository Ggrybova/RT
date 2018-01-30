/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:07:59 by vyastrub          #+#    #+#             */
/*   Updated: 2018/01/20 18:45:51 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static char	*read_file(char *file)
{
	char			*s;
	char			*l;
	char			buf[10 + 1];
	int				fd;

	s = ft_strnew(0);
	if ((fd = open(file, O_RDONLY)) < 0 || read(fd, buf, 0) < 0 || !s)
	{
		ft_putstr("Cannot open file\n");
		exit(0);
	}
	ft_bzero(buf, 10 + 1);
	while (read(fd, buf, 10) > 0)
	{
		l = ft_strjoin(s, buf);
		free(s);
		s = ft_strdup(l);
		free(l);
		ft_bzero(buf, 10 + 1);
	}
	close(fd);
	return (s);
}

static void	destroy_all(t_arr *gl)
{
	SDL_DestroyWindow(gl->sdl->win);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int			main(int ac, char **av)
{
	t_arr	*gl;
	ini_t	*ini;
	char	*s;

	(ac != 2 ? ft_error(2) : 0);
	gl = (t_arr*)malloc(sizeof(t_arr));
	s = read_file(av[1]);
	ini = ini_load(s, 0);
	gl->total = ini_section_count(ini) - 3;
	gl->all_obj = (t_obj **)malloc(sizeof(t_obj) * gl->total);
	parsing(gl, ini);
	init_all(gl);
	SDL_SetRenderDrawColor(gl->sdl->renderer, 100, 100, 100, 255);
	while (gl->running)
	{
		gl->menu->flag.d = 0;
		if (SDL_PollEvent(&(gl->sdl->event)))
			events(gl);
		checking_flags(gl, -1, -1);
		SDL_Delay(1);
	}
	destroy_all(gl);
	return (0);
}
