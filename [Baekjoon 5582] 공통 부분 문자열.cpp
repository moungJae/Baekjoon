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

string s1, s2;
int dp[4001][4001];

void input() {
	cin >> s1 >> s2;
}

void solution() {
	int n, m, ans = 0;
	
	n = s1.size(), m = s2.size();
	// base case
	for (int i = 1; i <= m; i++) {
		if (s1[0] == s2[i - 1])
			dp[1][i] = 1;
		ans = max(ans, dp[1][i]);
	}
	for (int i = 1; i <= n; i++) {
		if (s1[i - 1] == s2[0])
			dp[i][1] = 1;
		ans = max(ans, dp[i][1]);
	}
	// dynamic programming
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				if (s1[i - 2] == s2[j - 2]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = 1;
				}
			}
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}