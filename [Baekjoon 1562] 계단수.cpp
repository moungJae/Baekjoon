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

int N;
int dp[101][10][1024];

void input() {
	cin >> N;
}

void solution() {
	int mod = 1000000000;

	for (int i = 1; i <= 9; i++) {
		dp[1][i][(1 << i)] = 1;
	}

	for (int d = 2; d <= N; d++) {
		for (int i = 0; i <= 9; i++) {
			for (int bit = 0; bit < (1 << 10); bit++) {
				if (i == 0) {
					dp[d][0][bit | 1] 
						= (dp[d][0][bit | 1] + dp[d - 1][1][bit]) % mod;
				}
				else if (i == 9) {
					dp[d][9][bit | (1 << 9)] 
						= (dp[d][9][bit | (1 << 9)] + dp[d - 1][8][bit]) % mod;
				}
				else {
					dp[d][i][bit | (1 << i)]
						= (dp[d][i][bit | (1 << i)] + dp[d - 1][i - 1][bit]) % mod;
					dp[d][i][bit | (1 << i)]
						= (dp[d][i][bit | (1 << i)] + dp[d - 1][i + 1][bit]) % mod;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i <= 9; i++) {
		ans = (ans + dp[N][i][1023]) % mod;
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}