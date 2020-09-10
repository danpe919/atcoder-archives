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
  deque<P> h(n);
  rep(i, n) cin >> h[i].first >> h[i].second;

  sort(h.begin(), h.end(), [&](const P& a, const P& b) {
    return a.first + a.second < b.first + b.second;
  });

  ll ta(0), ao(0);
  bool t = true;
  while (h.size() > 0) {
    if (t) {
      ta += h.back().first;
      h.pop_back();
    } else {
      ao += h.back().second;
      h.pop_back();
    }
    t = !t;
  }
  cout << ta - ao << endl;
}
