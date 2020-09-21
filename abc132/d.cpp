#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const ll mod = 1e9 + 7;

V<ll> fac, finv, inv;
void comb_init(int max) {
  fac.resize(max);
  finv.resize(max);
  inv.resize(max);
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < max; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = mod - inv[mod % i] * (mod / i) % mod;
    finv[i] = finv[i - 1] * inv[i] % mod;
  }
}
ll comb_cache(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
  int n, k;
  cin >> n >> k;

  comb_init(2020);
  for (int i = 1; i <= k; i++) {
    ll red = comb_cache(n - k + 1, i);
    ll blue = comb_cache(k - 1, i - 1);
    ll ans = red * blue % mod;
    printf("%ld\n", ans);
  }
}
