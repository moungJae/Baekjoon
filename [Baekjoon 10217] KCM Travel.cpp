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

class Info {
public :
	int next;
	int cost;
	int time;
};

int N, M, K;
vector<Info> path[101];
int D[101][10001];

void init() {
	for (int i = 1; i <= N; i++)
		path[i].clear();
}

void input() {
	int u, v, c, d;

	cin >> N >> M >> K;
	init();
	for (int i = 1; i <= K; i++) {
		cin >> u >> v >> c >> d;
		path[u].push_back({ v, c, d });
	}
}

void solution() {
	priority_queue<pair<pair<int, int>, int>> PQ;
	int start = 1, end = N;
	int t, cost, cur;
	int next_cost, next_time, next;
	int ans;

	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= M; j++)
			D[i][j] = INF;

	D[start][0] = 0;
	PQ.push({ {0, 0}, start });
	while (!PQ.empty()) {
		t = -PQ.top().first.first;
		cost = -PQ.top().first.second;
		cur = PQ.top().second;
		
		PQ.pop();
		if (D[cur][cost] > t) 
			continue;
		for (Info info : path[cur]) {
			next = info.next;
			next_cost = info.cost + cost;
			next_time = info.time + t;
			if (next_cost <= M && next_time < D[next][next_cost]) {
				D[next][next_cost] = next_time;
				PQ.push({ {-next_time, -next_cost}, next });
			}
		}
	}

	ans = INF;
	for (int i = 0; i <= M; i++) {
		ans = min(ans, D[end][i]);
	}
    
	if (ans == INF) cout << "Poor KCM" << endl;
	else cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		input();
		solution();
	}

	return 0;
}