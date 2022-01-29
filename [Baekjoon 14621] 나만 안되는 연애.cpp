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

int N, M;
int parent[1001];
char sex[1001];
vector<pair<pair<int, int>, int>> V;

void input() {
	int u, v, d;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> sex[i];
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> d;
		V.push_back({ {u,v}, d });
	}
}

bool compare(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
	return x.second < y.second;
}

int get_parent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = get_parent(parent[x]);
}

void Union(int x, int y) {
	x = get_parent(x), y = get_parent(y);
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

void init() {
	for (int i = 1; i <= N; i++)
		parent[i] = i;
}

void solution() {
	int result = 0, op = 0;
	init();
	sort(V.begin(), V.end(), compare);
	for (int i = 0; i < V.size(); i++) {
		int x = V[i].first.first, y = V[i].first.second;
		int dist = V[i].second;
		if ((sex[x] != sex[y]) && (get_parent(x) != get_parent(y))) {
			Union(x, y);
			result += dist;
			op++;
		}
	}
	
	if (op == N - 1) cout << result;
	else cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}