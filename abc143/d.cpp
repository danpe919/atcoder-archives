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
  V<int> l(n);
  rep(i, n) cin >> l[i];

  sort(l.begin(), l.end());

  int ans = 0;
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      auto left =
          upper_bound(l.begin() + j + 1, l.end(), abs(l[i] - l[j])) - l.begin();
      auto right =
          lower_bound(l.begin() + j + 1, l.end(), l[i] + l[j]) - l.begin();
      ans += right - left;
    }
  }
  cout << ans << endl;
}
