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
#include <list>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

bool maze[42][720];
const int END = 41;

void init() {
	for (int i = 0; i <= 41; i++) {
		for (int j = 0; j < 720; j++) {
			maze[i][j] = false;
		}
	}
}

void input() {
	int n;
	int t, r, theta1, theta2;
	int r1, r2, theta;
	char c;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'C') {
			cin >> r >> theta1 >> theta2;
			for (t = theta1; t != theta2; t = (t + 1) % 360) {
				maze[2 * r][2 * t] = true;
				maze[2 * r][2 * t + 1] = true;
			}
			maze[2 * r][2 * t] = true;
		}
		else if (c == 'S') {
			cin >> r1 >> r2 >> theta;
			for (r = r1; r < r2; r++) {
				maze[2 * r][2 * theta] = true;
				maze[2 * r + 1][2 * theta] = true;
			}
			maze[2 * r][2 * theta] = true;
		}
	}
}

void solution() {
	queue<pair<int, int>> Q;

	for (int theta = 0; theta < 720; theta++) {
		if (!maze[1][theta]) {
			Q.push({ 1, theta });
			maze[1][theta] = true;
		}
	}
	while (!Q.empty()) {
		int pos = Q.front().first;
		int theta = Q.front().second;

		Q.pop();
		if (pos == END) {
			cout << "YES" << endl;
			return;
		}
		int prev_theta = (theta + 719) % 720;
		int next_theta = (theta + 1) % 720;

		if ((pos - 1) && !maze[pos - 1][theta]) {
			Q.push({ pos - 1, theta });
			maze[pos - 1][theta] = true;
		}
		if (!maze[pos + 1][theta]) {
			Q.push({ pos + 1, theta });
			maze[pos + 1][theta] = true;
		}
		if (!maze[pos][prev_theta]) {
			Q.push({ pos, prev_theta });
			maze[pos][prev_theta] = true;
		}
		if (!maze[pos][next_theta]) {
			Q.push({ pos, next_theta });
			maze[pos][next_theta] = true;
		}
	}
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;

	cin >> t;
	while (t--) {
		init();
		input();
		solution();
	}

	return 0;
}