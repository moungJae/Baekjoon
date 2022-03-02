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

vector<pair<int, int>> v;
vector<pair<ll, pair<int, int>>> pipe;
int N, C;
int parent[4000001];

void input()
{
	int x, y;

	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		v.push_back({ x, y });
	}
}

bool compare(pair<ll, pair<int, int>> x, pair<ll, pair<int, int>> y)
{
	return x.first < y.first;
}

void set_pipe()
{
	ll cost;
	int x_1, y_1, x_2, y_2;

	for (int i = 0; i < N - 1; i++)
	{
		x_1 = v[i].first, y_1 = v[i].second;
		for (int j = i + 1; j < N; j++)
		{
			x_2 = v[j].first, y_2 = v[j].second;
			cost = (ll)((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
			pipe.push_back({ cost, {i + 1, j + 1} });
		}
	}
	sort(pipe.begin(), pipe.end());
}

void init()
{
	int end = ((N - 1) * N) / 2;
	for (int i = 1; i <= end; i++)
		parent[i] = i;
}

int get_parent(int x, int parent[])
{
	if (parent[x] == x)
		return x;
	return (parent[x] = get_parent(parent[x], parent));
}

void go_union(int x, int y, int parent[])
{
	x = get_parent(x, parent);
	y = get_parent(y, parent);
	if (x > y)
		parent[x] = y;
	else
		parent[y] = x;
}

void solution() 
{
	ll total = 0;
	int cnt = 0;

	set_pipe();
	init();
	for (int i = 0; i < pipe.size(); i++)
	{
		ll cost = pipe[i].first;
		int from = pipe[i].second.first, to = pipe[i].second.second;
		if (cost >= C && get_parent(from, parent) != get_parent(to, parent))
		{
			total += cost, cnt++;
			go_union(from, to, parent);
		}
		if (cnt == N - 1)
			break;
	}
	if (cnt == N - 1)
		cout << total;
	else
		cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}