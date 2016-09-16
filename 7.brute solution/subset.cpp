// 求子集 如 {0，1，2}
//
// 3
//
// 0
// 0 1
// 0 1 2
// 0 2
// 1
// 1 2
// 2
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

//增量法求子集
void print_subset(int n, int* A, int cur) {
  for (int i = 0; i < cur; i++) {
    cout << A[i] << " ";  //打印当前集合
  }
  cout << endl;
  int small = (cur ? A[cur - 1] + 1 : 0);  //确定当前元素的最小可能值
  for (int i = small; i < n; i++) {
    A[cur] = i;
    print_subset(n, A, cur + 1);  //递归构造子集
  }
}

int n;
int nums[maxn];
int main() {
  //  freopen("", "r", stdin);
  //  freopen("", "w", stdout);

  int T, t;
  cin >> T;
  t = 1;
  while (T--) {
    cin >> n;
    print_subset(n, nums, 0);
  }
  return 0;
}
