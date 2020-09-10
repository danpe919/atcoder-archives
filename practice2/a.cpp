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

  dsu d(n);
  rep(i, q) {
    int query, v1, v2;
    cin >> query >> v1 >> v2;
    if (query == 0) {
      d.merge(v1, v2);
    } else {
      bool same = d.same(v1, v2);
      cout << ((same) ? "1" : "0") << endl;
    }
  }
}
