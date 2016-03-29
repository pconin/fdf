#include "fdf.h"

void	draw_init_window(s_env *stock)
{
	ft_free_tab(stock->tmp, stock);
	ft_tab_iso(stock);
}

int		key_h(int keycode, s_env *stock)
{
	stock->img_ptr = mlx_new_image(stock->mlx, SCR_WIDTH, SCR_HEIGHT);
	stock->img = mlx_get_data_addr(stock->img_ptr, &(stock->bpp), &(stock->line), &(stock->endi));
	if (keycode == ENTER)
		draw_init_window(stock);
	if (keycode == ESC)
		exit(0);
	if (keycode == LEFT)
		ft_move_x(stock, -1);
	if (keycode == RIGHT)
		ft_move_x(stock, 1);
	if (keycode == UP)
		ft_move_y(stock, -1);
	if (keycode == DOWN)
		ft_move_y(stock, 1);
	draw_tab(stock);
	mlx_put_image_to_window(stock->mlx, stock->win, stock->img_ptr, 0, 0);
	ft_putstr_win(stock);
	ft_putstr("\n keycode :");
	ft_putnbr(keycode);
	return (0);
}

void	ft_setwin(s_env *stock)
{
	stock->bpp = 0;
	stock->line = 0;
	stock->endi = 0;
	stock->zoom = 1;
	ft_init_tab(stock);
	stock->mlx = mlx_init();
	stock->win = mlx_new_window(stock->mlx, SCR_WIDTH, SCR_HEIGHT, "Fil de Fer 42");
	stock->img_ptr = mlx_new_image(stock->mlx, SCR_WIDTH, SCR_HEIGHT);
	stock->img = mlx_get_data_addr(stock->img_ptr, &(stock->bpp), &(stock->line), &(stock->endi));
	mlx_string_put (stock->mlx, stock->win, 300, 300, 0xffffff, "Press ENTER to init" );
	mlx_key_hook(stock->win, &key_h, stock);
	mlx_loop(stock->mlx);
}
