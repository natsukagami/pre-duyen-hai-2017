#include <bits/stdc++.h>
using namespace std;

int N;
long long X;

string pls(string a, string b) {
	int rem = 0;
	if (a.length() < b.length()) a.insert(0, b.length() - a.length(), '0');
	else b.insert(0, a.length() - b.length(), '0');
	for (int i = a.length() - 1; i >= 0; --i) {
		a[i] += b[i] - '0' + rem;
		if (a[i] > '9') rem = 1, a[i] -= 10;
		else rem = 0;
	}
	if (rem) a.insert(0, 1, '1');
	return a;
}

string s(long long x) {
	stringstream ss; ss << x; return ss.str();
}

int main() {
	cin >> N >> X;
	long long  k = 1;
	for (int i = 2; i <= N; ++i) k = k * 10 % X;
	k = (X - k) % X;

	string ans = pls("1" + string(N - 1, '0'), s(k));
	if (ans.length() > N) return cout << -1 << endl, 0;
	cout << ans << endl;
}