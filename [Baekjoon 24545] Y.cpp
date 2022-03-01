#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

#define INF 1000000000
#define endl '\n'

using namespace std;

int N;
vector<int> v[100001];
bool visited[100001];

void input()
{
	int a, b;
	
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void init()
{
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}

void dfs(int cur, int level, vector<pair<int, int>> &info)
{	
	if (visited[cur])
		return;
	if (v[cur].size() == 1 && level > 1)
		info.push_back({ cur, level });
	visited[cur] = true;
	for (int next : v[cur])
	{
		dfs(next, level + 1, info);
	}
}

void dfs_other(int cur, int level, vector<pair<int, int>>& info)
{
	if (visited[cur])
		return;
	if (v[cur].size() == 1)
		info.push_back({ cur, level });
	visited[cur] = true;
	for (int next : v[cur])
	{
		dfs_other(next, level + 1, info);
	}
}

bool checking(int cur, int before, int start, int end)
{
	if (v[cur].size() == 1 && cur == end)
	{
		visited[cur] = true;
		return true;
	}

	for (int next : v[cur])
	{
		if (next == before)
			continue;
		if (checking(next, cur, start, end))
		{
			visited[cur] = true;
			return true;
		}
	}
	return false;
}

void go(int cur, int before, vector<pair<int, int>>& info)
{
	if (v[cur].size() == 1 && before != -1)
		return;
	for (int next : v[cur])
	{
		if (next == before)
			continue;
		if (visited[next])
			go(next, cur, info);
		else
			dfs_other(next, 1, info);
	}
}

bool compare(pair<int, int> x, pair<int, int> y)
{
	return x.second > y.second;
}

bool is_Y()
{
	for (int i = 1; i <= N; i++)
	{
		if (v[i].size() >= 3)
			return true;
	}
	return false;
}

void solution() {
	vector<pair<int, int>> info;
	int s, e, dist;

	if (!is_Y())
	{
		cout << 0;
		return;
	}

	dfs(1, 1, info);
	sort(info.begin(), info.end(), compare);
	s = info[0].first;

	info.clear(), init();
	dfs(s, 1, info);
	sort(info.begin(), info.end(), compare);
	e = info[0].first, dist = info[0].second;

	info.clear(), init();
	checking(s, -1, s, e);	
	go(s, -1, info);
	sort(info.begin(), info.end(), compare);
	
	cout << (dist + info[0].second);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();
	
	return 0;
}