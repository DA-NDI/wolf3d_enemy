/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:19:48 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/20 11:17:07 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		ft_check_skybox(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_W])
		holder->skybox_num = 0;
	if (keystate[SDL_SCANCODE_E])
		holder->skybox_num = 2;
	if (keystate[SDL_SCANCODE_R])
		holder->skybox_num = 3;
}

void		ft_check_weapons(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_1])
	{
		holder->gun = 0;
		holder->gun_1 = 0;
	}
	if (keystate[SDL_SCANCODE_2])
	{
		holder->gun = 1;
		holder->gun_1 = 1;
	}
	if (keystate[SDL_SCANCODE_3])
	{
		holder->gun = 2;
		holder->gun_1 = 0;
	}
	if (keystate[SDL_SCANCODE_4])
	{
		holder->gun = 3;
		holder->gun_1 = 0;
	}
}

void		ft_check_extra_keys(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_Q])
	{
		if (Mix_PausedMusic() == 0)
			Mix_PauseMusic();
		else
			Mix_ResumeMusic();
	}
	if (keystate[SDL_SCANCODE_RETURN] && holder->starting)
	{
		if (holder->start->play_select)
		{
			Mix_PlayMusic(holder->music, -1);
			holder->starting = 0;
		}
		else
			ft_close(holder);
	}
	ft_check_weapons(holder, keystate);
	ft_check_skybox(holder, keystate);
}

void		ft_check_space(t_wolf *holder, const Uint8 *keystate)
{
	float		v_x;
	float		v_y;

	if (keystate[SDL_SCANCODE_SPACE] && !holder->starting && !holder->shooting)
	{
		holder->shooting = 1;
		Mix_PlayChannel(-1, holder->weapon[G]->pistol_shoot, 0);
		holder->weapon[G]->frame = 0;
		v_x = holder->sprite->x - holder->player_x;
		v_y = holder->sprite->y - holder->player_y;
		holder->sprite->is_alive = (SHOOTS >= 4 || !IS_SPRITE) ? 0 : 1;
		IS_SPRITE = (SHOOTS == 5 || !IS_ARC) ? 0 : 1;
		if (SHOOTS >= 5)
			restart_enemy(holder);
		if (abs((int)(fabsf(v_x / holder->DIR_X)) - \
	(int)(fabsf(v_y / holder->DIR_Y))) <= 3 && SHOOTS < 6 && IS_ARC)
		{
			if (SHOOTS < 5)
			{
				ARCADE_TEX = holder->sprite->arr_sprite[H][SHOOTS];
			}
			SHOOTS += (G == 0) ? 1 : 2;
			SHOOTS += (G == 1) ? 2 : 0;
		}
	}
}
