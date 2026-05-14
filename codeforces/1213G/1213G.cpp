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

struct UF {
  vl e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<array<ll, 3>> eds(n - 1);

  rep(i, 0, n - 1) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    eds[i] = {w, u, v};
  }

  sort(all(eds));

  vector<pair<ll, ll>> ret;
  UF uf(n);

  ll cur = 0;
  ret.push_back({0, 0});
  for (auto [w, u, v] : eds) {
    cur += 1LL * uf.size(u) * uf.size(v);
    ret.push_back({w, cur});
    uf.join(u, v);
  }

  rep(i, 0, m) {
    int q;
    cin >> q;
    cout << (--upper_bound(all(ret), make_pair(q, INF)))->second
         << " \n"[i + 1 == m];
  }

  return 0;
}
