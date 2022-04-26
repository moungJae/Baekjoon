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

int V, E, P;
vector<pair<int, int>> v[5001];
int D[5001][5001];

void input() {
	int a, b, c;
	cin >> V >> E >> P;
	for (int i = 1; i <= E; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
}

void dijkstra(int start) {
	priority_queue<pair<int, int>> PQ;

	for (int i = 1; i <= V; i++)
		D[start][i] = INF;

	D[start][start] = 0;
	PQ.push({ 0,start });
	while (!PQ.empty()) {
		int dist = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		if (dist > D[start][cur])
			continue;
		for (pair<int, int> p : v[cur]) {
			int next = p.first, next_dist = dist + p.second;
			if (next_dist < D[start][next]) {
				D[start][next] = next_dist;
				PQ.push({ -next_dist, next });
			}
		}
	}
}

void solution() {
	dijkstra(1);
	dijkstra(P);

	if (D[1][P] + D[P][V] == D[1][V])
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}