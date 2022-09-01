#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <string>

#define ll long long
#define INF 100000000
#define endl '\n'

using namespace std;

int N, M;
ll total;
vector<pair<ll, pair<int, int>>> path;
int parent[100001];

void input() {
	int from, to;
	ll dist;

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> from >> to >> dist;
		path.push_back({ dist, {from,to} });
		total += dist;
	}
}

bool compare(pair<ll, pair<int, int>> x, pair<ll, pair<int, int>> y) {
	return x.first < y.first;
}

int get_parent(int x) {
	if (parent[x] == x)
		return x;
	return (parent[x] = get_parent(parent[x]));
}

void union_operation(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);

	if (x > y)
		parent[x] = y;
	else
		parent[y] = x;
}

void solution(){
	ll mst = 0;
	int connect = 0;

	sort(path.begin(), path.end(), compare);
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 0; i < path.size(); i++) {
		ll dist = path[i].first;
		int from = path[i].second.first;
		int to = path[i].second.second;

		if (get_parent(from) != get_parent(to)) {
			union_operation(from, to);
			connect++;
			mst += dist;
		}
		if (connect == N - 1)
			break;
	}

	if (connect == N - 1)
		cout << (total - mst);
	else
		cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}