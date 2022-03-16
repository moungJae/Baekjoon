#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>
#include <string>
#include <map>

#define ll long long

using namespace std;

int N, M;
int coin[21];
int dp[10001];

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> coin[i];
	cin >> M;
}

void solution()
{
	// base case 
	for (int i = 1; i <= M; i++)
		dp[i] = 0;
	dp[0] = 1;
	for (int i = coin[1]; i <= M; i += coin[1])
		dp[i] += dp[i - coin[1]];

	// dynamic programming
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j >= coin[i])
				dp[j] += dp[j - coin[i]];
		}
	}

	// find the solution
	cout << dp[M] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		input();
		solution();
	}

	return 0;
}