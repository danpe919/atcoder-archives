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
  V<ll> a(n);
  rep(i, n) cin >> a[i];
  map<ll, int> m;
  rep(i, n) m[a[i]]++;

  if (m.size() == 1 && m[0] == n) {
    cout << "Yes" << endl;
    return 0;
  }

  if (n % 3 != 0) {
    cout << "No" << endl;
    return 0;
  }

  V<P> p;
  for (auto e : m) p.push_back({e.first, e.second});
  sort(p.begin(), p.end());

  bool ans = true;
  if (p.size() == 1) {
    ans = p[0].first == 0;
  } else if (p.size() == 2) {
    if (p[0].first == 0 || p[1].first == 0) {
      ans = p[0].second == n / 3 || p[1].second == n / 3;
    } else {
      ans = false;
    }
  } else if (m.size() == 3) {
    for (auto e : m) {
      if (e.second != n / 3) ans = false;
    }
    ll sum = p[0].first ^ p[1].first;
    sum ^= p[2].first;
    if (sum != 0) ans = false;
  } else {
    ans = false;
  }

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
