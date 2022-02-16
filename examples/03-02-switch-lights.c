// 22/02/16 = Wed

// Switch Lights

// Lights 1 to n. People 1 to k. Person 1 turns on all the lights. Then Person 2
// switches the lights whose number is a multiple of 2. Then Person 3 switches
// the lights whose number is a multiple of 3. And so on. Given n and k, find
// the lights that are on finally.

// Example:
// Input: 7 3
// Output: 1 5 6 7

// Constraints:
// k <= n <= 1000

#include <stdio.h>

#define N 1010

int lights[N];

void set(int n, int k) {
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j % i == 0) {
        lights[j - 1] = !lights[j - 1];
      }
    }
  }
}

void show(int n) {
  for (int i = 1, first = 1; i <= n; ++i) {
    if (lights[i - 1]) {
      if (first) {
        first = 0;
      } else {
        putchar(' ');
      }
      printf("%d", i);
    }
  }
  putchar('\n');
}

void solve(int n, int k) {
  set(n, k);
  show(n);
}

int main(void) {
  int n, k;
  scanf("%d%d", &n, &k);
  solve(n, k);
  return 0;
}
