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
int L[21], J[21];
bool dp[101][2001][21];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> L[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> J[i];
	}
}

void dfs(int life, int joy, int idx, int &res) {
	if (life <= 0)
		return;
	res = max(res, joy);
	if (idx > N || dp[life][joy][idx])
		return;

	dp[life][joy][idx] = true;
	dfs(life - L[idx], joy + J[idx], idx + 1, res);
	dfs(life, joy, idx + 1, res);
}

void solution() {
	int result = 0;

	dfs(100, 0, 1, result);
	cout << result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}