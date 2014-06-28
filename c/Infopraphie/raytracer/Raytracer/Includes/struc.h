#ifndef	        __STRUC_H__
#define		__STRUC_H__

typedef struct	s_param t_param;
typedef struct	s_objet t_objet;
typedef struct	s_spot t_spot;
typedef struct	s_utils t_utils;
typedef struct	s_vect t_vect;
typedef struct	s_k t_k;
typedef struct	s_perlin t_perlin;

typedef struct	s_color
{
  short         red;
  short         green;
  short         blue;
  short         new_red;
  short         new_green;
  short         new_blue;
} t_color;

typedef struct	s_ppti
{
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
} t_ppti;

typedef struct	s_rot
{
  double        rot_x;
  double        rot_y;
  double        rot_z;
} t_rot;

typedef struct	s_coord
{
  double	x;
  double  y;
  double	z;
} t_coord;

struct		s_objet
{
  int       type;
  int       nb;
  t_coord   coord;
  t_rot     rot;
  t_color   color;
  double    brill;
  double     trans;
  double    reflex;
  double    middle;
  double    size;
  int       p_type;
  t_color	  pm_color;
  t_color  	ps_color;
  int       perturb;
  int       texture;
  t_objet	  *next;
};

struct		s_vect
{
  double	v_x;
  double	v_y;
  double	v_z;
  double	n_x;
  double	n_y;
  double	n_z;
  double	LR;
};

struct		s_utils
{
  t_coord	coord;
  t_rot		eye_rot;
  t_vect	vect;
  t_vect	norm;
  t_spot	*spot;
  double	amb;
  double	norme;
};

struct		s_perlin
{
  double a;
  double b;
  double c;
  double d;
};

struct		s_k
{
  int		type;
  int		nb;
  double	reflex;
  t_color	color;
  double	k;
  double	ind;
  double	transp;
  short		brill;
};

struct		s_spot
{
  t_coord	coord;
  t_color	color;
  t_spot	*next;
};

struct		s_param
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img;
  t_coord	eye_coord;
  t_rot		eye_rot;
  int     anti_alias;
  double	amb;
  t_spot	*spot;
  t_objet *objet;
  double	*valeurs2D;
};

#endif
