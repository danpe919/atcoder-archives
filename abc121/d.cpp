#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

ll count(ll n, ll m) {
  ll ret = n % m;
  ret -= m / 2;
  if (ret < 0) return 0;
  return ret + 1;
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll mod = 4;
  ll ans = 0;
  while (b * 10 >= mod) {
    ll n1 = count(a, mod);
    ll n2 = count(b, mod);

    ll num;
    if (a / mod == b / mod) {
      num = n2 - n1;
      if (n1 > 0) num++;
    } else {
      num = mod / 2 - n1 + n2;
      if (n1 > 0) num++;
    }

    if (num % 2 != 0) ans += mod / 2;
    mod *= 2;
  }

  ll num = (b - a + 1) / 2;
  if ((b - a + 1) % 2 != 0) {
    if (a % 2 != 0) num++;
  }
  if (num % 2 != 0) ans++;

  cout << ans << endl;
}
