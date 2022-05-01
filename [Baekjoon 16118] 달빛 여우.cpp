#define _CRT_SECURE_NO_WARNINGS
#include <string>
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
vector<pair<int, ll>> v[4001];
ll D_f[4001], D_w[4001][2];

void input() {
	int a, b;
	ll d;

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> d;
		v[a].push_back({ b,2 * d });
		v[b].push_back({ a, 2 * d });
	}
}

void dijkstra_fox(int start) {
	priority_queue<pair<int, ll>> PQ;

	for (int i = 1; i <= N; i++) {
		D_f[i] = 1e18;
	}
	PQ.push({ 0, start });
	D_f[start] = 0;
	while (!PQ.empty()) {
		ll dist = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		if (dist > D_f[cur])
			continue;
		for (pair<int, ll> p : v[cur]) {
			int next = p.first;
			ll next_dist = p.second + dist;
			if (next_dist < D_f[next]) {
				D_f[next] = next_dist;
				PQ.push({ -next_dist, next });
			}
		}
	}
}

void dijkstra_wolf(int start) {
	priority_queue<pair<pair<int, ll>, int>> PQ;

	for (int i = 1; i <= N; i++) {
		D_w[i][0] = D_w[i][1] = 1e18;
	}
	PQ.push({ { 0, start }, 0 });
	D_w[start][0] = 0;
	while (!PQ.empty()) {
		ll dist = -PQ.top().first.first;
		int cur = PQ.top().first.second, op = PQ.top().second;
		PQ.pop();

		if (dist > D_w[cur][op])
			continue;
		for (pair<int, ll> p : v[cur]) {
			int next = p.first;
			ll next_dist;
			if (op == 0) next_dist = dist + p.second / 2;
			else next_dist = dist + p.second * 2;
			if (next_dist < D_w[next][op ^ 1]) {
				D_w[next][op ^ 1] = next_dist;
				PQ.push({ {-next_dist, next}, op ^ 1 });
			}
		}
	}
}

void solution() {
	int cnt = 0;

	dijkstra_fox(1);
	dijkstra_wolf(1);
	for (int i = 2; i <= N; i++) {
		if (D_f[i] < min(D_w[i][0], D_w[i][1]))
			cnt++;
	}
	cout << cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}