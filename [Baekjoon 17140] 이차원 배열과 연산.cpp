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

int arr[101][101];
int r, c, k;

void input()
{
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	}
}

bool compare(pair<int, int> x, pair<int, int> y)
{
	if (x.second == y.second)
		return x.first < y.first;
	return x.second < y.second;
}

void solution()
{
	int cnt = 0;
	for (int t = 0; t <= 100; t++)
	{
		if (arr[r][c] == k)
		{
			cout << t << endl; 
			return;
		}
		vector<pair<int, int>> r_v[101], c_v[101];
		map<int, int> r_m[101], c_m[101];
		int x = 0, y = 0;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				if (arr[i][j]) {
					x = max(x, i), y = max(y, j);
				}
				else continue;
				if (!r_m[i][arr[i][j]])
				{
					r_m[i][arr[i][j]] = 1;
					r_v[i].push_back({ arr[i][j], 1 });
				}
				else r_m[i][arr[i][j]]++;
				if (!c_m[j][arr[i][j]])
				{
					c_m[j][arr[i][j]] = 1;
					c_v[j].push_back({ arr[i][j], 1 });
				}
				else c_m[j][arr[i][j]]++;
			}
		}
		if (x >= y)
		{
			for (int i = 1; i <= 100; i++)
			{
				for (int j = 0; j < r_v[i].size(); j++)
				{
					r_v[i][j].second = r_m[i][r_v[i][j].first];
				}
			}
			for (int i = 1; i <= 100; i++)
			{
				if (r_v[i].size())
					sort(r_v[i].begin(), r_v[i].end(), compare);
			}
			for (int i = 1; i <= 100; i++)
			{
				int t = 1;
				for (int j = 0; j < r_v[i].size(); j++)
				{
					arr[i][t++] = r_v[i][j].first;
					arr[i][t++] = r_v[i][j].second;
					if (t > 100) break;
				}
				for (int j = t; j <= 100; j++)
					arr[i][j] = 0;
			}
		}
		else
		{
			for (int i = 1; i <= 100; i++)
			{
				for (int j = 0; j < c_v[i].size(); j++)
				{
					c_v[i][j].second = c_m[i][c_v[i][j].first];
				}
			}
			for (int i = 1; i <= 100; i++)
			{
				if (c_v[i].size())
					sort(c_v[i].begin(), c_v[i].end(), compare);
			}
			for (int i = 1; i <= 100; i++)
			{
				int t = 1;
				for (int j = 0; j < c_v[i].size(); j++)
				{
					arr[t++][i] = c_v[i][j].first;
					arr[t++][i] = c_v[i][j].second;
					if (t > 100) break;
				}
				for (int j = t; j <= 100; j++)
					arr[j][i] = 0;
			}
		}
		cnt++;
	}
	cout << -1 << endl;
}

int main()
{
	input();
	solution();

	return 0;
}