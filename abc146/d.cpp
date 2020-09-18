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
  V<V<int>> to(n);
  V<int> a(n - 1), b(n - 1);
  rep(i, n - 1) {
    int p, q;
    cin >> p >> q;
    --p;
    --q;
    a[i] = p;
    b[i] = q;
    to[p].push_back(q);
    to[q].push_back(p);
  }

  int num = 1;
  V<int> c(n, -1);
  queue<int> q;
  c[0] = 0;
  q.push(0);
  while (!q.empty()) {
    auto e = q.front();
    q.pop();
    int tmp = 1;
    for (auto i : to[e]) {
      if (c[i] >= 0) continue;
      if (tmp == c[e]) tmp++;
      c[i] = tmp++;
      num = max(c[i], num);
      q.push(i);
    }
  }
  cout << num << endl;
  rep(i, n - 1) printf("%d\n", c[b[i]]);
}
