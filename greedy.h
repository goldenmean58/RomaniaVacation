#ifndef GREEDY_H
#define GREEDY_H

#include "graphics.h"
#include "utils.h"
#include <assert.h>
#include <fstream>
#include <limits.h>
#include <vector>
using std::fstream;
using std::string;
using std::vector;

int read_hsld(char *file_name, int *f, size_t *size);
Result greedy(Map *map, int *hsld, int start, int end);

#endif
