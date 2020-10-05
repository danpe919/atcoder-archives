#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const int MAX = 2e5 + 10;
V<int> cache(MAX);

int f(int n, int c) {
  if (n == 0) return c;
  if (cache[n] != 0) return c + cache[n];

  int v = n % __builtin_popcount(n);
  int ret = f(v, c + 1);
  cache[n] = ret;
  return ret;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int c = count(s.begin(), s.end(), '1');
  rep(i, MAX) f(i, 0);

  V<int> for0(n), for1(n);
  int val1(1), val2(1);
  rep(i, n) {
    for0[n - i - 1] = val1;
    for1[n - i - 1] = val2;
    val1 = (val1 << 1) % (c + 1);
    if (c != 1) val2 = (val2 << 1) % (c - 1);
  }
  ll sumfor0(0), sumfor1(0);
  rep(i, n) {
    if (s[i] == '0') continue;
    sumfor0 += for0[i];
    sumfor1 += for1[i];
  }

  rep(i, n) {
    int val;
    if (s[i] == '0') {
      val = (sumfor0 + for0[i]) % (c + 1);
    } else {
      if (c == 1) {
        cout << 0 << endl;
        continue;
      } else {
        val = (sumfor1 - for1[i]) % (c - 1);
      }
    }
    cout << cache[val] + 1 << endl;
  }
}
