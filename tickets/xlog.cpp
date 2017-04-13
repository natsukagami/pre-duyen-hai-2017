#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;
const int MAXN = 1e5 + 5;

int N, X;
int A[MAXN];
priority_queue<ii, vector<ii>, greater<ii> > q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> X;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	for (int i = 1; i <= N; ++i) q.push(ii(0, i));
	ll total = 0;
	while (X--) {
		ii p = q.top(); q.pop();
		total += p.first; q.push(ii(p.first + A[p.second], p.second));
	}
	cout << total << endl;
}