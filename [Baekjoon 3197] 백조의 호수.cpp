#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

bool is_meet(int x1, int y1, int x2, int y2);
void Union(int x1, int y1, int x2, int y2);

int R, C;
int L_x[2], L_y[2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int parent[1502][1502];
char Map[1502][1502];
bool check[1502][1502];
queue<pair<int, int>> Q;

void input() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string S;
		cin >> S;
		for (int j = 1; j <= C; j++) {
			Map[i][j] = S[j - 1];
			if (Map[i][j] == 'L') {
				if (!L_x[0]) L_x[0] = i, L_y[0] = j;
				else L_x[1] = i, L_y[1] = j;
			}
		}
	}
}

int get_2_to_1(int x, int y) {
	return (x - 1) * C + y;
}

pair<int, int> get_1_to_2(int t) {
	pair<int, int> ret;
	ret.first = (t - 1) / C + 1;
	ret.second = (t % C == 0 ? C : t % C);
	return ret;
}


void init() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			parent[i][j] = get_2_to_1(i, j);
		}
	}
}

void map_separate() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (Map[i][j] != 'X') {
				for (int k = 0; k < 4; k++) {
					int nextX = i + dx[k], nextY = j + dy[k];
					if (nextX >= 1 && nextX <= R && nextY >= 1 && nextY <= C) {
						if (Map[nextX][nextY] == 'X' && !check[nextX][nextY]) {
							Q.push({ nextX, nextY });
							check[nextX][nextY] = true;
						}
						else if (Map[nextX][nextY] != 'X' && !is_meet(i, j, nextX, nextY)) {
							Union(i, j, nextX, nextY);
						}
					}
				}
			}
		}
	}
}

int get_parent(int x, int y) {
	if (parent[x][y] == get_2_to_1(x, y)) {
		return parent[x][y];
	}
	pair<int, int> p = get_1_to_2(parent[x][y]);
	return parent[x][y] = get_parent(p.first, p.second);
}

void Union(int x1, int y1, int x2, int y2) {
	int X = get_parent(x1, y1);
	int Y = get_parent(x2, y2);
	pair<int, int> p1 = get_1_to_2(X);
	pair<int, int> p2 = get_1_to_2(Y);
	if (X > Y) parent[p1.first][p1.second] = Y;
	else parent[p2.first][p2.second] = X;
}

bool is_meet(int x1, int y1, int x2, int y2) {
	if (get_parent(x1, y1) == get_parent(x2, y2))
		return true;
	return false;
}

void solution() {
	int day = 0;
	init();
	map_separate();
	while (!is_meet(L_x[0], L_y[0], L_x[1], L_y[1])) {
		queue<pair<int, int>> new_Q;
		while (!Q.empty()) {
			int x = Q.front().first, y = Q.front().second;
			Q.pop();

			check[x][y] = false, Map[x][y] = '.';
			for (int i = 0; i < 4; i++) {
				int nextX = x + dx[i], nextY = y + dy[i];
				if (nextX >= 1 && nextX <= R && nextY >= 1 && nextY <= C) {
					if (Map[nextX][nextY] == 'X' && !check[nextX][nextY]) {
						new_Q.push({ nextX, nextY });
						check[nextX][nextY] = true;
					}
					else if (Map[nextX][nextY] != 'X' && !is_meet(x, y, nextX, nextY)) {
						Union(x, y, nextX, nextY);
					}
				}
			}
		}
		Q = new_Q;
		day += 1;
	}
	cout << day;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();
	
	return 0;
}