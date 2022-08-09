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
#include <list>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
int cost[19][19];
int visited[19][1 << 19];
int parent[19];
vector<int> path[19];
const int START = 1;

void input() {
	int U, V, C;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> U >> V >> C;
		cost[U][V] = C;
		path[U].push_back(V);
	}
}

int dfs(int total_bit, int cur) {
	if (total_bit == ((1 << N) - 1)) {
		if (cost[cur][START]) {
			visited[cur][total_bit] = cost[cur][START];
			return cost[cur][START];
		}
		else
			return INF;
	}
	if (visited[cur][total_bit])
		return visited[cur][total_bit];

	visited[cur][total_bit] = INF;
	for (int next : path[cur]) {
		int next_bit = total_bit | (1 << (next - 1));
		if (total_bit & (1 << (next - 1)))
			continue;
		visited[cur][total_bit] = min(visited[cur][total_bit],
			max(cost[cur][next], dfs(next_bit, next)));
	}
	return visited[cur][total_bit];
}

void show_path(int cur) {
	if (!parent[cur]) {
		cout << cur << " ";
		return;
	}
	show_path(parent[cur]);
	cout << cur << " ";
}

void find_path(int total_bit, int cur) {
	if (total_bit == (1 << N) - 1) {
		if (cost[cur][START]) {
			show_path(cur);
			exit(0);
		}
		return;
	}

	for (int next : path[cur]) {
		int next_bit = total_bit | (1 << (next - 1));
		if (total_bit & (1 << (next - 1)))
			continue;
		if (visited[cur][total_bit] == max(cost[cur][next],visited[next][next_bit])) {
			parent[next] = cur;
			find_path(next_bit, next);
		}
	}
}

void solution() {
	if (dfs(1, START) == INF)
		cout << -1;
	else {
		cout << visited[START][1] << endl;
		find_path(1, START);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}