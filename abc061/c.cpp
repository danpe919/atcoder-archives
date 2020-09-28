#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  V<P> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;

  sort(p.begin(), p.end());
  ll num = 0;
  rep(i, n) {
    num += p[i].second;
    if (num >= k) {
      cout << p[i].first << endl;
      return 0;
    }
  }
}
