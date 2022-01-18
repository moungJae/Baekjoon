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

vector<pair<pair<int, int>,int>> v;
int n, m;
int parent[200001];

bool input() {
	cin >> n >> m;
	if (n == 0 && m == 0) return false;
	v.clear();
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({ {x,y},z });
	}
	return true;
}

int get_parent(int x) {
	if (parent[x] == x) return x;
	return (parent[x] = get_parent(parent[x]));
}

void Union(int x, int y) {
	x = get_parent(x), y = get_parent(y);
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

bool compare(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
	return x.second < y.second;
}

void solution() {
	int ans = 0;
	for (int i = 0; i < n; i++) parent[i] = i;
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first.first, y = v[i].first.second;
		if (get_parent(x) != get_parent(y)) {
			Union(x, y);
			ans -= v[i].second;
		}
		ans += v[i].second;
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (input()) {
		solution();
	}

	return 0;
}