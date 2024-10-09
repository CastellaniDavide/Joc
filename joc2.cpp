/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 20

#define DEBUG

// input data
int N, K, i, j;
bool V[MAXN];

int main() {
  //  uncomment the following lines if you want to read/write from files
  #ifdef DEBUG
  freopen("input0.txt", "r", stdin);
  #endif // DEBUG
  //  freopen("output.txt", "w", stdout);

  assert(2 == scanf("%d %d", &N, &K));
  for (i = 0; i < N; i++) {
    int val;
    assert(1 == scanf("%d", &val));
    V[i] = val;
  }

  for (i = 0; i < N; i++) {
    int t;
    assert(1 == scanf("%d", &t));
    for (j = 0; j < t; j++) {
      int pos;
      assert(1 == scanf("%d", &pos));
      // the i-th button will turn off the pos-th light
    }
  }

  // insert your code here

  printf("%d\n", 42);  // change 42 with actual answer
  return 0;
}
