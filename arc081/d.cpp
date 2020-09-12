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
  string s1, s2;
  cin >> s1 >> s2;

  V<int> d;
  rep(i, n) {
    if (s1[i] == s2[i]) {
      d.push_back(1);
    } else {
      i++;
      d.push_back(2);
    }
  }
  int l = d.size();
  ll ans = (d[0] == 1) ? 3 : 6;
  for (int i = 1; i < l; i++) {
    if (d[i] == 1) {
      if (d[i - 1] == 1) ans = ans * 2 % mod;
    } else {
      if (d[i - 1] == 1) ans = ans * 2 % mod;
      if (d[i - 1] == 2) ans = ans * 3 % mod;
    }
  }
  cout << ans << endl;
}
