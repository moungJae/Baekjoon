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

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

vector<pair<int, int>> v[5001];
int N, Q;
bool visited[5001];

void input()
{
	int p, q, r;

	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> p >> q >> r;
		v[p].push_back({ q,r });
		v[q].push_back({ p,r });
	}
}

void init()
{
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}

int dfs(int k, int cur, int rec)
{
	if (visited[cur])
		return 0;
	visited[cur] = true;

	int cnt;
	if (rec == (1e9 + 1)) 
		cnt = 0;
	else 
		cnt = (rec >= k ? 1 : 0);
	for (int i = 0; i < v[cur].size(); i++)
	{
		int next = v[cur][i].first, info = v[cur][i].second;
		cnt += dfs(k, next, min(rec, info));
	}
	return cnt;
}

void solution() 
{
	int k, x;

	while (Q--)
	{
		init();
		cin >> k >> x;
		cout << dfs(k, x, 1e9 + 1) << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}