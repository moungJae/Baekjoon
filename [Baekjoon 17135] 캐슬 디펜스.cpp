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

int N, M, D;
int Map[17][17], tmp[17][17];

void input()
{
	cin >> N >> M >> D;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> Map[i][j];
}

void map_cpy(int dst[][17], int src[][17])
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			dst[i][j] = src[i][j];
}

bool compare(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y)
{
	if (x.first == y.first)
		return x.second.second < y.second.second;
	return x.first < y.first;
}

int play()
{
	int ret, idx, step;
	int players[3], check[3];

	idx = 0;
	for (int i = 1; i <= M; i++)
		if (Map[N + 1][i])
			players[idx++] = i;

	ret = step = 0;
	idx = N;
	while (idx)
	{
		vector<pair<int, pair<int, int>>> enemy_kill[3];
		for (int i = idx; i >= 1; i--)
		{
			for (int j = 1; j <= M; j++)
			{
				if (Map[i][j])
				{
					for (int k = 0; k < 3; k++)
					{
						if (abs(N + 1 - i - step) + abs(players[k] - j) <= D)
							enemy_kill[k].push_back({ abs(N + 1 - i - step) + abs(players[k] - j) , {i, j} });
					}
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if(enemy_kill[i].size())
				sort(enemy_kill[i].begin(), enemy_kill[i].end(), compare);
		}
		for (int i = 0; i < 3; i++)
		{
			if (enemy_kill[i].size())
			{
				int x = enemy_kill[i][0].second.first, y = enemy_kill[i][0].second.second;
				if (Map[x][y])
				{
					Map[x][y] = 0;
					ret++;
				}
			}
		}

		idx--, step++;
	}

	return ret;
}

int dfs(int n)
{
	int ret = 0;

	if (n == 4)
	{
		map_cpy(tmp, Map);
		ret = play();
		map_cpy(Map, tmp);
		return ret;
	}
	for (int i = 1; i <= M; i++)
	{
		if (Map[N + 1][i])
			continue;
		Map[N + 1][i] = 1;
		ret = max(ret, dfs(n + 1));
		Map[N + 1][i] = 0;
	}
	return ret;
}

void solution()
{
	cout << dfs(1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}