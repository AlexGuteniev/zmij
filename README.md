# Żmij

A double-to-string conversion algorithm based on Schubfach

Improvements:
* Faster logarithm approximations
* Fewer branches
* Faster division and modulo
* More efficient significand and exponent output
* Improved estimate selection

## Usage

```c++
#include "zmij.h"
#include <stdio.h>

int main() {
  char buf[zmij::buffer_size];
  zmij::dtoa(6.62607015e-34, buf);
  puts(buf);
}
```

## Performance

More than 2.5x faster than Ryu and 80% faster than [Schubfach](https://github.com/vitaut/schubfach)
on dtoa-benchmark.

| Function       | Time (ns) | Speedup  |
|----------------|----------:|---------:|
| ostringstream  | 879.662   | 1.00x    |
| sprintf        | 737.575   | 1.19x    |
| doubleconv     | 86.517    | 10.17x   |
| to_chars       | 42.691    | 20.61x   |
| ryu            | 38.072    | 23.11x   |
| schubfach      | 24.847    | 35.40x   |
| fmt            | 22.802    | 38.58x   |
| dragonbox      | 20.986    | 41.92x   |
| zmij           | 12.742    | 69.04x   |
| null           | 0.932     | 943.49x  |

<img width="788" height="347" alt="image" src="https://github.com/user-attachments/assets/0e3de579-09b7-448e-b1de-b247a31c83c4" />

<img width="882" height="666" alt="image" src="https://github.com/user-attachments/assets/7119c447-6cb2-4b04-9e75-33c19dbf75fb" />



