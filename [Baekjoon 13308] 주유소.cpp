#define _CRT_SECURE_NO_WARNINGS
#include <string>
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
ll oil[2501];
vector<pair<int, ll>> path[2501];
ll cost[2501][2501];

void input() {
	int from, to;
	ll dist;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> oil[i];
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> dist;
		path[from].push_back({ to,dist });
		path[to].push_back({ from, dist });
	}
}

void dijkstra(int start) {
	priority_queue<pair<pair<ll, ll>, int>> PQ;

	cost[start][oil[start]] = 0;
	PQ.push({ {0,-oil[start]}, start });
	while (!PQ.empty()) {
		ll cur_cost = -PQ.top().first.first;
		ll cur_oil = -PQ.top().first.second;
		int cur = PQ.top().second;

		PQ.pop();
		if (cur_cost > cost[cur][cur_oil])
			continue;
		for (int i = 0; i < path[cur].size(); i++) {
			int next = path[cur][i].first;
			ll next_cost = cur_cost + cur_oil * path[cur][i].second;
			ll next_oil = min(cur_oil, oil[next]);

			if (next_cost < cost[next][next_oil]) {
				cost[next][next_oil] = next_cost;
				PQ.push({ {-next_cost, -next_oil}, next });
			}
		}
	}
}

void solution() {
	ll ans = 1e18;

	fill(cost[1], cost[N + 1], 1e18);
	dijkstra(1);
	for (int i = 0; i <= 2500; i++) {
		ans = min(ans, cost[N][i]);
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}