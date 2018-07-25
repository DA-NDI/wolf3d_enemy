/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 20:17:52 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/20 09:13:51 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <SDL.h>
# include <SDL_image.h>
# include <libft.h>
# include <fcntl.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# define DOWN SDLK_DOWN
# define UP SDLK_UP
# define LEFT SDLK_LEFT
# define RIGHT SDLK_RIGHT
# define SPACE SDLK_SPACE
# define P SDLK_p
# define MAP holder->map
# define P_X holder->player_x
# define P_Y holder->player_y
# define DIR_X camera->dir_x
# define DIR_Y camera->dir_y
# define PLANE_X_COORD camera->plane_x
# define WHITE (SDL_Color){255, 255, 255, 255}
# define LINE_H (camera->line_height)
# define WIDTH holder->width
# define HEIGHT holder->height
# define POINT ((camera->draw_start << 8) - (HEIGHT << 7) + (LINE_H << 7))
# define START_SCR holder->start->start_screen
# define DELTA_DIST_X camera->delta_dist_x
# define DELTA_DIST_Y camera->delta_dist_y
# define WALL_X_FL holder->camera->wall_x_f
# define WALL_Y_FL holder->camera->wall_y_f
# define PERP_DIST_WALL holder->camera->perp_wall_dist
# define FLOOR_TEX_X (int)(current_floor_x * 64) % 64
# define FLOOR_TEX_Y (int)(current_floor_y * 64) % 64
# define CHECK_SIDE_0 (camera->side == 0 && camera->ray_dir_x > 0)
# define CHECK_SIDE_1 (camera->side == 1 && camera->ray_dir_y < 0)
# define CHECK_SIDE_2 (camera->side == 0 && camera->ray_dir_x < 0)
# define CHECK_SIDE_3 (camera->side == 1 && camera->ray_dir_y > 0)
# define MAP_CELL MAP[camera->map_y][camera->map_x]
# define FPS 1000/holder->frame_time
# define TEX_NUM holder->skybox_num
# define RENDER holder->renderer
# define G holder->gun
# define H holder->gun_1
# define PIC holder->weapon[G]->pic
# define FIXED_POINT_ONE (1 << 8)
# define INT_F(x) ((x) << 8)
# define FLOAT_F(x) ((int)roundf(x * 256))
# define FIXED_I(x) ((x) >> 8)
# define FIXED_F(x) (((float)(x)) / 256)
# define FIX_MULT(x, y) ((x)*(y) >> 8)
# define FIX_DIV(x, y) (((x)<< 8) / (y))
# define IS_SPRITE holder->sprite->is_sprite
# define SHOOTS (*(holder->shoots))
# define ARCADE_TEX holder->sprite->tex_sprite[0]
# define IS_ARC holder->sprite->sprite_found

# define ROUND(x) (roundf(x * 10) / 10)
# define V_LEN(x, y) sqrt(x * x + y * y)
# define V_X_NORM(x, y) (x / V_LEN(x, y))
# define V_Y_NORM(x, y) (y / V_LEN(x, y))

typedef int			t_intfix;
typedef struct		s_camera
{
	SDL_Surface		*texture[11];
	SDL_Texture		*skybox_tex[5];
	float			ray_dir_x;
	float			ray_dir_y;
	float			wall_x_f;
	float			wall_y_f;
	int				step_x;
	int				step_y;
	int				is_hit;
	int				side;
	int				map_x;
	int				map_y;
	float			side_dist_x;
	float			side_dist_y;
	float			perp_wall_dist;
	float			delta_dist_x;
	float			delta_dist_y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			camera_x;
	float			camera_y;
	float			plane_y;
	float			time;
	float			old_time;
	float			move_speed;
	float			rot_speed;
	float			wall_x;
	int				draw_end;
	int				draw_start;
	TTF_Font		*font;
	int				line_height;
	Mix_Chunk		*dstelept;
}					t_camera;

typedef struct		s_sprite
{
	SDL_Surface		*tex_sprite[3];
	SDL_Surface		*arr_sprite[2][12];
	SDL_Surface		*arr_sprite_g[9];
	float			x;
	float			y;
	float			zbuffer[1024];
	int				is_alive;
	int				is_sprite;
	int				texture;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	float			transform_y;
	int				sprite_width;
	float			orig_x;
	float			orig_y;
	float			speed;
	int				sprite_found;
}					t_sprite;

