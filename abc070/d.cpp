#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

V<V<int>> to;
V<ll> d(100010, -1);
map<pair<int, int>, ll> cost;

void dfs(int n, ll dist = 0) {
  d[n] = dist;
  for (auto e : to[n]) {
    if (n == e) continue;
    if (d[e] >= 0) continue;
    dfs(e, dist + cost[{n, e}]);
  }
}

int main() {
  int n;
  cin >> n;
  to.resize(n);

  rep(i, n - 1) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    --a;
    --b;
    to[a].push_back(b);
    to[b].push_back(a);
    cost[{a, b}] = c;
    cost[{b, a}] = c;
  }
  int q, k;
  cin >> q >> k;
  --k;

  dfs(k);

  rep(i, q) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    ll ans = d[x] + d[y];
    printf("%ld\n", ans);
  }
}
