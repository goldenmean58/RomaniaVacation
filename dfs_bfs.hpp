#ifndef DFS_BFS_H
#define DFS_BFS_H
#include "graphics.hpp"
#include "utils.hpp"
#include <algorithm>
#include <deque>
#include <set>
using std::deque;
using std::find;
using std::set;

Result dfs(Map *map, int start, int end) {
  assert(map);
  assert(start >= 0 && start < map->get_city_count());
  assert(end >= 0 && end < map->get_city_count());
  vector<int> track;
  deque<int> visit_stack;
  set<int> visited;
  int visit_count = 0;
  int city_count = map->get_city_count();
  int pre[city_count];
  for (int i = 0; i < city_count; ++i) {
    pre[i] = 0;
  }
  Result result;
  clock_t t1 = clock();
  visit_stack.push_front(start);
  if (start != end) {
    while (!visit_stack.empty()) {
      int top = visit_stack.front();
      visited.insert(top);
      visit_count++;
      visit_stack.pop_front();
      if (top == end) {
        clock_t t2 = clock();
        double run_time = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1000;
        result.visit_count = visit_count;
        track.push_back(end);
        int i = pre[top];
        while (i != start) {
          track.push_back(i);
          i = pre[i];
        }
        track.push_back(start);
        std::reverse(track.begin(), track.end());
        result.tracks = track;
        result.run_milsec = run_time;
        result.distance = 0;
        for (size_t i = 0; i < track.size() - 1; ++i) {
          result.distance += map->get_cost(track[i], track[i + 1]);
        }
        return result;
      }
      vector<int> neighbors = map->get_neighbors(top);
      for (auto neighbor : neighbors) {
        if (visited.find(neighbor) == visited.end() &&
            find(visit_stack.begin(), visit_stack.end(), neighbor) ==
                visit_stack.end()) {
          pre[neighbor] = top;
          visit_stack.push_front(neighbor);
        }
      }
    }
  }
  return result;
}

Result bfs(Map *map, int start, int end) {
  assert(map);
  assert(start >= 0 && start < map->get_city_count());
  assert(end >= 0 && end < map->get_city_count());
  vector<int> track;
  deque<int> visit_queue;
  set<int> visited;
  int visit_count = 0;
  int city_count = map->get_city_count();
  int pre[city_count];
  for (int i = 0; i < city_count; ++i) {
    pre[i] = 0;
  }
  Result result;
  clock_t t1 = clock();
  visit_queue.push_front(start);
  if (start != end) {
    while (!visit_queue.empty()) {
      int top = visit_queue.front();
      visited.insert(top);
      visit_count++;
      visit_queue.pop_front();
      if (top == end) {
        clock_t t2 = clock();
        double run_time = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1000;
        result.visit_count = visit_count;
        track.push_back(end);
        int i = pre[top];
        while (i != start) {
          track.push_back(i);
          i = pre[i];
        }
        track.push_back(start);
        std::reverse(track.begin(), track.end());
        result.tracks = track;
        result.run_milsec = run_time;
        result.distance = 0;
        for (size_t i = 0; i < track.size() - 1; ++i) {
          result.distance += map->get_cost(track[i], track[i + 1]);
        }
        return result;
      }
      vector<int> neighbors = map->get_neighbors(top);
      for (auto neighbor : neighbors) {
        if (visited.find(neighbor) == visited.end() &&
            find(visit_queue.begin(), visit_queue.end(), neighbor) ==
                visit_queue.end()) {
          pre[neighbor] = top;
          visit_queue.push_back(neighbor);
        }
      }
    }
  }
  return result;
}
#endif
