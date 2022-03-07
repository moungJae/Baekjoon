#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>

#define ll long long

using namespace std;

int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int pixel[200][200];
int dist[200][200];
bool visited[200][200];

void input()
{
	string s;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
			pixel[i][j] = (s[j] - '0');
	}
}

void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!pixel[i][j]) dist[i][j] = 1e9;
		}
	}
}

bool all_one()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!pixel[i][j])
				return false;
		}
	}
	return true;
}

void solution()
{
	init();
	while (!all_one())
	{
		vector<pair<int, int>> v;
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				if (pixel[x][y])
				{
					for (int k = 0; k < 4; k++)
					{
						int next_x = x + dx[k], next_y = y + dy[k];
						if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m
							&& !pixel[next_x][next_y])
						{
							dist[next_x][next_y] = min(dist[next_x][next_y], dist[x][y] + 1);
							v.push_back({ next_x, next_y });
						}
					}
				}
			}
		}
		for (int i = 0; i < v.size(); i++)
			pixel[v[i].first][v[i].second] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	input();
	solution();

	return 0;
}