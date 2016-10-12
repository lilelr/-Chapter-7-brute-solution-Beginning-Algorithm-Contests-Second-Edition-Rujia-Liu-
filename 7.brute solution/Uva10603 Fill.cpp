// UVa10603 Fill
// Rujia Liu
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
  int v[3], dist;
  bool operator<(const Node &rhs) const { return dist > rhs.dist; }
};

const int maxn = 200 + 5;
int mark[maxn][maxn], dist[maxn][maxn], cap[3], ans[maxn];
// ans[d] 表示倒出d升水所需的最少水量
// 更新答案，即ans[d] 更新为u.dist 的最少水量
void update_ans(const Node &u) {
  for (int i = 0; i < 3; i++) {
    int d = u.v[i];
    if (ans[d] < 0 || u.dist < ans[d])
      ans[d] = u.dist;
  }
}

void solve(int a, int b, int c, int d) {
  cap[0] = a;
  cap[1] = b;
  cap[2] = c;
  memset(ans, -1, sizeof(ans));
  memset(mark, 0, sizeof(mark));
  memset(dist, -1, sizeof(dist));
  priority_queue<Node> q;

  Node start;
  start.dist = 0; // 第一个状态节点，已倒的最少水量为0
  start.v[0] = 0;
  start.v[1] = 0;
  start.v[2] = c;
  q.push(start);

  dist[0][0] = 0;
  while (!q.empty()) {
    Node u = q.top();
    q.pop();
    if (mark[u.v[0]][u.v[1]])
      continue; // 该状态已经遍历过
    mark[u.v[0]][u.v[1]] = 1;
    update_ans(u);
    if (ans[d] >= 0)
      break; //所求的状态已经到达，over
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (i != j) {
          if (u.v[i] == 0 || u.v[j] == cap[j])
            continue;
          int amount = min(cap[j], u.v[i] + u.v[j]) -
                       u.v[j]; // 把 u.v[i] 的水倒到 u.v[j]
          Node u2;
          memcpy(&u2, &u, sizeof(u));
          u2.dist = u.dist + amount;
          u2.v[i] -= amount;
          u2.v[j] += amount;
          int &D = dist[u2.v[0]][u2.v[1]];
          if (D < 0 || u2.dist < D) {
            // 是最少水量才进队，否则不进；
            D = u2.dist;
            q.push(u2);
          }
        }
  }
  while (d >= 0) {
    if (ans[d] >= 0) {
      printf("%d %d\n", ans[d], d);
      return;
    }
    d--; // 找最接近于目标的小d
  }
}

int main() {
  int T, a, b, c, d;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    solve(a, b, c, d);
  }
  return 0;
}
