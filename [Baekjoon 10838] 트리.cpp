#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>

#define ll long long
#define INF 100000000
#define endl '\n'

using namespace std;

int N, K;
pair<int, int> parent[100001];

int get_lca(int a, int b) {
	vector<bool> visited(N + 1, false);

	for (int i = 0; i <= 1000; i++) {
		visited[a] = true;
		a = parent[a].first;
	}

	for (int i = 0; i <= 1000; i++) {
		if (visited[b])
			return b;
		b = parent[b].first;
	}
	return 0;
}

void paint(int a, int b, int c) {
	map<int, bool> visited;
	int lca;

	lca = get_lca(a, b);

	while (a != lca) {
		parent[a].second = c;
		a = parent[a].first;
	}
	while (b != lca) {
		parent[b].second = c;
		b = parent[b].first;
	}
}

void move(int a, int b) {
	parent[a].first = b;
}

int count(int a, int b) {
	map<int, bool> visited;
	int lca;
	int cnt = 0;

	lca = get_lca(a, b);

	while (a != lca) {
		if (!visited[parent[a].second]) {
			visited[parent[a].second] = true;
			cnt++;
		}
		a = parent[a].first;
	}
	while (b != lca) {
		if (!visited[parent[b].second]) {
			visited[parent[b].second] = true;
			cnt++;
		}
		b = parent[b].first;
	}

	return cnt;
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = { 0,0 };
	}
}

void solution() {
	int r, a, b, c;

	cin >> N >> K;
	init();
	while (K--) {
		cin >> r;
		if (r == 1) {
			cin >> a >> b >> c;
			paint(a, b, c);
		}
		else if (r == 2) {
			cin >> a >> b;
			move(a, b);
		}
		else if (r == 3) {
			cin >> a >> b;
			cout << count(a, b) << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	solution();

	return 0;
}