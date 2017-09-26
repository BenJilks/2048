#ifndef COLOUR_H
#define COLOUR_H

#include "Vector.h"

/* Runtime colours */
static Vec3f White       = {1,1,1};
static Vec3f Black       = {0,0,0};
static Vec3f DarkGrey    = {0.73, 0.68, 0.63};
static Vec3f Grey        = {0.8, 0.75, 0.7};
static Vec3f LightGrey   = {0.93, 0.89, 0.85};
static Vec3f Four        = {0.93, 0.88, 0.78};
static Vec3f LightOrange = {0.95, 0.69, 0.47};
static Vec3f Orange      = {0.96, 0.49, 0.37};
static Vec3f DarkOrange  = {0.96, 0.37, 0.23};
static Vec3f FirstNumber = {0.44, 0.40, 0.37};

/* Compile time colours */
#define WHILE        {1,1,1}
#define BLACK        {0,0,0}
#define DARK_GRAY    {0.73, 0.68, 0.63}
#define GREY         {0.8, 0.75, 0.7}
#define LIGHT_GRAY   {0.93, 0.89, 0.85}
#define FOUR         {0.93, 0.88, 0.78}
#define LIGHT_ORANGE {0.95, 0.69, 0.47}
#define ORANGE       {0.96, 0.49, 0.37}
#define DARK_ORANGE  {0.96, 0.37, 0.23}

#endif // COLOUR_H

