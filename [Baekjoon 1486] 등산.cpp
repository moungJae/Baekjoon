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

int N, M, T, D;
char Map[26][26];
vector<pair<pair<int, int>, int>> path[26][26];
int Dist[26][26][26][26];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void input() {
	cin >> N >> M >> T >> D;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			Map[i][j] = s[j - 1];
		}
	}
}

bool is_in(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= M;
}

int get_height(char c) {
	const char* s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	for (int i = 0; ; i++) {
		if (s[i] == c)
			return i;
	}
}

void set_path(int from_x, int from_y, int to_x, int to_y) {
	int from_height = get_height(Map[from_x][from_y]);
	int to_height = get_height(Map[to_x][to_y]);

	if (abs(from_height - to_height) > T)
		return;
	int gap = from_height >= to_height 
		? 1 : (to_height - from_height) * (to_height - from_height);
	path[from_x][from_y].push_back({ {to_x, to_y}, gap });
}

void set_paths() {
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			for (int i = 0; i < 4; i++) {
				int next_x = x + dx[i];
				int next_y = y + dy[i];

				if (is_in(next_x, next_y)) {
					set_path(x, y, next_x, next_y);
				}
			}
		}
	}
}

void dijkstra(int start_x, int start_y) {
	priority_queue<pair<int, pair<int, int>>> PQ;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			Dist[start_x][start_y][i][j] = 1e9;
		}
	}

	PQ.push({ 0, {start_x, start_y} });
	Dist[start_x][start_y][start_x][start_y] = 0;
	while (!PQ.empty()) {
		int dist = -PQ.top().first;
		int cur_x = PQ.top().second.first;
		int cur_y = PQ.top().second.second;

		PQ.pop();
		if (Dist[start_x][start_y][cur_x][cur_y] < dist)
			continue;

		for (int i = 0; i < path[cur_x][cur_y].size(); i++) {
			int next_x = path[cur_x][cur_y][i].first.first;
			int next_y = path[cur_x][cur_y][i].first.second;
			int next_dist = dist + path[cur_x][cur_y][i].second;

			if (next_dist < Dist[start_x][start_y][next_x][next_y]) {
				Dist[start_x][start_y][next_x][next_y] = next_dist;
				PQ.push({ -(next_dist), {next_x,next_y} });
			}
		}
	}
}

void solution(){
	int maxH;

	set_paths();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dijkstra(i, j);
		}
	}
	
	maxH = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Dist[1][1][i][j] + Dist[i][j][1][1] <= D) {
				maxH = max(maxH, get_height(Map[i][j]));
			}
		}
	}
	cout << maxH;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}