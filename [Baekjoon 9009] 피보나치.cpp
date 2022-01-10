#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

ll fibo[45];
bool op;

void set_fibonacci() {
	fibo[0] = 0, fibo[1] = 1;
	for (int i = 2; i < 45; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
}

void solution(ll n, stack<int> S) {
	if (op) return;
	for (int i = 44; i > 0; i--) {
		if (fibo[i] == n && !op) {
			op = true;
			cout << fibo[i] << " ";
			while (!S.empty()) {
				cout << S.top() << " ";
				S.pop();
			}
			cout << endl;
			return;
		}
		else if (fibo[i] < n) {
			S.push(fibo[i]);
			solution(n - fibo[i], S);
			S.pop();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;

	ll n;
	cin >> t;
	set_fibonacci();
	while (t--) {
		stack<int> S;
		cin >> n;
		op = false;
		solution(n, S);
	}
	
	return 0;
}