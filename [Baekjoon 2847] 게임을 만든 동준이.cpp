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

int N;
int X[101];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}
}

// 3 4 5 5 5
// 1 2 3 4 5

bool check_increase(int X[]) {
	for (int i = 1; i < N; i++) {
		if (X[i - 1] >= X[i])
			return false;
	}
	return true;
}

int make_increase(int X[]) {
	int ret = 0;
	for (int i = 1; i < N; i++) {
		if (X[i - 1] >= X[i]) {
			ret += (X[i - 1] - X[i] + 1);
			X[i - 1] = X[i] - 1;
		}
	}
	return ret;
}

void solution() {
	int cnt = 0;
	while (!check_increase(X)) {
		cnt += make_increase(X);
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}