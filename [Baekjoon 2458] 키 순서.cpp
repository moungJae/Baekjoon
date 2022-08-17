#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
vector<int> go[501], back[501];
bool visited[501];

void input() {
	int from, to;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		go[from].push_back(to);
		back[to].push_back(from);
	}
}

void init() {
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}

int straight_bfs(int start) {
	queue<int> Q;
	int cnt = 1;

	Q.push(start);
	visited[start] = true;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int next : go[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				Q.push(next);
				cnt++;
			}
		}
	}
	return cnt;
}

int reverse_bfs(int start) {
	queue<int> Q;
	int cnt = 1;

	Q.push(start);
	visited[start] = true;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int next : back[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				Q.push(next);
				cnt++;
			}
		}
	}
	return cnt;
}

void solution() {
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		init();
		if (straight_bfs(i) + reverse_bfs(i) == N + 1)
			ans++;
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}