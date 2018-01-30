/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 09:51:16 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 21:06:19 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		init_img3(t_arr *gl, int i)
{
	gl->menu->surface = IMG_Load("img/light.png");
	gl->menu->texture_img[8] = SDL_CreateTextureFromSurface(gl->sdl->renderer,
		gl->menu->surface);
	SDL_FreeSurface(gl->menu->surface);
	gl->menu->surface = IMG_Load("img/keyboard.png");
	gl->menu->texture_img[9] = SDL_CreateTextureFromSurface(gl->sdl->renderer,
		gl->menu->surface);
	SDL_FreeSurface(gl->menu->surface);
	i = -1;
	while (++i < 10)
	{
		gl->menu->rect_img[i].x = 0;
		gl->menu->rect_img[i].y = 0;
		gl->menu->rect_img[i].w = W;
		gl->menu->rect_img[i].h = H;
	}
}

static void	init_img2(t_arr *gl, int i)
{
	gl->menu->surface = IMG_Load("img/parabaloid.png");
	gl->menu->texture_img[5] = SDL_CreateTextureFromSurface(gl->sdl->renderer,
		gl->menu->surface);
	SDL_FreeSurface(gl->menu->surface);
	gl->menu->surface = IMG_Load("img/disk.png");
	gl->menu->texture_img[6] = SDL_CreateTextureFromSurface(gl->sdl->renderer,
		gl->menu->surface);
	SDL_FreeSurface(gl->menu->surface);
	gl->menu->surface = IMG_Load("img/camera.png");
	gl->menu->texture_img[7] = SDL_CreateTextureFromSurface(gl->sdl->renderer,
		gl->menu->surface);
	SDL_FreeSurface(gl->menu->surface);
	init_img3(gl, i);
}

void		init_img(t_arr *gl)
{
	IMG_Init(IMG_INIT_PNG);
	gl->menu->surface = IMG_Load("img/team.png");
	gl->menu->texture_img[0] = SDL_CreateTextureFromSurface(gl->sdl->renderer,
		gl->menu->surface);
	SDL_FreeSurface(gl->menu->surface);
	gl->menu->surface = IMG_Load("img/sphera.png");
	gl->menu->texture_img[1] = SDL_CreateTextureFromSurface(gl->sdl->renderer,
		gl->menu->surface);
	SDL_FreeSurface(gl->menu->surface);
	gl->menu->surface = IMG_Load("img/cylinder.png");
	gl->menu->texture_img[2] = SDL_CreateTextureFromSurface(gl->sdl->renderer,
		gl->menu->surface);
	SDL_FreeSurface(gl->menu->surface);
	gl->menu->surface = IMG_Load("img/conus.png");
	gl->menu->texture_img[3] = SDL_CreateTextureFromSurface(gl->sdl->renderer,
		gl->menu->surface);
	SDL_FreeSurface(gl->menu->surface);
	gl->menu->surface = IMG_Load("img/torus.png");
	gl->menu->texture_img[4] = SDL_CreateTextureFromSurface(gl->sdl->renderer,
		gl->menu->surface);
	SDL_FreeSurface(gl->menu->surface);
	init_img2(gl, -1);
}

void		init_sdl(t_arr *gl)
{
	gl->sdl = (t_sdl *)malloc(sizeof(t_sdl));
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_error(6);
	gl->sdl->win = SDL_CreateWindow("aRT Warriors",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		W, H,
		SDL_WINDOW_OPENGL);
	gl->sdl->renderer = SDL_CreateRenderer(gl->sdl->win, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	gl->menu = (t_menu*)malloc(sizeof(t_menu));
	init_flags_menu(gl);
}

void		init_all(t_arr *gl)
{
	to_arr(gl);
	mmul(gl);
	init_sdl(gl);
	init_img(gl);
	init_font(gl);
	init_menu(gl);
}
