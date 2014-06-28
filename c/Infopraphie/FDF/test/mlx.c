
#include "fdf.h"

void            ft_nbr_line_col(char *str, t_env *env)
{
    int    i;
    int    j;
    char    **tmp;

    j = -1;
    env->nbr_line = 0;
    env->nbr_col = 0;
    env->fd = open(str, O_RDONLY);
    env->tab = malloc(sizeof(*tmp) * 1000);
    while (ft_get_next_line(env->fd, &env->line))
    {
        i = 0;
        tmp = ft_strsplit(env->line, ' ');
        ft_putstr(env->line);
        ft_putchar('\n');
        while (tmp[i])
            i++;
        env->nbr_line++;
        i = -1;
        while (tmp[++i])
        {
            env->tab[++j] = ft_atoi(tmp[i]);
        }
    }
    env->nbr_col = i;
}

int main(int argc, char **argv)
{
    t_env   env;
    //int      fd;
	int     count = 0;
    int  width1;
    int  height1;
    int  width2;
    int  height2;
    int  width3;
    int  height3;
    char    *data;
    int  bpp;
    int  sizeline;
    int  endian;
    
    int i;
    int j;
    int k;

    i = -1;
    j = 0;
    k = env.nbr_col;

    ft_nbr_line_col(argv[1], &env);
    printf("line = %d col = %d\n", env.nbr_line, env.nbr_col);
    while (++i <= env.nbr_line)
    {
        printf(" ");
        while (j < k)
        {
            if (env.tab[j] == 0)
                printf("  %d", env.tab[j]);
            else
                printf(" %d", env.tab[j]);
            j++;
        }
        k = k + env.nbr_col;
        printf("\n");
    }
    if(!(env.ptr = mlx_init()))
        return (0);
    env.win = mlx_new_window(env.ptr, WIDTH, HEIGHT, "FDF");

        //////////////
          //  env.img = mlx_new_image(env.ptr, WIDTH, HEIGHT);
          //  data = mlx_get_data_addr(env.img, &bpp, &sizeline, &endian);
            
            
        /////////////
        while (count < env.nbr_col * env.nbr_line)
        {
            width1 =  (env.tab[count] * -1)  + (PADDING * (count % env.nbr_col)) + 30;
            height1 = (env.tab[count] * -1)  + (PADDING * (count / env.nbr_col)) + 30;
            
            width1 = ( CTE1 * width1 - CTE2 * height1) + (WIDTH / 2);
            height1 = (1 + (CTE1 / -4) * width1 + (CTE2/20) * height1)+ (HEIGHT / 4);

            count++;

            width2 =  (env.tab[count] * -1)  + (PADDING * (count % env.nbr_col)) + 30;
            height2 = (env.tab[count] * -1)  + (PADDING * (count / env.nbr_col)) + 30;
            
            width2 = ( CTE1 * width2 - CTE2 * height2)+ (WIDTH /2);
            height2 = (1 + (CTE1 / -4) * width2 + (CTE2/20) * height2)+ (HEIGHT / 4);

            width3 = (env.tab[count + (env.nbr_col - 1)] * -1) + (PADDING * ((count + (env.nbr_col - 1)) % env.nbr_col)) + 30;
            height3 = (env.tab[count + (env.nbr_col - 1)] * -1)  + (PADDING * ((count + (env.nbr_col - 1)) / env.nbr_col)) + 30;
            
            width3 = ( CTE1 * width3 - CTE2 * height3)+ (WIDTH /2) ;
            height3 = (1 + (CTE1 / -4) * width3 + (CTE2/20) * height3)+ (HEIGHT / 4);

            //printf("cn = %d, w1 = %d, h1 = %d, w2 = %d, h2 = %d, w3 = %d, h3 = %d\n", count, width1, height1, width2, height2, width3, height3);
            ft_draw_line(width1, height1, width2, height2, env);
            if (count < 191)
                ft_draw_line2(width1, height1, width3, height3, env);
            mlx_pixel_put(env.ptr, env.win, width1, height1, 0xFFFFFF);
            //data[width1 * (sizeline + (bpp / 8)) * height1] = mlx_get_color_value(mlx.ptr,0xFF);
        }
        //mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
        
        
        mlx_loop(env.ptr);
    return (0);
}

void    ft_draw_line(int w1, int h1, int w2, int h2, t_env env)
{
    int x;

    x = w1;

    while (x <= w2)
    {
        mlx_pixel_put(env.ptr, env.win,  x, h1 + ((h2 - h1) * (x - w1)) / (w2 - w1), 0x66CC66);
        x++;
    }
}

void    ft_draw_line2(int w1, int h1, int w2, int h2, t_env env)
{
    int y;

    y = h1;

    //printf("BBB y = %d, h1 = %d, h2 = %d, h2-h1 = %d, w1 = %d, w2 = %d, w2-w1 %d\n", y, h1, h2, h2 - h1, w1, w2, w2 - w1);
    while (y <= h2)
    {
        mlx_pixel_put(env.ptr, env.win, w1 + ((w2 - w1) * (y - h1)) / (h2 - h1), y, 0x66CC66);
        y++;
    }
}
