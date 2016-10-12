//// UVa11212 Editing a Book   IDA* 算法 经典 迭代加深 + 剪枝
//// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2153
//// Rujia Liu
//// This implementation is not very fast, but easy to understand
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//const int maxn = 9;
//int n, a[maxn];
//
//bool is_sorted() {
//  for (int i = 0; i < n - 1; i++)
//    if (a[i] >= a[i + 1])
//      return false;
//  return true;
//}
//
//// the number of integers with incorrect successor
//int h() {
//  int cnt = 0;
//  for (int i = 0; i < n - 1; i++)
//    if (a[i] + 1 != a[i + 1])
//      cnt++;
//  if (a[n - 1] != n)
//    cnt++;
//  return cnt;
//}
//
//bool dfs(int d, int maxd) {
//  // 设深度上限为maxd, 当前节点深度为d,乐观估价还需添加深度为h,则当 d+h > maxd
//  // 应该剪枝
//  if (d * 3 + h() > maxd * 3)
//    return false;
//  if (is_sorted())
//    return true;
//
//  int b[maxn], olda[maxn];
//  memcpy(olda, a, sizeof(a));
//  for (int i = 0; i < n; i++)
//    for (int j = i; j < n; j++) {
//      // cut
//      int cnt = 0;
//      for (int k = 0; k < n; k++)
//        if (k < i || k > j)
//          b[cnt++] = a[k];
//
//      // insert before position k
//      for (int k = 0; k <= cnt; k++) {
//        int cnt2 = 0;
//        for (int p = 0; p < k; p++)
//          a[cnt2++] = b[p];
//        for (int p = i; p <= j; p++)
//          a[cnt2++] = olda[p];
//        for (int p = k; p < cnt; p++)
//          a[cnt2++] = b[p];
//
//        if (dfs(d + 1, maxd))
//          return true;
//        memcpy(a, olda, sizeof(a)); // 回溯，还原
//      }
//    }
//  return false;
//}
//
//int solve() {
//  if (is_sorted())
//    return 0;
//  int max_ans = 5; // after experiments, we found ans <= 5 for n <= 9
//  for (int maxd = 1; maxd < max_ans; maxd++) // maxd 定义dfs 树的最大深度
//    // 设深度上限为maxd, 当前节点深度为d,乐观估价还需添加深度为h,则当 d+h > maxd
//    // 应该剪枝
//    if (dfs(0, maxd))
//      return maxd;
//  return max_ans;
//}
//
//int main() {
//  int kase = 0;
//  while (scanf("%d", &n) == 1 && n) {
//    for (int i = 0; i < n; i++)
//      scanf("%d", &a[i]);
//    printf("Case %d: %d\n", ++kase, solve());
//  }
//  return 0;
//}
