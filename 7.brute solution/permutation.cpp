//递归法求全排列  3!= 3*2*1 = 6
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define LL long long
const int maxn = 100;
int mutation_count;

void print_permutation(int n, int* a, int cur) {
  if (cur == n) {
    mutation_count++;
    for (int i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  } else {
    for (int j = 1; j <= n; j++) {
      int ok = 1;
      for (int k = 0; k < cur; k++) {
        if (a[k] == j) {
          ok = 0;
        }
      }
      if (ok) {
        a[cur] = j;

        print_permutation(n, a, cur + 1);
      }
    }
  }
}

int n;
int nums[maxn];

int main() {
  //  freopen("/Users/yuxiao/XcodeProject/7.brute solution/7.brute solution/in",
  //          "r", stdin);
  //  freopen("/Users/yuxiao/XcodeProject/7.brute solution/7.brute
  //  solution/out",
  //          "w", stdout);

  int T, t;
  cin >> T;
  t = 1;
  while (T--) {
    cin >> n;
    mutation_count = 0;
    print_permutation(n, nums, 0);
    cout << "mutation_count: " << mutation_count << endl;
  }
  return 0;
}
