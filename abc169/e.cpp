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
  V<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans;
  if (n % 2 != 0) {
    ll l = a[n / 2];
    ll r = b[n / 2];
    ans = r - l + 1;
  } else {
    ll l = (a[n / 2] + a[n / 2 - 1]);
    ll r = (b[n / 2] + b[n / 2 - 1]);
    ans = r - l + 1;
  }
  cout << ans << endl;
}
