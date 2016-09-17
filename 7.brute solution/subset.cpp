// 求子集 如 {0，1，2}

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
void print_subset(int n, int* A, int cur) {
  for (int i = 0; i < cur; i++) {
    cout << A[i] << " ";  //打印当前集合
  }
  cout << endl;
  // cur 的值是不变的，直到下一次递归，因此for循环可以使A[0]=0，1，2
  int small = (cur ? A[cur - 1] + 1 : 0);  //确定当前元素的最小可能值
  for (int i = small; i < n; i++) {
    A[cur] = i;
    print_subset(n, A, cur + 1);  //递归构造子集
  }
}

// 0 1 2
// 0 1
// 0 2
// 0
// 1 2
// 1
// 2
//位向量法求子集
void print_subset2(int n, int* B, int cur) {
  if (cur == n) {
    for (int i = 0; i < cur; i++) {
      if (B[i]) {
        cout << i << " ";
      }
    }
    cout << endl;
    return;
  }
  // cur 的值是不变的，直到下一次递归过程，因此可以保证B[0] = 1,B[0] =
  // 0都会遍历到
  B[cur] = 1;
  print_subset2(n, B, cur + 1);  //选第cur个元素
  B[cur] = 0;
  print_subset2(n, B, cur + 1);  // 不选第cur个元素
}

int n;
int nums[maxn];
int visited[maxn];
int main() {
  //  freopen("", "r", stdin);
  //  freopen("", "w", stdout);

  int T, t;
  cin >> T;
  t = 1;
  while (T--) {
    cin >> n;
    print_subset(n, visited, 0);
  }
  return 0;
}
