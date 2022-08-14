#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int answer;
int N, M, G, R;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int Map[52][52], Copy[52][52];
int visited[52][52];
vector<pair<int, int>> info;
const int GREEN = 100, RED = 200, FLOWER = 300;

void input() {
	cin >> N >> M >> G >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Map[i][j];
			Copy[i][j] = Map[i][j];
			if (Map[i][j] == 2)
				info.push_back({ i, j });
		}
	}
}

bool is_in(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= M;
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			Map[i][j] = Copy[i][j];
			visited[i][j] = 0;
		}
	}
}

int bfs(vector<pair<int, int>>& g_v, vector<pair<int, int>>& r_v) {
	queue<pair<pair<int, int>, pair<int ,int>>> Q;
	int flower = 0;

	init();
	for (pair<int, int> p : g_v) {
		Q.push({ { p.first, p.second }, {1, GREEN} });
		Map[p.first][p.second] = GREEN;
	}
	for (pair<int, int> p : r_v) {
		Q.push({ { p.first, p.second }, {1, RED} });
		Map[p.first][p.second] = RED;
	}

	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int t = Q.front().second.first;
		int color = Q.front().second.second;

		Q.pop();
		if (Map[x][y] == FLOWER)
			continue;
		for (int i = 0; i < 4; i++) {
			int n_x = x + dx[i];
			int n_y = y + dy[i];

			if (is_in(n_x, n_y) && Map[n_x][n_y]) {
				if (Map[n_x][n_y] == 1 || Map[n_x][n_y] == 2) {
					Q.push({ {n_x, n_y}, {t + 1,color} });
					visited[n_x][n_y] = t;
					Map[n_x][n_y] = color;
				}
				else if (visited[n_x][n_y] == t
					&& ((Map[n_x][n_y] == RED && color == GREEN) 
					|| (Map[n_x][n_y] == GREEN && color == RED))) {
					flower++;
					Map[n_x][n_y] = FLOWER;
				}
			}
		}
	}

	return flower;
}

void dfs(int idx, int g_cnt, int r_cnt,
	vector<pair<int, int>>& g_v, vector<pair<int, int>>& r_v) {
	if (g_cnt == G && r_cnt == R) {
		answer = max(answer, bfs(g_v, r_v));
		return;
	}
	if (g_cnt > G || r_cnt > R || idx == info.size())
		return;

	for (int i = idx; i < info.size(); i++) {
		int x = info[i].first, y = info[i].second;

		g_v.push_back({ x, y });
		dfs(i + 1, g_cnt + 1, r_cnt, g_v, r_v);
		g_v.pop_back();

		r_v.push_back({ x, y });
		dfs(i + 1, g_cnt, r_cnt + 1, g_v, r_v);
		r_v.pop_back();
	}
}

void solution() {
	vector<pair<int, int>> g_v, r_v;

	dfs(0, 0, 0, g_v, r_v);
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}