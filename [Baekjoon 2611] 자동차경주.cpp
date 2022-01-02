#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1000000000
#define endl '\n'

using namespace std;

int N, M;
vector<pair<int, int>> road[1001];
int inDegree[1001];
int dp[1001], parent[1001];

void input() {
	int p, q, r;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> p >> q >> r;
		road[p].push_back({ q,r });
		inDegree[q]++;
	}
}

void print_road(int x, int s) {
	if (x == s) {
		cout << x << " ";
		return;
	}
	print_road(parent[x], s);
	cout << x << " ";
}

void solution(int s) {
	int cur, next, tmp;
	queue<int> Q;
	
	Q.push(s);
	dp[s] = 0;
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();
		if (cur == s && inDegree[s] == 0) break;

		for (int i = 0; i < road[cur].size(); i++) {
			next = road[cur][i].first;
			if ((tmp = dp[cur] + road[cur][i].second) > dp[next]) {
				dp[next] = tmp;
				parent[next] = cur;
			}
			if (--inDegree[next] == 0) {
				Q.push(next);
			}
		}
	}

	cout << dp[s] << endl;
	print_road(parent[s], s);
	cout << s;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution(1);

	return 0;
}