#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

struct Bit {
  int n;
  V<map<char, int>> data;
  Bit(int n_) {
    n = n_ + 1;
    data.resize(n + 10);
  }
  void remove(int a, char c) {
    for (int x = a; x <= n; x += x & -x) {
      data[x][c]--;
    }
  }
  void add(int a, char c) {
    for (int x = a; x <= n; x += x & -x) {
      data[x][c]++;
    }
  }
  int query(int a, int b) {
    auto mb = sum(b);
    auto ma = sum(a);
    int ret = 0;
    for (auto e : mb) {
      int num = e.second - ma[e.first];
      if (num > 0) ret++;
    }
    return ret;
  }
  map<char, int> sum(int a) {
    map<char, int> ret;
    for (int x = a; x > 0; x -= x & -x) {
      for (auto c : data[x]) ret[c.first] += c.second;
    }
    return ret;
  }
};

int main() {
  int n, Q;
  string s;
  cin >> n >> s >> Q;

  Bit bit(n);
  rep(i, n) { bit.add(i + 1, s[i]); }
  s = " " + s;

  int idx, l, r;
  char c;
  rep(i, Q) {
    int q;
    cin >> q;
    if (q == 1) {
      cin >> idx >> c;
      bit.remove(idx, s[idx]);
      bit.add(idx, c);
      s[idx] = c;
    } else {
      cin >> l >> r;
      int ans = bit.query(l - 1, r);
      printf("%d\n", ans);
    }
  }
}
