#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>

#define ll long long

using namespace std;

int R, C, P;
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
int eval[501][501];
int point[250001], parent[250001], check[250001];

void input()
{
	int cnt = 0;

	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> eval[i][j];
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> point[++cnt];
			if (point[cnt])
				P++;
		}
	}
}

int get_vertex(int x, int y)
{
	return ((x - 1) * C + y);
}

bool compare(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y)
{
	return (x.first < y.first);
}

void set_info(vector<pair<int, pair<int, int>>>& info)
{
	for (int x = 1; x <= R; x++)
	{
		for (int y = 1; y <= C; y++)
		{
			for (int i = 0; i < 2; i++)
			{
				int next_x = x + dx[i], next_y = y + dy[i];
				if (next_x >= 1 && next_x <= R && next_y >= 1 && next_y <= C)
				{
					int dist = abs(eval[next_x][next_y] - eval[x][y]);
					info.push_back({ dist, {get_vertex(x, y), get_vertex(next_x, next_y)} });
				}
			}
		}
	}
	sort(info.begin(), info.end(), compare);
}

void set_parent(int parent[])
{
	for (int i = 1; i <= R * C; i++)
	{
		if (point[i]) parent[i] = 0;
		else parent[i] = i;
	}
}

void set_check(int check[])
{
	for (int i = 1; i <= R * C; i++)
		check[i] = i;
}

int get_parent(int x, int parent[])
{
	if (x == parent[x])
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
	vector<pair<int, pair<int, int>>> info;
	int D = 0, connect = 0;
	int from, to, dist, from_parent, to_parent;
	int from_check, to_check;

	set_info(info);
	set_parent(parent);
	set_check(check);
	for (int i = 0; i < info.size(); i++)
	{
		from = info[i].second.first, to = info[i].second.second, dist = info[i].first;
		from_parent = get_parent(from, parent), to_parent = get_parent(to, parent);
		from_check = get_parent(from, check), to_check = get_parent(to, check);
		if (from_parent != to_parent)
		{
			go_union(from, to, parent);
			go_union(from, to, check);
		}
		else if(from_parent == 0 && to_parent == 0)
		{
			if (from_check != to_check)
			{
				go_union(from, to, check);
				connect++;
			}
		}
		D = max(D, dist);
		if (connect == P - 1)
			break;
	}
	cout << D;
}

int main()
{
	input();
	solution();

	return 0;
}