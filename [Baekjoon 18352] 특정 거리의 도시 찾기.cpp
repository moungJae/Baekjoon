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

int N, M, K, X;
int Dist[300001];
vector<int> v[300001];

void input() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}
}

void solution() {
	priority_queue<pair<int, int>> PQ;
	bool ok = false;

	for (int i = 1; i <= N; i++) Dist[i] = INF;
	PQ.push({ 0, X });
	Dist[X] = 0;

	while (!PQ.empty()) {
		int dist = -PQ.top().first, x = PQ.top().second;
		PQ.pop();

		if (dist < Dist[x]) continue;
		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i];
			if (dist + 1 < Dist[next]) {
				Dist[next] = dist + 1;
				PQ.push({ -Dist[next], next });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (Dist[i] == K) {
			ok = true;
			cout << i << endl;
		}
	}

	if (!ok) cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}