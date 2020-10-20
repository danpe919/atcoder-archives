#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const ll INF = 1e10;

int main() {
  int n, k;
  cin >> n >> k;
  int q, a, b, c, d;
  ll e;
  V<V<int>> g(n + 1, V<int>());
  unordered_map<string, ll> cost;

  auto regist = [&](int c, int d, ll e) {
    string k1 = to_string(c) + "," + to_string(d);
    string k2 = to_string(d) + "," + to_string(c);
    if (cost.find(k1) == cost.end()) {
      cost[k1] = e;
      cost[k2] = e;
    } else {
      cost[k1] = min(e, cost[k1]);
      cost[k2] = min(e, cost[k2]);
    }
    g[c].push_back(d);
    g[d].push_back(c);
  };
  auto get_cost = [&](int c, int d) {
    string k = to_string(c) + "," + to_string(d);
    return cost[k];
  };
  auto calc = [&](int s, int t) {
    priority_queue<P, V<P>, greater<P>> q;
    V<ll> cost(n + 1, INF);
    q.push(P(0, s));
    while (!q.empty()) {
      auto e = q.top();
      q.pop();
      // printf("[%ld]", e.second);
      for (auto i : g[e.second]) {
        // printf("%d ", i);
        ll c = e.first + get_cost(e.second, i);
        if (c >= cost[i]) continue;
        cost[i] = c;
        q.push(P(c, i));
      }
    }
    return (cost[t] == INF) ? -1 : cost[t];
  };

  rep(i, k) {
    cin >> q;
    if (q == 0) {
      cin >> a >> b;
      ll ans = calc(a, b);
      printf("%ld\n", ans);
    } else {
      cin >> c >> d >> e;
      regist(c, d, e);
    }
  }
}
