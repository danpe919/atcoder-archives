#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const int MAX = 64;
const ll mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  V<ll> a(n);
  rep(i, n) cin >> a[i];

  V<V<P>> bits(n, V<P>(MAX, {0, 0}));
  for (int i = 0; i < n; i++) {
    rep(j, MAX) {
      bits[i][j] = (i > 0) ? bits[i - 1][j] : P({0, 0});
      if (a[i] >> j & 1)
        bits[i][j].first++;
      else
        bits[i][j].second++;
    }
  }
  ll ans = 0;
  rep(i, n - 1) {
    V<P> b = bits[n - 1];
    rep(j, MAX) {
      b[j].first -= bits[i][j].first;
      b[j].second -= bits[i][j].second;
    }
    ll e = 1;
    rep(j, MAX) {
      if (a[i] >> j & 1) {
        ans += b[j].second * e % mod;
      } else {
        ans += b[j].first * e % mod;
      }
      ans %= mod;
      e = e * 2 % mod;
    }
  }
  cout << ans << endl;
}
