#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

bool has8(int n) {
  int div = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) div++;
  }
  return div == 8;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    if (has8(i)) ans++;
  }
  cout << ans << endl;
}
