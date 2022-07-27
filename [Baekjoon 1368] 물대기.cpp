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
#include <set>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N;
int W[301], parent[301];
vector<pair<pair<int, int>, int>> info;

void input() {
	int w;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> W[i];
		info.push_back({ {0, i}, W[i] });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> w;
			if (i != j) info.push_back({ {i,j}, w });
		}
	}
}

bool compare(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
	return x.second < y.second;
}

int get_parent(int x) {
	if (x == parent[x]) 
		return x;
	return (parent[x] = get_parent(parent[x]));
}

void go_union(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

int get_total_weight() {
	int edge = 0;
	int total_weight = 0;

	for (int i = 1; i <= N; i++) parent[i] = i;
	sort(info.begin(), info.end(), compare);
	for (int i = 0; i < info.size(); i++) {
		int from = info[i].first.first;
		int to = info[i].first.second;
		int w = info[i].second;

		if (get_parent(from) != get_parent(to)) {
			go_union(from, to);
			total_weight += w;
			edge++;
		}
		if (edge == N) break;
	}

	return total_weight;
}

void solution() {
	int path = get_total_weight();

	cout << path;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}