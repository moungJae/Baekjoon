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

int N;
ll cost[1001][1001];
int parent[1001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> cost[i][j];
		}
	}
}

int get_parent(int x, int parent[]) {
	if (x == parent[x])
		return x;
	return (parent[x] = get_parent(parent[x], parent));
}

void go_union(int x, int y, int parent[]) {
	x = get_parent(x, parent);
	y = get_parent(y, parent);
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

bool compare(pair<pair<int, int>, ll> x, pair<pair<int, int>, ll> y) {
	return x.second < y.second;
}

void solution() {
	vector<pair<pair<int, int>, ll>> info;
	int connected = 0;
	ll result = 0;
	
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			info.push_back({ {i, j}, cost[i][j] });
		}
	}
	sort(info.begin(), info.end(), compare);
	for (int i = 0; connected != N - 1; i++) {
		int x = info[i].first.first, y = info[i].first.second;
		ll c = info[i].second;

		if (get_parent(x, parent) != get_parent(y, parent)) {
			go_union(x, y, parent);
			connected++;
			result += c;
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