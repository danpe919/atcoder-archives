#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

bool is_acgt(char c) { return c == 'A' || c == 'G' || c == 'C' || c == 'T'; }

int main() {
  string s;
  cin >> s;
  int n = s.length();
  int ans = 0;
  rep(i, n) {
    if (!is_acgt(s[i])) continue;

    int len = 1;
    for (int j = i + 1; j < n; ++j) {
      if (!is_acgt(s[j])) break;
      len++;
    }
    ans = max(ans, len);
  }
  cout << ans << endl;
}
