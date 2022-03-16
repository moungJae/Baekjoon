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

int N, M, K;
int Map[16][16];
int dp[16][16][2];

void input()
{
	cin >> N >> M >> K;
}

void solution()
{
	if (K == 0)
	{
		for (int i = 1; i <= N; i++)
			dp[i][1][0] = 1;
		for (int i = 1; i <= M; i++)
			dp[1][i][0] = 1;
		for (int i = 2; i <= N; i++)
		{
			for (int j = 2; j <= M; j++)
			{
				dp[i][j][0] = dp[i - 1][j][0] + dp[i][j - 1][0];
			}
		}
		cout << dp[N][M][0];
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (1 + M * (i - 1) == K)
				dp[i][1][1] = 1;
			else
				dp[i][1][0] = 1, dp[i][1][1] = dp[i - 1][1][1];
		}
		for (int i = 1; i <= M; i++)
		{
			if (i == K)
				dp[1][i][1] = 1;
			else
				dp[1][i][0] = 1, dp[1][i][1] = dp[1][i - 1][1];
		}
		for (int i = 2; i <= N; i++)
		{
			for (int j = 2; j <= M; j++)
			{
				if (M * (i - 1) + j == K)
					dp[i][j][1] = dp[i - 1][j][0] + dp[i][j - 1][0];
				else
				{
					dp[i][j][0] = dp[i - 1][j][0] + dp[i][j - 1][0];
					dp[i][j][1] = dp[i - 1][j][1] + dp[i][j - 1][1];
				}
			}
		}
		cout << dp[N][M][1];
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}