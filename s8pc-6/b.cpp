#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

ll calc_median(V<ll>& vec) {
  int n = vec.size();
  if (n % 2 != 0) {
    return vec[n / 2];
  } else {
    ll m1 = vec[n / 2 - 1];
    ll m2 = vec[n / 2];
    return (m1 + m2) / 2;
  }
}

int main() {
  int n;
  cin >> n;
  V<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans = 0;
  rep(i, n) ans += abs(a[i] - b[i]);
  ll ma = calc_median(a);
  ll mb = calc_median(b);
  rep(i, n) ans += abs(a[i] - ma);
  rep(i, n) ans += abs(b[i] - mb);

  cout << ans << endl;
}
