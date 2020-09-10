#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;

  V<pair<int, char>> v;
  char p = s[0];
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (p != s[i]) {
      v.push_back({cnt, p});
      p = s[i];
      cnt = 0;
    }
    cnt++;
  }
  v.push_back({cnt, p});

  int num = v.size();
  V<int> cs(num);
  int sum = 0;
  rep(i, num) {
    sum += v[i].first;
    cs[i] = sum;
  }

  int ans = 0;
  rep(i, num) {
    int r;
    if (v[i].second == '1') {
      r = min(i + 2 * k, num - 1);
    } else {
      r = min(i + 2 * k - 1, num - 1);
    }
    int val = cs[r] - cs[i] + v[i].first;
    ans = max(ans, val);
  }
  cout << ans << endl;
}
