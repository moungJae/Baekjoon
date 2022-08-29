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
#define FIRE 0
#define PLAYER 1

using namespace std;

char Map[1001][1001];
bool visited[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int w, h;

void input() {
	cin >> w >> h;
	for (int i = 1; i <= h; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= w; j++) {
			Map[i][j] = s[j - 1];
		}
	}
}

bool is_in(int x, int y) {
	return (x >= 1 && x <= h && y >= 1 && y <= w);
}

void init() {
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			visited[i][j][0] = visited[i][j][1] = false;
		}
	}
}

void solution() {
	queue<pair<pair<int, int>, pair<int, int>>> Q;

	init();
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (Map[i][j] == '@') {
				Q.push({ {i,j}, {0, PLAYER} });
			}
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (Map[i][j] == '*') {
				Q.push({ {i,j}, {0, FIRE} });
			}
		}
	}
	
	while (!Q.empty()) {
		int cur_x = Q.front().first.first;
		int cur_y = Q.front().first.second;
		int cnt = Q.front().second.first;
		int op = Q.front().second.second;

		Q.pop();
		if (op == PLAYER && visited[cur_x][cur_y][FIRE])
			continue;

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (is_in(next_x, next_y) && Map[next_x][next_y] == '.' 
				&& !visited[next_x][next_y][op]) {
				visited[next_x][next_y][op] = true;
				Q.push({ {next_x,next_y}, {cnt + 1,op} });
			}
			else if (!is_in(next_x, next_y) && op == PLAYER) {
				cout << (cnt + 1) << endl;
				return;
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;

	cin >> t;
	while (t--) {
		input();
		solution();
	}

	return 0;
}