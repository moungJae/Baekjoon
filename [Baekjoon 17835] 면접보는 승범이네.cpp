#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <string>

#define ll long long
#define INF 100000000
#define endl '\n'

using namespace std;

int N, M, K;
vector<pair<int, ll>> path[100001];
ll D[100001];

void input() {
	int U, V;
	ll C;

	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		cin >> U >> V >> C;
		path[V].push_back({ U, C });
	}
	for (int i = 1; i <= K; i++) {
		cin >> U;
		path[0].push_back({ U, 0 });
	}
}

void dijkstra() {
	priority_queue<pair<ll, int>> PQ;

	for (int i = 0; i <= N; i++)
		D[i] = 1e18;
	PQ.push({ 0, 0 });
	D[0] = 0;
	while (!PQ.empty()) {
		ll dist = -PQ.top().first;
		int cur = PQ.top().second;

		PQ.pop();
		if (dist > D[cur])
			continue;
		for (pair<int, ll> p : path[cur]) {
			int next = p.first;
			ll next_dist = dist + p.second;
			
			if (next_dist < D[next]) {
				D[next] = next_dist;
				PQ.push({ -next_dist, next });
			}
		}
	}
}

void solution() {
	ll dist = 0;

	dijkstra();
	for (int i = 1; i <= N; i++) {
		dist = max(dist, D[i]);
	}
	for (int i = 1; i <= N; i++) {
		if (dist == D[i]) {
			cout << i << endl << dist;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}