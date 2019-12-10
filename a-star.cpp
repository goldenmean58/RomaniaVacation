#include "A-star.h"
Result A_star(Map *map, int *hsld, int start, int end) {
  assert(map);
  assert(hsld);
  vector<int> track;
  int visit_count = 0;
  Result result;
  clock_t t1 = clock();
  while (1) {
    track.push_back(start);
    if (start == end) {
      clock_t t2 = clock();
      double run_time = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1000;
      result.tracks = track;
      result.visit_count = visit_count;
      result.run_milsec = run_time;
      result.distance = 0;
      for (size_t i = 0; i < track.size() - 1; ++i) {
        result.distance += map->get_cost(track[i], track[i + 1]);
      }
      break;
    }
    auto neighbors = map->get_neighbors(start);
    visit_count += neighbors.size();
    int min_value = INT_MAX;
    int next_place = start;
    for (auto neighbor : neighbors) {
      if (hsld[neighbor] + map->get_cost(start, neighbor) < min_value) {
        next_place = neighbor;
        min_value = hsld[neighbor] + map->get_cost(start, neighbor);
      }
    }
    start = next_place;
  }
  return result;
}
