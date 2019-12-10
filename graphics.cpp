#include "graphics.h"

int Map::name2index(string &place_name) {
  for (size_t i = 0; i < this->place_name.size(); ++i) {
    if (this->place_name[i] == place_name) {
      return i;
    }
  }
  return -1;
}

string Map::index2name(int index) {
  assert(index >= 0 && index < this->place_name.size());
  return this->place_name[index];
}

int Map::get_cost(int place1, int place2) {
  assert(this->matrix);
  assert(place1 >= 0 && place1 < this->place_name.size());
  assert(place2 >= 0 && place2 < this->place_name.size());
  return this->matrix[place1][place2];
}

vector<int> Map::get_neighbors(int place) {
  vector<int> ret;
  for (size_t i = 0; i < this->place_name.size(); ++i) {
    if (this->matrix[place][i] > 0) {
      ret.push_back(i);
    }
  }
  return ret;
}
void Map::read_map(char *file_name) {
  fstream in;
  in.open(file_name);
  assert(in.is_open());
  char cities[1024];
  char buff[1024];
  bool word = false;
  int start = 0;
  int len = 0;
  this->city_count = 0;
  in.getline(cities, 1024);
  int i;
  for (i = 0; i < 1024; ++i) {
    if (cities[i] == '\0')
      break;
    if (isspace(cities[i])) {
      if (word) {
        word = false;
        len = i - start;
        strncpy(buff, &cities[start], len);
        buff[len] = '\0';
        string str = buff;
        this->place_name.push_back(str);
        this->city_count++;
      }
    } else {
      if (!word) {
        word = true;
        start = i;
      }
    }
  }
  if (word) {
    len = i - start;
    strncpy(buff, &cities[start], len);
    string str = buff;
    buff[len] = '\0';
    this->place_name.push_back(str);
    this->city_count++;
  }
  this->matrix = new int *[this->city_count];
  for (i = 0; i < this->city_count; ++i) {
    this->matrix[i] = new int[this->city_count];
  }
  for (i = 0; i < this->city_count; ++i) {
    string city_name;
    in >> city_name;
    int city_index = this->name2index(city_name);
    assert(city_index != -1 && city_index < city_count);
    for (int j = 0; j < this->city_count; ++j) {
      int cost;
      in >> cost;
      cost = (cost == 1000) ? -1 : cost;
      this->matrix[city_index][j] = cost;
    }
  }
  in.close();
}

int Map::get_city_count() { return this->city_count; }

Map::Map() : matrix(nullptr), city_count(0) {}

Map::~Map() {
  for (int i = 0; i < this->city_count; ++i) {
    delete[] this->matrix[i];
  }
  delete[] this->matrix;
}

