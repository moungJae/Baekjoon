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
#include <set>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
int s, e;
vector<pair<pair<int, int>, int>> path;
vector<pair<int, int>> v[100001];
int parent[100001];
int ans;

void input() {
	int from, to, weight;

	cin >> N >> M;
	cin >> s >> e;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> weight;
		path.push_back({ {from, to}, weight });
	}
}

bool compare(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
	return x.second > y.second;
}

int get_parent(int x) {
	if (parent[x] == x)
		return x;
	return (parent[x] = get_parent(parent[x]));
}

void go_union(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

void set_path() {
	int edge = 0;

	for (int i = 1; i <= N; i++)
		parent[i] = i;
	sort(path.begin(), path.end(), compare);
	for (int i = 0; i < path.size(); i++) {
		int from = path[i].first.first;
		int to = path[i].first.second;
		int weight = path[i].second;

		if (get_parent(from) != get_parent(to)) {
			go_union(from, to);
			edge++;
			v[from].push_back({ to, weight });
			v[to].push_back({ from, weight });
		}
		if (edge == N - 1)
			break;
	}
}

void dfs(int cur, int before, int cur_w) {
	if (cur == e) {
		ans = cur_w;
		return;
	}

	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i].first;
		int next_w = v[cur][i].second;
		
		if (next == before) continue;
		dfs(next, cur, min(cur_w, next_w));
	}
}

void solution() {
	set_path();
	dfs(s, -1, INF);
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}