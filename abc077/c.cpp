#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
template <class T>
using V = vector<T>;

int main() {
  int n;
  cin >> n;
  V<ll> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  V<int> b_ok(n + 1);
  rep(i, n) {
    int l = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
    b_ok[i] = n - l;
  }
  V<ll> acc(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    acc[i] = b_ok[i] + acc[i + 1];
  }

  ll ans = 0;
  rep(i, n) {
    int l = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    ans += acc[l];
  }
  cout << ans << endl;
}
