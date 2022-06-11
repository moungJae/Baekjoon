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
int D[1001], track[1001];
vector<pair<int, int>> v[1001];

void input() {
	int x, y, dist;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> dist;
		v[x].push_back({ y,dist });
		v[y].push_back({ x, dist });
	}
}

void dijkstra() {
	priority_queue<pair<int, int>> PQ;

	for (int i = 1; i <= N; i++)
		D[i] = INF;

	PQ.push({ 0, 1 });
	while (!PQ.empty()) {
		int dist = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		if (dist > D[cur])
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_dist = dist + v[cur][i].second;
			if (next_dist < D[next]) {
				D[next] = next_dist;
				track[next] = cur;
				PQ.push({ -next_dist, next });
			}
		}
	}
}

int new_dijkstra(int child, int parent) {
	priority_queue<pair<int, int>> PQ;

	for (int i = 1; i <= N; i++)
		D[i] = INF;

	PQ.push({ 0, 1 });
	while (!PQ.empty()) {
		int dist = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		if (dist > D[cur])
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_dist = dist + v[cur][i].second;
			
			if ((cur == child && next == parent) || (cur == parent && next == child))
				continue;
			if (next_dist < D[next]) {
				D[next] = next_dist;
				PQ.push({ -next_dist, next });
			}
		}
	}
	return D[N];
}

void solution() {
	int x = N;
	int result = 0;

	dijkstra();
	while (x != 1) {
		result = max(result, new_dijkstra(track[x], x));
		x = track[x];
	}
	cout << result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}