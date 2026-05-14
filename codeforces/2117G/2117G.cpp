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

const int INF = 2e9;

struct UF {
  vi e, mini;
  UF(int n) : e(n, -1), mini(n, INF) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b, int w = INF) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    mini[a] = min(mini[a], min(mini[b], w));
    e[b] = a;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> eds(m);
    rep(i, 0, m) {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      eds[i] = {u, v, w};
    }
    sort(all(eds), [&](const array<int, 3>& a, const array<int, 3>& b) {
      return a[2] < b[2];
    });

    UF uf(n);
    int ret = INF;

    for (auto [u, v, w] : eds) {
      uf.join(u, v, w);
      if (uf.sameSet(0, n - 1)) {
        ret = min(ret, w + uf.mini[uf.find(0)]);
      }
    }
    cout << ret << '\n';
  }
  return 0;
}
