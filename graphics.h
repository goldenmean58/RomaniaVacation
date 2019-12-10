#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <assert.h>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::vector;

class Map {
private:
  vector<string> place_name;
  int **matrix;
  int city_count;

public:
  int name2index(string &);
  string index2name(int);
  int get_cost(int, int);
  vector<int> get_neighbors(int);
  void read_map(char *);
  int get_city_count();
  Map();
  ~Map();
};

#endif
