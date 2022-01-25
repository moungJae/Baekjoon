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

int n, m, k;
vector<pair<int, int>> v[1001];
priority_queue<int> heap[1001];

void input() {
	int a, b, c;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
}

void solution() {
	priority_queue<pair<int, int>> PQ;
	PQ.push({ 0, 1 }), heap[1].push(0);
	while (!PQ.empty()) {
		int dist = -PQ.top().first, x = PQ.top().second;
		PQ.pop();
		
		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i].first, next_dist = dist + v[x][i].second;
			if (heap[next].size() < k) {
				heap[next].push(next_dist);
				PQ.push({ -next_dist, next });
			}
			else if (heap[next].top() > next_dist) {
				heap[next].pop();
				heap[next].push(next_dist);
				PQ.push({ -next_dist, next });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (heap[i].size() != k) cout << -1 << endl;
		else cout << heap[i].top() << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}