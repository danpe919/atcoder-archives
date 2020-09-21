#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const ll mod = 1e9 + 7;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  V<int> a(n);
  rep(i, n) cin >> a[i];

  ll single = 0;
  rep(j, n) rep(i, j) {
    if (a[i] > a[j]) single++;
  }
  int num = 0;
  rep(i, n) rep(j, n) {
    if (a[i] > a[j]) num++;
  }
  ll tmp = k * (k - 1) / 2 % mod;
  tmp = tmp * num % mod;

  ll ans = single * k % mod;
  ans += tmp;
  ans %= mod;

  cout << ans << endl;
}
