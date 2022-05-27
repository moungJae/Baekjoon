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

int N, M;
int r_f, c_f, r_h, c_h;
int a[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[1001][1001][2];
bool visited_row[1001], visited_col[1001];

typedef struct info {
	int x;
	int y;
	int jump_cnt;
	int op;
} Info;

bool in_area(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= M;
}

void input() {
	cin >> N >> M;
	cin >> r_f >> c_f >> r_h >> c_h;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> a[i][j];
		}
	}
}

void solution() {
	queue<Info> Q;
	Info info, next_info;

	visited[r_f][c_f][0] = true;
	Q.push({ r_f, c_f, 0, 0 });
	while (!Q.empty()) {
		info = Q.front();
		Q.pop();

		if (info.x == r_h && info.y == c_h) {
			cout << info.jump_cnt;
			return;
		}
		if (info.op == 0) {
			next_info.op = 1;
			next_info.jump_cnt = info.jump_cnt + 1;
			if (!visited_row[info.x]) {
				visited_row[info.x] = true;
				next_info.x = info.x;
				for (int y = 1; y <= M; y++) {
					next_info.y = y;
					if (!visited[next_info.x][next_info.y][next_info.op]) {
						visited[next_info.x][next_info.y][next_info.op] = true;
						Q.push(next_info);
					}
				}
			}
			if (!visited_col[info.y]) {
				visited_col[info.y] = true;
				next_info.y = info.y;
				for (int x = 1; x <= N; x++) {
					next_info.x = x;
					if (!visited[next_info.x][next_info.y][next_info.op]) {
						visited[next_info.x][next_info.y][next_info.op] = true;
						Q.push(next_info);
					}
				}
			}
		}
		next_info.op = info.op;
		next_info.jump_cnt = info.jump_cnt + 1;
		for (int i = 0; i < 4; i++) {
			next_info.x = info.x + a[info.x][info.y] * dx[i];
			next_info.y = info.y + a[info.x][info.y] * dy[i];
			if (in_area(next_info.x, next_info.y)
				&& !visited[next_info.x][next_info.y][next_info.op]) {
				visited[next_info.x][next_info.y][next_info.op] = true;
				Q.push(next_info);
			}
		}
	}
	cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}