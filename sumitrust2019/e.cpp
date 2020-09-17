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
  cin >> n;
  V<ll> a(n);
  rep(i, n) cin >> a[i];

  ll c1(0), c2(0), c3(0);
  ll tmp = 1;

  V<ll> sub;
  rep(i, n) {
    if (c1 == c2 && c2 == c3) {
      sub.push_back(tmp);
      tmp = 1;
    }

    int p1(0), p2(0), p3(0);
    if (a[i] == c1) p1++;
    if (a[i] == c2) p2++;
    if (a[i] == c3) p3++;

    ll p = p1 + p2 + p3;
    tmp = tmp * p % mod;
    if (p1)
      c1++;
    else if (p2)
      c2++;
    else if (p3)
      c3++;
  }
  ll ans = tmp;
  for (auto e : sub) ans = ans * e % mod;
  cout << ans << endl;
}
