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

int N, M, K, L, P;
int S, E;
vector<pair<int, int>> path[10001], trap[10001][2];
bool is_trap[10001];
int D[10001][101];

void input() {
	int t, from, to, dist;
	
	cin >> N >> M >> K >> L >> P;
	for (int i = 1; i <= K; i++) {
		cin >> t;
		is_trap[t] = true;
	}
	for (int i = 1; i <= M - L; i++) {
		cin >> from >> to >> dist;
		path[from].push_back({ to, dist });
	}
	for (int i = 1; i <= L; i++) {
		cin >> from >> to >> dist;
		trap[from][0].push_back({ to, dist });
		trap[to][1].push_back({ from, dist });
	}
	cin >> S >> E;
}

void dijkstra() {
	priority_queue<pair<pair<int, int>, pair<int, int>>> PQ;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 100; j++) {
			D[i][j] = INF;
		}
	}
	PQ.push({ {0, S}, {0, 0} });
	D[S][0] = 0;
	while (!PQ.empty()) {
		int dist = -PQ.top().first.first, cur = PQ.top().first.second;
		int cnt = PQ.top().second.first, op = PQ.top().second.second;
		int tmp_cnt = cnt, tmp_op = op;
		PQ.pop();

		if (dist > D[cur][cnt]) 
			continue;
		for (pair<int, int> p : path[cur]) {
			int next = p.first, next_dist = dist + p.second;
			if (is_trap[next]) {
				cnt++;
				if (cnt % P == 0) op ^= 1;
			}
			if (next_dist < D[next][cnt]) {
				D[next][cnt] = next_dist;
				PQ.push({ {-next_dist, next}, {cnt, op} });
			}
			cnt = tmp_cnt, op = tmp_op;
		}
		for (pair<int, int> p : trap[cur][op]) {
			int next = p.first, next_dist = dist + p.second;
			if (is_trap[next]) {
				cnt++;
				if (cnt % P == 0) op ^= 1;
			}
			if (next_dist < D[next][cnt]) {
				D[next][cnt] = next_dist;
				PQ.push({ {-next_dist, next}, {cnt, op} });
			}
			cnt = tmp_cnt, op = tmp_op;
		}
	}
}

void solution() {
	int result = INF;

	dijkstra();
	for (int i = 0; i <= 100; i++) {
		result = min(result, D[E][i]);
	}
	cout << (result == INF ? -1 : result);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}