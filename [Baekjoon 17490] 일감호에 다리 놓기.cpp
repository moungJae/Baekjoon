#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
ll K;
ll S[1000001];
int parent[1000001];
bool visited[1000001];
bool check1[1000001], check2[1000001];
vector<pair<pair<int, int>,ll>> path;

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		path.push_back({ {0,i + 1}, S[i] });
		check1[i + 1] = check2[i + 1] = true;
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		if (x < y) {
			check1[x] = false;
			check2[y] = false;
		}
		else { 
			check2[x] = false;
			check1[y] = false;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (i == N) {
			if (!check1[1] && !check2[N]) continue;
			path.push_back({ { 1, N }, 0 });
		}
		else {
			if (!check1[i] && !check2[i + 1]) continue;
			path.push_back({ { i, i + 1 }, 0 });
		}
	}
}

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void Union(int x, int y) {
	x = getParent(x), y = getParent(y);
	if (x == y) return;
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

bool compare(pair<pair<int, int>,ll> x, pair<pair<int, int>,ll> y) {
	return x.second < y.second;
}

void solution() {
	if (M <= 1) {
		cout << "YES" << endl;
	}
	else {
		for (int i = 0; i <= N; i++) parent[i] = i;
		sort(path.begin(), path.end(), compare);
		ll distance = 0;
		for (int i = 0; i < path.size(); i++) {
			int x = path[i].first.first, y = path[i].first.second;
			ll weight = path[i].second;
			if (getParent(x) != getParent(y)) {
				Union(x, y);
				distance += weight;
			}
		}
		if (distance <= K) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}