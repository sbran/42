#ifndef		__MAIN_H__
#define		__MAIN_H__

void		rempli_img(t_param *);
void		aff_percent(int, t_param *);
t_k		calc(double, double, t_param *, t_k *);
int		expose(t_param *);
int		key(int, t_param **);
void		mlx_ppti(int, int, t_param *, t_k *);
void		free_list(t_param *);

#endif

