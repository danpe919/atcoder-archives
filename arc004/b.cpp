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
  V<int> d(n);
  rep(i, n) cin >> d[i];

  sort(d.rbegin(), d.rend());
  ll max = accumulate(d.begin(), d.end(), 0L);

  ll min = 0;
  if (n == 1) {
    min = d[0];
  } else if (n == 2) {
    min = abs(d[0] - d[1]);
  } else {
    int m1 = d[0], m2 = d[1];
    int r = max - m1 - m2;
    if (r + m2 >= m1) {
      min = 0;
    } else {
      min = m1 - m2 - r;
    }
  }

  cout << max << endl;
  cout << min << endl;
}
