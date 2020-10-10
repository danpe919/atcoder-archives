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
  V<ll> a(n + 1);
  rep(i, n + 1) cin >> a[i];

  V<ll> m(n + 1);
  m[n] = a[n];
  for (int i = n - 1; i >= 0; i--) {
    m[i] = m[i + 1] + a[i];
  }

  ll ans = 1;
  ll leaf = 1;
  bool ok = true;
  if (n == 0) {
    ok = a[0] == 1;
  } else {
    ok = a[0] == 0;
  }
  rep(i, n) {
    leaf = min(m[i + 1], (leaf - a[i]) * 2);
    ans += leaf;
    if (leaf < a[i + 1]) {
      ok = false;
      break;
    }
  }
  if (!ok) ans = -1;
  cout << ans << endl;
}
