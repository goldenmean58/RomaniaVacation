#include "A-star.hpp"
#include "dfs_bfs.hpp"
#include "graphics.hpp"
#include "greedy.hpp"
#include "utils.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(void) {
  // test map
  cout << "Map" << endl;
  Map m;
  char file_name[] = "RomaniaMap.txt";
  m.read_map(file_name);

  // test dfs
  cout << "Dfs" << endl;
  Result ret = dfs(&m, 0, 1);
  for (auto track : ret.tracks) {
    cout << m.index2name(track) << " ";
  }
  cout << endl;
  cout << "Run time: " << ret.run_milsec << " ms" << endl;
  cout << "Generated vertex number: " << ret.visit_count << endl;
  cout << "Distance: " << ret.distance << endl;

  // test bfs
  cout << "Bfs" << endl;
  ret = bfs(&m, 0, 1);
  for (auto track : ret.tracks) {
    cout << m.index2name(track) << " ";
  }
  cout << endl;
  cout << "Run time: " << ret.run_milsec << " ms" << endl;
  cout << "Generated vertex number: " << ret.visit_count << endl;
  cout << "Distance: " << ret.distance << endl;

  // test greedy
  cout << "Greedy" << endl;
  int tmp[255] = {0};
  size_t size = 0;
  char hsld_file_name[] = "RomaniaHSLD.txt";
  read_hsld(hsld_file_name, tmp, &size);
  ret = greedy(&m, tmp, 0, 1);
  for (auto track : ret.tracks) {
    cout << m.index2name(track) << " ";
  }
  cout << endl;
  cout << "Run time: " << ret.run_milsec << " ms" << endl;
  cout << "Generated vertex number: " << ret.visit_count << endl;
  cout << "Distance: " << ret.distance << endl;

  // A-star
  cout << "A-star" << endl;
  ret = A_star(&m, tmp, 0, 1);
  for (auto track : ret.tracks) {
    cout << m.index2name(track) << " ";
  }
  cout << endl;
  cout << "Run time: " << ret.run_milsec << " ms" << endl;
  cout << "Generated vertex number: " << ret.visit_count << endl;
  cout << "Distance: " << ret.distance << endl;
  return 0;
}
