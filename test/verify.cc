// A verifier for https://github.com/vitaut/zmij/.
// Copyright (c) 2025 - present, Victor Zverovich
// Distributed under the MIT license (see LICENSE).

#include "zmij.h"

#include <math.h>    // isnan
#include <stdio.h>   // sscanf
#include <stdint.h>  // uint32_t
#include <string.h>  // memcpy

int main() {
  char buf[25] = {};
  unsigned long long i = 0, n = ~uint32_t();
  double percent = 100.0 / n;
  for (; i <= n; ++i) {
    if (i % 10'000'000 == 0) printf("Progress: %.2f%%\n", i * percent);
    uint32_t bits = i;
    float expected = 0;
    memcpy(&expected, &bits, sizeof(float));
    zmij::to_string(expected, buf);
    float actual = 0;
    sscanf(buf, "%g", &actual);
    if (actual == expected) continue;
    if (isnan(actual) && isnan(expected)) continue;
    printf("Roundtrip failure: %.9g != %.9g\n", actual, expected);
    return 1;
  }
  printf("Tested %lld values\n", i);
}
