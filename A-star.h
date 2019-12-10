#ifndef A_STAR_H
#define A_STAR_H

#include "graphics.h"
#include "utils.h"
#include <limits.h>
#include <vector>
using std::vector;

Result A_star(Map *map, int *hsld, int start, int end);
#endif
