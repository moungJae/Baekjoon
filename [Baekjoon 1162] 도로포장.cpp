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

int N, M, K;
vector<pair<int, int>> v[10001];
ll D[10001][21];

void input() {
	int from, to;
	ll dist;

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
		v[to].push_back({ from, dist });
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			D[i][j] = 1e18;
		}
	}
}

void dijkstra(int start) {
	priority_queue<pair<pair<ll, int>, int>> PQ;

	init();
	PQ.push({ {0, start}, 0 });
	D[start][0] = 0;
	while (!PQ.empty()) {
		ll cur_dist = -PQ.top().first.first;
		int cur = PQ.top().first.second;
		int cur_pave = -PQ.top().second;

		PQ.pop();
		if (D[cur][cur_pave] < cur_dist)
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			ll next_dist = cur_dist + v[cur][i].second;

			// 포장도로를 안 깔은 경우
			if (next_dist < D[next][cur_pave]) {
				D[next][cur_pave] = next_dist;
				PQ.push({ {-next_dist, next}, -cur_pave });
			}
			// 포장도로를 깐 경우
			if (cur_pave + 1 <= K && cur_dist < D[next][cur_pave + 1]) {
				D[next][cur_pave + 1] = cur_dist;
				PQ.push({ {-cur_dist, next}, -(cur_pave + 1) });
			}
		}
	}
}

void solution() {
	ll ans = 1e18;

	dijkstra(1);
	for (int i = 0; i <= K; i++) {
		ans = min(ans, D[N][i]);
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}