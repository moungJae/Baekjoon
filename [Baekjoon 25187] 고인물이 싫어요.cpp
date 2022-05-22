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

int N, M, Q;
int water[100001], query[100001];
int parent[100001], check_water[100001][2];
vector<int> path[100001];

void input() {
	int from, to;

	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++)
		cin >> water[i];
	for (int i = 1; i <= M; i++) {
		cin >> from >> to;
		path[from].push_back(to);
		path[to].push_back(from);
	}
	for (int i = 1; i <= Q; i++) {
		cin >> query[i];
	}
}

int get_parent(int x) {
	if (x == parent[x])
		return x;
	return (parent[x] = get_parent(parent[x]));
}

void go_union(int x, int y) {
	x = get_parent(x), y = get_parent(y);
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

void set_water() {
	int x;

	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int from = 1; from <= N; from++) {
		for (int to : path[from]) {
			if (get_parent(to) != get_parent(from))
			{
				go_union(to, from);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		x = get_parent(i);
		if (water[i]) check_water[x][1]++;
		else check_water[x][0]++;
	}
}

bool clean_water(int q) {
	int x;

	x = get_parent(q);
	if (check_water[x][1] > check_water[x][0])
		return true;
	return false;
}

void solution() {
	set_water();
	for (int i = 1; i <= Q; i++) {
		if (clean_water(query[i]))
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}