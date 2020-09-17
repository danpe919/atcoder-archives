#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n;
  cin >> n;
  map<P, ll> g;
  V<V<ll>> e(n);
  rep(i, n - 1) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    g[{u, v}] = w;
    g[{v, u}] = w;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  V<int> c(n, -1);
  c[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    auto i = q.front();
    q.pop();
    for (auto node : e[i]) {
      if (c[node] != -1) continue;
      if (g[{i, node}] % 2 == 0) {
        c[node] = c[i];
      } else {
        c[node] = !c[i];
      }
      q.push(node);
    }
  }
  rep(i, n) printf("%d\n", c[i]);
}
