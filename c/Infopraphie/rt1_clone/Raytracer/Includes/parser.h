/*
** parser.h for raytracer in /home/bagot_b//new_parser
** 
** Made by benjamin bagot
** Login   <bagot_b@epitech.net>
** 
** Started on  Tue May  8 14:09:43 2012 benjamin bagot
** Last update Sun Jun  3 18:10:45 2012 benjamin bagot
*/

#ifndef __PARSER_H__
#define __PARSER_H__

int		get_scene(t_param *, char *);
char		*get_next_line(const int);
t_param		*get_all_obj(t_param *, char **);
int		check_limit_while(char **tab, int *i);
void		get_general(t_param *param, char **tab, int *i);
t_objet		*get_one_obj(t_objet *, char **, int *);
t_spot		*get_one_spot(t_spot *, char **, int *);
t_objet		*get_elem_obj(t_objet *, char **, int *, int);
t_spot		*extract_elem_spot(t_spot *, char **, int *);
t_objet		*get_elem(t_objet *, char **, int *);
void		assign_value(t_objet **, char *);
void		assign_value_spot(t_spot **, char *);
void		get_eye(t_param *param, char **tab, int *i);
char		*extract_str(char *);
void		put_obj_in_list(t_objet **, t_objet);
void		put_spot_in_list(t_spot **, t_spot);

#endif
