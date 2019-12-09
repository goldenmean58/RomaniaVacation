#ifndef UTILS_H
#define UTILS_H

#include <functional>
#include <time.h>
#include <vector>
using std::function;

struct Result {
  std::vector<int> tracks;
  // search_procedure
  int visit_count;
  double run_milsec;
  int distance;
};

template <typename FUN_RESULT, typename... ARGS>
function<FUN_RESULT(ARGS... args)> decorator(FUN_RESULT (*f)(ARGS... args),
                                             double *run_milsec) {
  auto post = [&](ARGS... args) -> FUN_RESULT {
    clock_t t1 = clock();
    FUN_RESULT ret = f(args...);
    clock_t t2 = clock();
    *run_milsec = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1000;
    return ret;
  };
  return post;
}

#endif
