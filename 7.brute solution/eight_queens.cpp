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
// using namespace std;
//#define LL long long
// const int maxn = 100;
// int n;
// int total;  //一共有多少种解法
// int columns[maxn];  // columns[i] 表示第i行应该把皇后放置的在第column[i] 列
// int visited[3][maxn];  //利用二维数组判断是否有冲突
//
////八皇后问题
// void queen_search(int cur) {
//  if (cur == n) {
//    total++;
//  } else {
//    for (int i = 0; i < n; i++) {
//      int ok = 1;
//      columns[cur] = i;  //尝试把第cur行的皇后放到第i列
//      for (int j = 0; j < cur; j++) {
//        //判断已放过的皇后是否有同列，主对角线和副对角线有没有冲突
//        if (columns[j] == columns[cur] ||
//            cur - columns[cur] == j - columns[j] ||
//            cur + columns[cur] == j + columns[j]) {
//          ok = 0;
//          break;
//        }
//      }
//      if (ok) {
//        queen_search(cur + 1);
//      }
//    }
//  }
//}
//
////利用辅助的全局变量visited[][] 数组记录冲突
// void queen_search2(int cur) {
//  if (cur == n) {
//    total++;
//  } else {
//    for (int i = 0; i < n; i++) {
//      //列冲突、主副对角线冲突
//      if (!visited[0][i] && !visited[1][cur + i] && !visited[2][cur - i + n])
//      {
//        columns[cur] = i;
//        visited[0][i] = visited[1][cur + i] = visited[2][cur - i + n] = 1;
//        queen_search(cur + 1);
//        ////如果在回溯法中修改了辅助的全局变量，则一定要及时把它们恢复原状
//        visited[0][i] = visited[1][cur + i] = visited[2][cur - i + n] = 0;
//      }
//    }
//  }
//}
//
// int main() {
//  //  freopen("", "r", stdin);
//  //  freopen("", "w", stdout);
//
//  int T, t;
//  cin >> T;
//  t = 1;
//  while (T--) {
//    cin >> n;
//    total = 0;
//    memset(visited, 0, sizeof(visited));
//    queen_search2(0);
//    cout << "answer: " << total << endl;
//  }
//  return 0;
//}
