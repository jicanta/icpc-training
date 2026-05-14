#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for (int i = (int)b - 1; i >= a; i--)
#define sz(x) (int)(x.size())
#define all(x) begin(x), end(x)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
using ll = long long;
using vl = vector<ll>;

const ll INF = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    vl a(n);
    rep(i, 0, n) cin >> a[i];

    vl modP(n + 1, 0), modQP(n + 1, 0);
    rep(i, 1, n + 1) modP[i] = modP[i - 1] + (a[i - 1] % p);
    rep(i, 1, n + 1) modQP[i] = modQP[i - 1] + (a[i - 1] % q % p);
    vl prefMin(n + 1, 0), sufMin(n + 2, 0);
    rep(i, 1, n + 1) prefMin[i] =
        prefMin[i - 1] + min(a[i - 1] % p, a[i - 1] % q % p);
    per(i, 1, n + 1) sufMin[i] =
        sufMin[i + 1] + min(a[i - 1] % p, a[i - 1] % q % p);

    ll ret = INF;
    rep(st, 1, n - k + 2) {
      ret = min(ret, prefMin[st - 1] + sufMin[st + k] +
                         min(modP[st + k - 1] - modP[st - 1],
                             modQP[st + k - 1] - modQP[st - 1]));
    }
    cout << ret << '\n';
  }

  return 0;
}
