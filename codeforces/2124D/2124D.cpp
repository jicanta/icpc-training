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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vi b = a;
    sort(begin(b), end(b));

    if (k == 1) {
      cout << "YES\n";
      continue;
    }

    int x = b[k - 1];
    vi newA;
    rep(i, 0, n) if (a[i] <= x) { newA.push_back(a[i]); }

    int deleted = 0;
    int i = 0, j = sz(newA) - 1;
    bool can = true;
    while (i < j) {
      if (newA[i] == newA[j])
        i++, j--;
      else {
        deleted++;
        if (newA[i] == x) {
          i++;
        } else if (newA[j] == x) {
          j--;
        } else {
          can = false;
          break;
        }
      }
    }

    if (sz(newA) - deleted < k - 1) can = false;
    if (can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
