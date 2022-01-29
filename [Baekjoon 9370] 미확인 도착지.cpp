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

int n, m, t;
int s, g, h;

vector<pair<int, int>> v[2001];
int Dist_S[2001], Dist_G[2001], Dist_H[2001];

void input() {
	int a, b, d;
	cin >> n >> m >> t;
	cin >> s >> g >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		v[a].push_back({ b,d });
		v[b].push_back({ a,d });
	}
}

void init() {
	for (int i = 0; i <= 2000; i++) {
		v[i].clear();
		Dist_S[i] = Dist_G[i] = Dist_H[i] = INF;
	}
}

void dijkstra(int start, int Dist[]) {
	priority_queue<pair<int, int>> PQ;
	PQ.push({ 0, start });
	Dist[start] = 0;
	while (!PQ.empty()) {
		int dist = -PQ.top().first, x = PQ.top().second;
		PQ.pop();
		if (dist > Dist[x]) continue;
		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i].first, next_dist = dist + v[x][i].second;
			if (next_dist < Dist[next]) {
				Dist[next] = next_dist;
				PQ.push({ -next_dist, next });
			}
		}
	}
}

void solution() {
	int x, intersect_distance;
	vector<int> result;

	dijkstra(s, Dist_S);
	dijkstra(g, Dist_G);
	intersect_distance = Dist_G[h];
	dijkstra(h, Dist_H);

	while (t--) {
		cin >> x;
		if (Dist_S[x] == Dist_S[g] + intersect_distance + Dist_H[x] ||
			Dist_S[x] == Dist_S[h] + intersect_distance + Dist_G[x])
			result.push_back(x);
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		init();
		input();
		solution();
	}

	return 0;
}