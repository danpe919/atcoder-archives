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
  V<int> f(n);
  rep(i, n) {
    int p = 0;
    rep(j, 10) {
      p <<= 1;
      int b;
      cin >> b;
      p += b;
    }
    f[i] = p;
  }
  V<V<ll>> p(n, V<ll>(11));
  rep(i, n) rep(j, 11) cin >> p[i][j];

  ll ans = -1e10;
  for (int i = 1; i < 1 << 10; i++) {
    ll val = 0;
    rep(j, n) {
      int idx = __builtin_popcount(i & f[j]);
      val += p[j][idx];
    }
    ans = max(ans, val);
  }
  cout << ans << endl;
}
