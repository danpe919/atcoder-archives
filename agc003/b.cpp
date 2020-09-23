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
  V<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  rep(i, n - 1) {
    if (a[i] % 2 != 0 && a[i + 1] > 0) {
      a[i]--;
      a[i + 1]--;
      ans++;
    }
  }
  rep(i, n) ans += a[i] / 2;
  cout << ans << endl;
}
