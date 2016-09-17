//// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=841&problem=465&mosmsg=Submission+received+with+ID+18014702
//// 素数环 回溯 判断质数
//#include <algorithm>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <iostream>
//#include <map>
//#include <queue>
//#include <set>
//#include <string>
//#include <vector>
//using namespace std;
//#define LL long long
//const int maxn = 20;
//
//int n;
//int ans[maxn];
//int visited[maxn];
//
//bool is_prime(int a) {
//  if (a == 2) {
//    return true;
//  } else if (a % 2 == 0) {
//    return false;
//  } else {
//    for (int i = 2; i * i <= a; i++) {
//      if (a % i == 0) {
//        return false;
//      }
//    }
//  }
//  return true;
//}
//
//void prime_ring(int cur) {
//  if (cur == n + 1) {
//    if (ans[1] == 1) {
//      printf("%d", 1);
//      for (int i = 2; i <= n; i++) {
//        printf(" %d", ans[i]);
//      }
//      printf("\n");
//    }
//  } else {
//    for (int i = 1; i <= n; i++) {
//      if (!visited[i]) {
//        int ok = 0;
//        int temp_sum = 0;
//        int temp_sum2 = 0;
//        if (cur == 1) {
//          ok = 1;
//        } else if (cur == n) {
//          temp_sum = ans[n - 1] + i;
//          temp_sum2 = ans[1] + i;
//          if (is_prime(temp_sum) && is_prime(temp_sum2)) {
//            ok = 1;
//          }
//        } else {
//          temp_sum = ans[cur - 1] + i;
//          if (is_prime(temp_sum)) {
//            ok = 1;
//          }
//        }
//
//        if (ok) {
//          ans[cur] = i;
//          visited[i] = 1;
//          prime_ring(cur + 1);
//          visited[i] = 0;
//        }
//      }
//    }
//  }
//}
//
//int main() {
//  //  freopen("/Users/yuxiao/XcodeProject/7.brute solution/7.brute solution/in",
//  //          "r", stdin);
//  //  freopen("/Users/yuxiao/XcodeProject/7.brute solution/7.brute
//  //  solution/out",
//  //          "w", stdout);
//
//  int t;
//
//  t = 1;
//  while (scanf("%d", &n) != EOF) {
//    if (t > 1) printf("\n");
//    printf("Case %d:\n", t++);
//    if (n != 1) {
//      prime_ring(1);
//    }
//  }
//  return 0;
//}
