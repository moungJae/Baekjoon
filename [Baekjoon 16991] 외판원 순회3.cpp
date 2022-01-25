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
double point[17][2]; // (xi, yi) 좌표
double W[17][17]; // i ~> j 의 가중치
double cost[17][1 << 16]; // 비트마스킹을 위한 배열

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> point[i][0] >> point[i][1];
	}
}

void set_weight() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			W[i][j] = sqrt(pow(point[i][0] - point[j][0], 2) 
				+ pow(point[i][1] - point[j][1], 2));
		}
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= (1 << N) - 1; j++) {
			cost[i][j] = INF;
		}
	}
}

double dfs(int cur_node, int cur_bit) {
	// 모든 정점을 다 방문하게 된 경우
    // 예를 들어 N = 4 일때, 1111 인 경우 모두 방문하였음
	if (cur_bit == (1 << N) - 1) {
    	// 원점(1)으로 돌아갈 수 없는 경우 (cur_node ~> 1 no)
		if (W[cur_node][1] == 0) return INF;
        // 원점(1)으로 돌아갈 수 있는 경우 (cur_node ~> 1 ok)
		return W[cur_node][1];
	}

	// 현재 정점으로 이동한 경로가 이전과 동일한 경우 
	if (cost[cur_node][cur_bit] != INF)
		return cost[cur_node][cur_bit];

	// 비트마스킹을 하는 작업
	for (int next_node = 1; next_node <= N; next_node++) {
		// 현재 노드에서 다음 노드로 이동할 수 없는 경우
        if (!W[cur_node][next_node]) continue;
        // 현재 노드에서 다음 노드로 이동하려고 하지만 이미 방문된 경우 
        // ex) N = 4, cur_bit = 0111, cur_node = 2, next_node = 3 일 때 이미 방문된 경우
		if((cur_bit & (1 << (next_node - 1))) == (1 << (next_node - 1))) continue;
        
        // cur_node ~> next_node 로의 가중치를 더하고 비트마스킹하여 인자값을 넘겨줌
		cost[cur_node][cur_bit] = min(cost[cur_node][cur_bit],
			W[cur_node][next_node] + dfs(next_node, cur_bit | (1 << (next_node - 1))));
	}

	// 현재 정점과 bit를 고려한 비용을 반환
	return cost[cur_node][cur_bit];
}

void solution() {
	set_weight();
	init();
	double result = dfs(1, 1);
	printf("%.6f", result);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}