#include <stdint.h>

using uint128_t = unsigned __int128;

constexpr uint64_t not_found = ~uint64_t();

// Finds the smallest n >= 0 such that (n * step) % mod is in [lower, upper].
// This is a standard algorithm for linear congruential inequalities.
inline auto find_min_n(uint64_t step, uint128_t mod, uint64_t lower,
                       uint64_t upper) -> uint64_t {
  if (lower > upper) return not_found;

  if (lower == 0) return 0;  // Current position is already a hit.

  uint128_t step128 = step % mod;
  if (step128 == 0) return not_found;

  // Check for direct hit without wrapping.
  uint128_t n = (lower + step128 - 1) / step128;
  if (n * step128 <= upper) return uint64_t(n);

  // Euclidean recursion.
  uint64_t res =
      find_min_n(mod % step128, step128, (step128 - upper % step128) % step128,
                 (step128 - lower % step128) % step128);
  if (res == not_found) return not_found;

  // Numerator can exceed 128 bits if not careful, but for m=2^64,
  // uint128_t handles the intermediate (res * m + L + step128 - 1) before
  // the / step128.
  return uint64_t((uint128_t(res) * mod + lower + step128 - 1) / step128);
}
