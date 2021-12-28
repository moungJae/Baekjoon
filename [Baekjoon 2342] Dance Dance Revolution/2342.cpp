#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

#define INF 1000000000
#define endl '\n'

using namespace std;

int position[100001];
int dp[5][5][100001];

bool point1(int before, int cur) {
	return before == cur && cur != 0;
}

bool point2(int before, int cur) {
	return before == 0 && cur;
}

bool point3(int before, int cur) {
	if (before % 2) return cur % 2 == 0;
	return cur % 2 != 0;
}

void setPoint(int before, int cur, int& point) {
	if (point1(before, cur)) point = 1;
	else if (point2(before, cur)) point = 2;
	else if (point3(before, cur)) point = 3;
	else point = 4;
}

void solution(int n) {
	int i, left, right, point_right, point_left;
	
	for (left = 0; left <= 4; left++) {
		for (right = 0; right <= 4; right++) {
			if (left == 0 && right == 0) continue;
			dp[left][right][0] = INF;
		}
	}

	for (i = 1; i <= n; i++) {
		for (left = 0; left <= 4; left++) 
			for (right = 0; right <= 4; right++) 
				dp[left][right][i] = INF;
		for (left = 0; left <= 4; left++) {
			for (right = 0; right <= 4; right++) {
				if (dp[left][right][i - 1] == INF) continue;
				setPoint(left, position[i], point_left);
				setPoint(right, position[i], point_right);
				dp[left][position[i]][i] = min({ dp[left][position[i]][i],
					dp[left][right][i - 1] + point_right});
				dp[position[i]][right][i] = min({ dp[position[i]][right][i],
					dp[left][right][i - 1] + point_left });
			}
		}
	}

	int result = INF;
	for (left = 0; left <= 4; left++) {
		for (right = 0; right <= 4; right++) {
			if (left == right) continue;
			result = min(result, dp[left][right][n]);
		}
	}

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int x, n;
	n = 0;
	while (1) {
		cin >> x;
		if (x == 0) break;
		position[++n] = x;
	}
	solution(n);

	return 0;
}