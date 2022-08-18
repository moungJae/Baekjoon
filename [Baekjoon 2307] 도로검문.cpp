#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
vector<pair<int, int>> v[1001];
int D[1001];
bool path[1001][1001];
int parent[1001];

void input() {
	int from, to, dist;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
		v[to].push_back({ from, dist });
		path[from][to] = path[to][from] = true;
	}
}

void dijkstra(int start) {
	priority_queue<pair<int, int>> PQ;

	for (int i = 1; i <= N; i++)
		D[i] = INF;

	PQ.push({0, start});
	D[start] = 0;
	parent[start] = 0;
	while (!PQ.empty()) {
		int cur_dist = -PQ.top().first;
		int cur = PQ.top().second;

		PQ.pop();
		if (D[cur] < cur_dist)
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_dist = cur_dist + v[cur][i].second;

			if (next_dist < D[next]) {
				parent[next] = cur;
				D[next] = next_dist;
				PQ.push({ -next_dist, next });
			}
		}
	}
}

void new_dijkstra(int start) {
	priority_queue<pair<int, int>> PQ;

	for (int i = 1; i <= N; i++)
		D[i] = INF;

	PQ.push({ 0, start });
	D[start] = 0;
	while (!PQ.empty()) {
		int cur_dist = -PQ.top().first;
		int cur = PQ.top().second;

		PQ.pop();
		if (D[cur] < cur_dist)
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_dist = cur_dist + v[cur][i].second;

			if (path[cur][next] && next_dist < D[next]) {
				D[next] = next_dist;
				PQ.push({ -next_dist, next });
			}
		}
	}
}

void solution() {
	int no_trap, yes_trap;
	int cur, next;

	dijkstra(1);
	no_trap = D[N], yes_trap = 0;
	cur = N;
	while ((next = parent[cur]) != 0) {
		path[cur][next] = path[next][cur] = false;
		new_dijkstra(1);
		path[cur][next] = path[next][cur] = true;
		yes_trap = max(yes_trap, D[N]);
		cur = next;
	}

	if (yes_trap == INF)
		cout << -1;
	else
		cout << (yes_trap - no_trap);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}