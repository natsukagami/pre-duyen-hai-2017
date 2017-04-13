#include <bits/stdc++.h>
using namespace std;

int N, K;
char A[1000005];
queue<int> S[10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	int st = 1, left = N - K;
	if (A[1] == '-' && K) {
		st = 2; 
	}
	if (!K) {
		for (int i = st; i <= N; ++i) putchar(A[i]); putchar('\n');
		return 0;
	}
	for (int i = st; i <= N; ++i) S[A[i] - '0'].push(i);
	for (int i = 1; i <= left; ++i) {
		int f = -1;
		for (int dig = 9; dig >= 0 && f < 0; --dig) {
			while (S[dig].size() && S[dig].front() < st) S[dig].pop();
			if (S[dig].size() && N - S[dig].front() >= left - i) f = S[dig].front();
		}
		putchar(A[f]);
		st = f + 1;
	}
	putchar('\n');
}