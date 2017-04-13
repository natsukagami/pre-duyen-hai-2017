#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;

int N, X;
int A[MAXN];

ll smeq(ll val) {
  ll total = 0;
  for (int i = 1; i <= N; ++i)
    total += val / A[i] + 1;
  return total;
}

ll sm(ll val) {
  return smeq(val - 1);
}

ll price(ll val) {
  ll total = 0;
  for (int i = 1; i <= N; ++i) {
    ll lg = (val - 1) / A[i];
    total += (lg * A[i] * (lg + 1) / 2);
  }
  return total + (X - sm(val)) * val;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> X;
  for (int i = 1; i <= N; ++i)
    cin >> A[i];
  ll low = 0, hi = 1e12;
	while (low != hi) {
		ll mid = (low + hi) >> 1;
		if (smeq(mid) < X)
		  low = mid + 1; 
		else hi = mid;
	}
	cout << price(low) << endl;
}