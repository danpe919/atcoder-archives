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
  V<ll> x(n), y(n);
  V<ll> h(n);
  rep(i, n) cin >> x[i] >> y[i] >> h[i];

  rep(cx, 101) rep(cy, 101) {
    bool ok = true;
    ll H = -1;
    ll max_h = 1e10;

    rep(i, n) {
      if (h[i] != 0) {
        ll cand = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
        if (H == -1) H = cand;
        if (H != cand || H > max_h) {
          ok = false;
          break;
        }
      } else {
        max_h = min(max_h, abs(x[i] - cx) + abs(y[i] - cy));
        if (H > max_h) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      printf("%d %d %ld\n", cx, cy, H);
      return 0;
    }
  }
}
