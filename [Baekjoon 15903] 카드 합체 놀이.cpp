#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

priority_queue<ll> PQ;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	ll a, x, y, tmp, score;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		PQ.push(-a);
	}

	while (m--) {
		x = -PQ.top(), PQ.pop();
		y = -PQ.top(), PQ.pop();
		tmp = x + y;
		x = tmp, y = tmp;
		PQ.push(-x), PQ.push(-y);
	}

	score = 0;
	while (!PQ.empty()) {
		score += (-PQ.top());
		PQ.pop();
	}
	cout << score;

	return 0;
}