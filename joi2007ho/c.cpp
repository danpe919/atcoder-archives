#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
template <class T>
using V = vector<T>;

int v[] = {-1, 1};

int main() {
  int n;
  cin >> n;
  V<P> pos(n);
  unordered_map<ll, int> m;
  rep(i, n) {
    cin >> pos[i].first >> pos[i].second;
    ll id = pos[i].first * 5001 + pos[i].second;
    m[id] = 1;
  }

  int ans = 0;
  rep(j, n) rep(i, j) {
    const auto& a = pos[i];
    const auto& b = pos[j];
    int dx = a.second - b.second;
    int dy = a.first - b.first;
    rep(i, 2) {
      int _dx = dx * v[i];
      int _dy = dy * v[i];
      ll p1 = (a.first - _dx) * 5001 + (a.second + _dy);
      if (m.find(p1) == m.end()) continue;
      ll p2 = (b.first - _dx) * 5001 + (b.second + _dy);
      if (m.find(p2) == m.end()) continue;
      int s = pow(dx, 2) + pow(dy, 2);
      ans = max(s, ans);
    }
  }
  cout << ans << endl;
}
