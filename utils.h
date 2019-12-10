#ifndef UTILS_H
#define UTILS_H

#include <functional>
#include <time.h>
#include <vector>
using std::function;
#define CLOCKS_PER_SEC 1
struct Result {
  std::vector<int> tracks;
  // search_procedure
  int visit_count;
  double run_milsec;
  int distance;
};

template <typename FUN_RESULT, typename... ARGS>
function<FUN_RESULT(ARGS... args)> decorator(FUN_RESULT (*f)(ARGS... args),
                                             double *run_milsec);

#endif
