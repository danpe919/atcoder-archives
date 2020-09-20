#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n, m;
  cin >> n >> m;
  V<int> c(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    c[a]++;
    c[b]++;
  }
  bool ans = true;
  rep(i, n) {
    if (c[i] % 2 != 0) ans = false;
  }
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
