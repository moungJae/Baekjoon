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

int N;
int W[17][17];
int cost[17][1 << 16];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> W[i][j];
		}
	}
}

int dfs(int cur_node, int cur_bit) {
	if (cur_bit == (1 << N) - 1) {
		if (W[cur_node][1] == 0) return INF;
		return W[cur_node][1];
	}

	if (cost[cur_node][cur_bit] != INF)
		return cost[cur_node][cur_bit];

	for (int next_node = 1; next_node <= N; next_node++) {
		if (!W[cur_node][next_node]) continue;
		if((cur_bit & (1 << (next_node - 1))) == (1 << (next_node - 1))) continue;
		cost[cur_node][cur_bit] = min(cost[cur_node][cur_bit],
			W[cur_node][next_node] + dfs(next_node, cur_bit | (1 << (next_node - 1))));
	}

	return cost[cur_node][cur_bit];
}

void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= (1 << N) - 1; j++) {
			cost[i][j] = INF;
		}
	}
	cout << dfs(1, 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}