typedef struct		s_weapon
{
	SDL_Texture		*texture_sshotgun[29];
	int				num_frames;
	int				frame;
	int				frame_w;
	int				frame_h;
	int				tex_w;
	int				tex_h;
	SDL_Rect		rect;
	int				pic;
	Mix_Chunk		*pistol_shoot;
}					t_weapon;

typedef struct		s_start
{
	SDL_Texture		*start_screen;
	int				play_select;
}					t_start;

typedef struct		s_wolf
{
	float			player_x;
	float			player_y;
	int				height;
	int				width;
	int				skybox_num;
	unsigned int	map_height;
	unsigned int	map_width;
	int				running: 1;
	int				shooting: 1;
	char			**map;
	SDL_Window		*window;
	SDL_Surface		*image;
	SDL_Texture		*screen;
	SDL_Texture		*texture_ak;
	SDL_Renderer	*renderer;
	t_camera		*camera;
	t_weapon		*weapon[4];
	t_start			*start;
	t_sprite		*sprite;
	unsigned int	fps;
	unsigned int	frame_delay;
	unsigned int	frame_start;
	unsigned int	frame_time;
	Mix_Music		*music;
	int				pause:1;
	int				starting:1;
	int				gun;
	int				gun_1;
	int				*shoots;
	int				frags;
}					t_wolf;

void				ft_print_error(char *str);
void				ft_init_image(t_wolf *holder);
void				ft_close_loop(t_wolf *holder, t_camera *camera);
SDL_Surface			*ft_load_bmp(t_wolf *holder, char *path);
SDL_Surface			*ft_load_png(t_wolf *holder, char *path);
void				ft_close(t_wolf *holder);
char				**ft_create_map(char **argv);
void				ft_verify_map(char **map, t_wolf *holder);
void				get_player_coordinates(t_wolf *holder);
void				ft_raycasting(t_wolf *holder, int x);
void				ft_draw_line(int x, int y_start, int y_end, \
								int color, t_wolf *holder);
void				init_weapon(t_weapon *weapon, t_wolf *holder);
void				draw_weapon(t_weapon *weapon[], t_wolf *holder);
void				apply_texture(int x, int y, SDL_Texture *tex, \
								SDL_Renderer *rend);
void				draw_skybox(t_wolf *holder, t_camera *camera);
void				ft_camera_init(t_camera *camera, t_wolf *holder);
SDL_Surface			*load_image(char *path);
SDL_Texture			*load_tex(SDL_Renderer	*renderer, char *path);
void				apply_texture(int x, int y, SDL_Texture *tex, \
								SDL_Renderer *rend);
SDL_Surface			*load_image(char *path);
Mix_Music			*load_music(char *path);
void				draw_fps(t_wolf *holder, TTF_Font *font);
void				draw_text(t_wolf *holder, char *text, int x, int y);
void				ft_start_screen(t_wolf *holder);
Mix_Chunk			*load_chunk(char *path);
void				ft_check_extra_keys(t_wolf *holder, \
					const Uint8 *keystate);
void				draw_floor(t_wolf *holder, t_camera *camera, \
		unsigned int buffer[][holder->width], unsigned int x);
unsigned int		get_pixel(SDL_Surface *surface, int x, int y);
void				ft_draw_sprites(t_wolf *holder, t_camera *camera, \
	unsigned int buffer[][holder->width]);
int					get_sprite_coordinates(t_wolf *holder, char c);
void				ft_move_boss(t_wolf *holder, t_sprite *sprite);
void				ft_check_space(t_wolf *holder, const Uint8 *keystate);
void				start_game(t_wolf *holder);
void				init_weapon_grenade(t_weapon *weapon, t_wolf *holder);
void				restart_enemy(t_wolf *holder);
void				init_weapon_demon(t_weapon *weapon, t_wolf *holder);
void				init_weapon_shotgun(t_weapon *weapon, t_wolf *holder);
void				draw_score(t_wolf *holder);

#endif
