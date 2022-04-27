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
int parent[300001];
queue<pair<int, int>> query;

void input() {
	int x, y;
	
	cin >> N;
	for (int i = 1; i <= N - 2; i++) {
		cin >> x >> y;
		query.push({ x,y });
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

void solution() {
	int x = 1, y; // N = 2 일 경우 non-initialization 방지

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	while (!query.empty()) {
		x = query.front().first, y = query.front().second;
		query.pop();
		if (get_parent(x, parent) != get_parent(y, parent)) {
			go_union(x, y, parent);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (get_parent(x, parent) != get_parent(i, parent)) {
			cout << x << " " << i;
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}