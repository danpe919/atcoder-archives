#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> fw(n);
  rep(i, n) {
    int ai;
    cin >> ai;
    fw.add(i, ai);
  }

  rep(i, q) {
    int query;
    cin >> query;
    if (query == 0) {
      ll p, x;
      cin >> p >> x;
      fw.add(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << fw.sum(l, r) << endl;
    }
  }
}
