
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ROUND(x) (roundf(x * 10) / 10)
#define V_LEN(x, y) sqrt(x * x + y * y)
#define V_X_NORM(x, y) (x / V_LEN(x, y))
#define V_Y_NORM(x, y) (y / V_LEN(x, y))
#define CYCLES 1000000000

typedef struct	s_sprite
{
	float		x;
	float		y;
	int			texture;
	float		zbuffer[1024];
}				t_sprite;

int		main(int argc, char **argv); //remove!!! its for norminette.
{
	t_sprite	*sprite;
	float		p_x;
	float		p_y;
	float		v_x;
	float		v_y;
	float		v_x_norm;
	float		v_y_norm;
	int			v_len;

	sprite = (t_sprite*)malloc(sizeof(t_sprite));
	p_x = 1.532312;
	p_y = 9.4234234;
	sprite->x = 5.512432;
	sprite->y = 4.232454;
	for (int i = 0; i < CYCLES; i++)
	{
		v_x = sprite->x - p_x;
		v_y = sprite->y - p_y;
//		v_len = V_LEN(v_x, v_y);
//		v_x_norm = ROUND(v_x / v_len);
//		v_y_norm = ROUND(v_y / v_len);
//		if (v_x_norm == ROUND(p_x) && (v_y_norm == ROUND(p_y)))
		if ((int)(fabsf(v_x / p_x)) == (int)(fabsf(v_y / p_y)))
		{
			printf("end\n");
			break ;
		}
	}
}
