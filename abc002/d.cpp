#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n, m;
  cin >> n >> m;
  V<V<int>> r(n, V<int>(n, 0));

  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    r[x][y] = 1;
    r[y][x] = 1;
  }

  int ans = 0;
  rep(i, 1 << n) {
    V<int> cans;
    rep(j, n) if (i >> j & 1) cans.push_back(j);
    int R = cans.size();
    bool ok = true;
    rep(k, R) rep(j, k) {
      if (r[cans[j]][cans[k]] == 0) ok = false;
    }
    if (ok) ans = max(ans, R);
  }
  cout << ans << endl;
}
