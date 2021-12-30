#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

#define INF 1000000000
#define endl '\n'

using namespace std;

int n, m;
int dist[1001], before[1001];
vector<pair<int, int>> v[1001];

void input() {
	int A, B, C;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
		v[B].push_back({ A,C });
	}
}

void dijkstra(int s) {
	priority_queue<pair<int, int>> PQ;
	int cur, next, d, next_d, e, cnt;
	
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0;
	PQ.push({ -dist[s], s });
	
	while (!PQ.empty()) {
		d = -PQ.top().first, cur = PQ.top().second;
		PQ.pop();
		if (d > dist[cur]) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			next = v[cur][i].first, next_d = v[cur][i].second + d;
			if (next_d < dist[next]) {
				dist[next] = next_d;
				before[next] = cur;
				PQ.push({ -dist[next], next });
			}
		}
	}

	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (before[i]) cnt++;
	}

	cout << cnt << endl;
	for (int i = 1; i <= n; i++) {
		if (before[i]) cout << before[i] << " " << i << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	dijkstra(1); // 슈퍼 컴퓨터 1번

	return 0;
}