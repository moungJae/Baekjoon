#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N;
priority_queue<ll> PQ;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll x;
		cin >> x;
		PQ.push(-x);
	}
}

void solution() {
	ll x, y, result = 0;
	if (PQ.size() == 1) {
		cout << 0;
	}
	else {
		while (PQ.size() != 1) {
			x = -PQ.top(), PQ.pop();
			y = -PQ.top(), PQ.pop();
			result += (x + y);
			PQ.push(-(x + y));
		}
		cout << result;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}