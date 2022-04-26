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
bool dp[1001][2];
const int SK = 0, CY = 1;

void input() {
	cin >> N;
}

void solution() {
	dp[1][SK] = dp[3][SK] = true;
	dp[2][CY] = true;
	for (int i = 4; i <= N; i++) {
		dp[i][SK] = dp[i - 3][CY] || dp[i - 1][CY];
		dp[i][CY] = dp[i - 3][SK] || dp[i - 1][SK];
	}
	if (dp[N][SK]) cout << "CY";
	else cout << "SK";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}