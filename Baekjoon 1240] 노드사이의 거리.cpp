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
vector<pair<int, int>> v[1001];
bool visited[1001];

void input()
{
	int from, to, dist;
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
		v[to].push_back({ from, dist });
	}
}

void init()
{
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}

int dfs(int cur, int fin, int dist)
{
	int ret;

	if (cur == fin)
		return dist;
	if (visited[cur])
		return 0;
	visited[cur] = true;
	for (pair<int, int> p : v[cur])
	{
		if ((ret = dfs(p.first, fin, dist + p.second)))
			return ret;
	}
	return 0;
}

void solution()
{
	int x, y;

	while (M--)
	{
		cin >> x >> y;
		init();
		cout << dfs(x, y, 0) << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}