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

int N, M, low, high;
vector<pair<int, int>> v[100001];
bool visited[100001];

void input() {
	int A, B, C;
	cin >> N >> M;
	low = INF, high = 0;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
		v[B].push_back({ A,C });
		low = min(low, C), high = max(high, C);
	}
}

void init() {
	for (int i = 1; i <= N; i++) 
		visited[i] = false;
}

bool bfs(int start, int end, int weight) {
	queue<int> Q;
	Q.push(start);
	visited[start] = true;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		if (x == end) return true;

		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i].first, w = v[x][i].second;
			if (!visited[next] && weight <= w) {
				visited[next] = true;
				Q.push(next);
			}
		}
	}
	return false;
}

void solution() {
	int from, to, result;
	cin >> from >> to;

	result = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		init();
		if (bfs(from, to, mid)) {
			result = max(result, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
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