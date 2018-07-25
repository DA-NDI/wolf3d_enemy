/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:39:00 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/20 09:15:45 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#define ARGB SDL_PIXELFORMAT_ARGB8888

void	ft_skybox_init(t_camera *camera, t_wolf *holder)
{
	camera->skybox_tex[0] = load_tex(RENDER, "./resourses/skybox_up.png");
	camera->skybox_tex[1] = load_tex(RENDER, "./resourses/skybox_bottom.png");
	camera->skybox_tex[2] = load_tex(RENDER, "./resourses/skybox_test1.jpg");
	camera->skybox_tex[3] = load_tex(RENDER, "./resourses/skybox_test3.jpg");
}

void	ft_camera_init(t_camera *camera, t_wolf *holder)
{
	camera->dir_x = -1;
	camera->dir_y = 0;
	camera->plane_x = 0;
	camera->plane_y = 0.66;
	camera->camera_x = 0;
	camera->camera_y = 0;
	camera->ray_dir_x = 0;
	camera->ray_dir_y = 0;
	camera->map_x = 0;
	camera->map_y = 0;
	camera->is_hit = 0;
	camera->move_speed = 0.2;
	camera->rot_speed = -0.04;
	if (!(camera->font = TTF_OpenFont("./src/font.ttf", 20)))
		ft_print_error("Unable to load font");
	camera->texture[0] = load_image("./resourses/fence_wire2.png");
	camera->texture[1] = load_image("./resourses/portal.png");
	camera->texture[2] = load_image("./resourses/wall_wire_blue.png");
	camera->texture[3] = load_image("./resourses/brick_lblue1.png");
	camera->texture[4] = load_image("./resourses/floor_wire_violet.png");
	camera->texture[5] = load_image("./resourses/arcade.png");
	camera->texture[6] = load_image("./textures/fury_poster.png");
	camera->texture[7] = load_image("./resourses/brick_pink2.png");
	camera->dstelept = load_chunk("resourses/dstelept.wav");
	ft_skybox_init(camera, holder);
}

/*
**	put in the end of init_image to hide coursor
**	SDL_SetRelativeMouseMode(SDL_TRUE);
*/

void	ft_init_image(t_wolf *holder)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		ft_print_error("Failed to init SDL");
	if ((holder->window = SDL_CreateWindow("Woo!", SDL_WINDOWPOS_CENTERED, \
	SDL_WINDOWPOS_CENTERED, holder->width, holder->height, 0)) < 0)
		ft_print_error("Failed to create window. Exiting");
	SDL_GetWindowSize(holder->window, &WIDTH, &HEIGHT);
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_print_error("Unable to load png");
	if ((TTF_Init()))
		ft_print_error("Unable to init ttf");
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		ft_print_error("Unable to init audio!");
	holder->music = load_music("./resourses/soundtrack.mp3");
	if (!(holder->renderer = SDL_CreateRenderer(holder->window, -1, \
		SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_ACCELERATED)))
		ft_print_error("Unable to create renderer");
	if ((SDL_SetRenderDrawBlendMode(holder->renderer, SDL_BLENDMODE_BLEND)))
		ft_print_error("Unable to set renderer blend mode");
	if (SDL_SetRenderDrawColor(holder->renderer, 0, 0, 0, 0))
		ft_print_error("SDL_SetRenderDrawColor failed");
	if (!(holder->screen = SDL_CreateTexture(holder->renderer,
		ARGB, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)))
		ft_print_error("Screen texture not created!");
	SDL_SetTextureBlendMode(holder->screen, SDL_BLENDMODE_BLEND);
}
