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
//
//int main() {
//  freopen("/Users/yuxiao/XcodeProject/7.brute solution/7.brute solution/in",
//          "r", stdin);
//  freopen("/Users/yuxiao/XcodeProject/7.brute solution/7.brute solution/out",
//          "w", stdout);
//
//  int T, t;
//  cin >> T;
//  t = 1;
//  LL ans;
//  while (T--) {
//    int n, s1, s2, v1, v2;
//    cin >> n >> s1 >> v1 >> s2 >> v2;
//    if (s1 > s2) { // s2 代表体积大的，s1 代表体积小的
//      swap(s1, s2);
//      swap(v1, v2);
//    }
//    ans = 0;
//    if (n / s2 >= 65536) {
//      for (LL i = 0; i <= s1; i++) { // s2 体积的物品不会超过s1
//        ans = max(ans, v2 * i + (n - s2 * i) / s1 * v1);
//      }
//      for (LL i = 0; i <= s2; i++) {
//        ans = max(ans, v1 * i + (n - s1 * i) / s2 * v2);
//      }
//    } else { // s2 is large
//      for (LL i = 0; s2 * i <= n; i++) {
//        ans = max(ans, v2 * i + (n - s2 * i) / s1 * v1);
//      }
//    }
//
//    printf("Case #%d: %lld\n", t++, ans);
//  }
//  return 0;
//}
