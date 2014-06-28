#ifndef		__OTHERS_H__
#define		__OTHERS_H__

t_k		*reflexion(t_k *, t_objet *, t_utils *, t_param *);
t_k		*transp(t_k *, t_objet *, t_utils *, t_param *);
t_utils		*my_init_norm(t_objet *, t_objet, t_utils *);
double		check_limit(double *, t_utils *, int, int);
int		get_color_pos_rot(char *, char );
int		get_type(char *);
int		get_size(char *);
void		count_obj(t_param *);
t_k		*check_k(t_k *, t_k *);
t_k		*new_search_k(t_objet *, t_utils *, t_k *, t_param *);
t_k		*search_k(t_objet *tmp, t_utils utils, t_k *k, t_param *param);

#endif
