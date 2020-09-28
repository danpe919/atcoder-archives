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
  string s;
  cin >> s;

  int ans = 1;
  string tmp = "b";
  while (tmp.length() < s.length()) {
    int mod = ans % 3;
    if (mod == 0) {
      tmp = "b" + tmp + "b";
    } else if (mod == 1) {
      tmp = "a" + tmp + "c";
    } else if (mod == 2) {
      tmp = "c" + tmp + "a";
    }
    ans++;
  }
  ans--;
  if (tmp != s) ans = -1;
  cout << ans << endl;
}
