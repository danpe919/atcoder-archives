#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const int INF = 1e7;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

using L = tuple<int, int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  V<string> g(h);
  rep(i, h) cin >> g[i];

  V<V<int>> c(h, V<int>(w, INF));
  priority_queue<L, V<L>, greater<L>> q;
  rep(i, h) rep(j, w) {
    if (g[i][j] == '.') continue;
    c[i][j] = 0;
    for (int k = 0; k < 4; k++) {
      int x = j + dx[k];
      int y = i + dy[k];
      if (x < 0 || x >= w || y < 0 || y >= h) continue;
      if (g[y][x] == '#') continue;
      c[y][x] = 1;
      q.push({1, y, x});
    }
  }
  while (!q.empty()) {
    auto e = q.top();
    q.pop();
    int d = get<0>(e);
    int i = get<1>(e);
    int j = get<2>(e);
    for (int k = 0; k < 4; k++) {
      int x = j + dx[k];
      int y = i + dy[k];
      if (x < 0 || x >= w || y < 0 || y >= h) continue;
      if (g[y][x] == '#') continue;
      int cost = d + 1;
      if (cost < c[y][x]) {
        c[y][x] = cost;
        q.push({cost, y, x});
      }
    }
  }
  int ans = 0;
  rep(i, h) rep(j, w) ans = max(ans, c[i][j]);
  cout << ans << endl;
}
