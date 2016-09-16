//递归法求全排列  3!= 3*2*1 = 6
//给出特定的数组，输出它的全排列
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
int target_arr[maxn];  //已排好序

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

void print_permutation_p(int n, int* A, int cur) {
  if (cur == n) {
    mutation_count++;
    for (int i = 0; i < n; i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  } else {
    for (int i = 0; i < n; i++) {
      int c1 = 0, c2 = 0;
      //避免重复遍历 “1，1，1” 若干次
      if (!i || target_arr[i] != target_arr[i - 1]) {
        for (int j = 0; j < cur; j++) {
          if (A[j] == target_arr[i]) {
            c1++;  // 结果数组中target_arr[i] 出现的次数
          }
        }
        for (int j = 0; j < n; j++) {
          if (target_arr[i] == target_arr[j]) {
            c2++;  // 目标数组中target_arr[i] 出现的总次数
          }
        }

        if (c1 < c2) {  //能够输出
          //包含重复元素的序列组合“1，1，1”，结合之前的if判断，使得只输出一次
          A[cur] = target_arr[i];
          print_permutation_p(n, A, cur + 1);
        }
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
    //    print_permutation(n, nums, 0);
    for (int i = 0; i < n; i++) {
      target_arr[i] = n - i;
    }
    print_permutation_p(n, nums, 0);
    cout << "mutation_count: " << mutation_count << endl;
  }
  return 0;
}
