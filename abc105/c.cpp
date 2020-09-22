#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  ll n;
  cin >> n;

  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }

  string ans = "";
  ll d = 1;
  while (n != 0) {
    if (n == d) {
      ans += "1";
      break;
    }
    d *= -2;
    if (n % d != 0) {
      ans += "1";
      n -= d / -2;
    } else {
      ans += "0";
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
