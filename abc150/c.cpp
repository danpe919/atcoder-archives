#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const int MAX = 1e5 + 10;

int main() {
  int n;
  cin >> n;
  V<int> p(n), q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];

  V<int> nums(n);
  rep(i, n) nums[i] = i + 1;

  auto is_same = [&](V<int>& l) {
    bool same = true;
    rep(i, n) if (l[i] != nums[i]) same = false;
    return same;
  };
  int a(0), b(0);
  int cnt = 1;
  do {
    if (is_same(p)) a = cnt;
    if (is_same(q)) b = cnt;
    cnt++;
  } while (next_permutation(nums.begin(), nums.end()));

  int ans = abs(a - b);
  cout << ans << endl;
}
