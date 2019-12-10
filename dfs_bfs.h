#ifndef DFS_BFS_H
#define DFS_BFS_H
#include "graphics.h"
#include "utils.h"
#include <algorithm>
#include <deque>
#include <set>
using std::deque;
using std::find;
using std::set;

extern Result dfs(Map *map, int start, int end);
extern Result bfs(Map *map, int start, int end);
#endif
