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
  V<V<ll>> a(n, V<ll>(m));
  rep(i, n) rep(j, m) { cin >> a[i][j]; }

  ll ans = 0;
  rep(j, m) rep(i, j) {
    ll point = 0;
    rep(k, n) { point += max(a[k][i], a[k][j]); }
    ans = max(ans, point);
  }
  cout << ans << endl;
}
