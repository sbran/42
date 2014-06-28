#ifndef		__INTER_H__
#define		__INTER_H__

double		inter_plan(t_utils, t_objet *);
double		inter_cylindre(t_utils, t_objet *);
double		inter_cone(t_utils, t_objet *);
double		inter_sphere(t_utils, t_objet *);
double		inter_paraboloide(t_utils, t_objet *);
double		inter_hyperboloide(t_utils, t_objet *);
double		search_res(double, double, double);
double		delta(double, double, double);

#endif
