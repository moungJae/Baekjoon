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

int N, M, T;
vector<pair<pair<int, int>, int>> path;
int parent[10001];

void input() {
	int A, B, C;

	cin >> N >> M >> T;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		path.push_back({ {A,B},C });
	}
}

bool compare(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
	return x.second < y.second;
}

int get_parent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = get_parent(parent[x]);
}

void union_operation(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

void solution() {
	int answer = 0;
	int mst = 0, t = 0;
	
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	sort(path.begin(), path.end(), compare);
	for (int i = 0; i < path.size(); i++) {
		int from = path[i].first.first;
		int to = path[i].first.second;
		int cost = path[i].second;

		if (get_parent(from) != get_parent(to)) {
			union_operation(from, to);
			answer += (cost + (t++) * T);
		}
		if (mst == N - 1)
			break;
	}

	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}