#define _CRT_SECURE_NO_WARNINGS
#include <string>
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

int S;
bool dp[31][1112][1112];

void input() {
	cin >> S;
}

void solution() {
	dp[1][1][1] = true;
	for (int t = 2; t <= 30; t++) {
		for (int i = 1; i <= 1111; i++) {
			for (int j = 1; j <= i; j++) {
				dp[t][i][i] |= dp[t - 1][i][j]; // save
				dp[t][i][j] |= dp[t - 1][i - j][j]
					|| dp[t - 1][i + 1][j]; // put or delete
			}
		}
		for (int i = 1; i <= S; i++) {
			if (dp[t][S][i]) {
				cout << t;
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}