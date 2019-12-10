#include "greedy.h"
int read_hsld(char *file_name, int *f, size_t *size) {
  assert(file_name);
  assert(f);
  assert(size);
  fstream in;
  in.open(file_name);
  assert(in.is_open());
  string city_name;
  int value;
  *size = 0;
  while (in >> city_name) {
    in >> value;
    *f = value;
    f++;
    *size = *size + 1;
  }
  in.close();
  return 0;
}

Result greedy(Map *map, int *hsld, int start, int end) {
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
    for (auto neighbor : neighbors) {
      if (hsld[neighbor] < min_value) {
        start = neighbor;
        min_value = hsld[neighbor];
      }
    }
  }
  return result;
}
