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
#include <set>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N;
int A[250];
int dp[250][250];
bool check[250][250];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
}

void solution() {
	int r;

	/* 1. base case */
	for (int i = 1; i <= N; i++) {
		dp[i][i] = A[i];
		check[i][i] = true;
	}

	/* 2. dynamic programming */
	for (int gap = 1; gap <= N - 1; gap++) {
		for (int l = 1; l <= N - gap; l++) {
			r = l + gap;
			for (int k = 0; k <= gap - 1; k++) {
				if (dp[l][l + k] == dp[l + k + 1][r]
					&& check[l][l + k] && check[l + k + 1][r]) {
					dp[l][r] = max(dp[l][r], dp[l][l + k] + 1);
					check[l][r] = true;
				}
				else dp[l][r] = max(dp[l][r], max(dp[l][l + k], dp[l + k + 1][r]));
			}
		}
	}

	/* 3. Find solution */
	cout << dp[1][N];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}