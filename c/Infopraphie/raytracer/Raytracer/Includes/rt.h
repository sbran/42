#ifndef	        __RT_H__
#define		__RT_H__

#include	"struc.h"
#include	"errors.h"
#include	"init.h"
#include	"parser.h"
#include	"main.h"
#include	"my.h"
#include	"inter.h"
#include	"perlin.h"
#include	"trans_rot.h"
#include	"luminosite.h"
#include	"others.h"

#define	WIN_X			1000
#define	WIN_Y			1000
#define IND_MILIEU		1.0027

#define	PLAN			1
#define	SPHERE			2
#define	CYLINDRE		3
#define	CONE			4
#define	PARABOLOIDE		5
#define	HYPERBOLOIDE	6

#define HYPER_OPEN		-5000

#define BW_FILTER		0
#define SEPIA_FILTER	0

#define	SQ(x)			((x) * (x))
#define	ABS(nb)			((nb < 0) ? (-nb) : (nb))

#endif
