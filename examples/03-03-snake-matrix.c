// 22/02/16 = Wed

// Snake Matrix

// Fill 1 to (n x n) in an nxn square matrix. For example, when n = 4,

//  10  11  12   1
//   9  16  13   2
//   8  15  14   3
//   7   6   5   4

// Constraints:
// n <= 8

#include <stdio.h>

#define N 10

int matrix[N][N];

void set(int n) {
  int val = 0;
  for (int i = 1; i <= (n + 1) / 2; ++i) {
    for (int r = i - 1; r <= n - i - 1; ++r) {
      matrix[r][n - i] = ++val;
    }
    for (int c = n - i; c >= i; --c) {
      matrix[n - i][c] = ++val;
    }
    for (int r = n - i; r >= i; --r) {
      matrix[r][i - 1] = ++val;
    }
    for (int c = i - 1; c <= n - i - 1; ++c) {
      matrix[i - 1][c] = ++val;
    }
  }
  if (n % 2 == 1) {
    matrix[n / 2][n / 2] = ++val;
  }
}

void show(int n) {
  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != n; ++j) {
      printf("%4d", matrix[i][j]);
    }
    putchar('\n');
  }
}

void solve(int n) {
  set(n);
  show(n);
}

int main(void) {
  int n;
  scanf("%d", &n);
  solve(n);
  return 0;
}
