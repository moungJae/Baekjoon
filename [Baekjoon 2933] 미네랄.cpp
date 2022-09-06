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

int R, C;
char Map[102][102];
int N;
int info[102];
bool check[102][102];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> mineral_vec;

void input() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= C; j++) {
			Map[i][j] = s[j - 1];
		}
	}
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> info[i];
}

void init() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			check[i][j] = 0;
		}
	}
}

void show_mineral() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << Map[i][j];
		}
		cout << endl;
	}
}

bool is_in(int x, int y) {
	return x >= 1 && x <= R && y >= 1 && y <= C;
}

void bfs(int s_x, int s_y, int get_op) {
	queue<pair<int, int>> Q;

	Q.push({ s_x,s_y });
	check[s_x][s_y] = true;
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;

		Q.pop();
		if (get_op) 
			mineral_vec.push_back({ x,y });
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (is_in(next_x, next_y) && Map[next_x][next_y] == 'x'
				&& !check[next_x][next_y]) {
				Q.push({ next_x,next_y });
				check[next_x][next_y] = true;
			}
		}
	}
}

bool is_move_down(vector<pair<int, int>> mineral_vec) {
	for (pair<int, int> p : mineral_vec) {
		int x = p.first, y = p.second;

		if (x + 1 <= R && Map[x + 1][y] == '.') {
			Map[x][y] = '.';
			check[x][y] = false;
		}
		else
			return false;
	}
	return true;
}

bool compare(pair<int, int> x, pair<int, int> y) {
	return x.first > y.first;
}

void move_mineral(int s_x, int s_y) {
	bfs(s_x, s_y, 1);
	sort(mineral_vec.begin(), mineral_vec.end(), compare);
	
	while (is_move_down(mineral_vec)) {
		for (int i = 0; i < mineral_vec.size(); i++) {
			int x = mineral_vec[i].first + 1;
			int y = mineral_vec[i].second;

			mineral_vec[i].first = x;
			Map[x][y] = 'x';
			check[x][y] = true;
		}
	}
	
	for (pair<int, int> p : mineral_vec) {
		int x = p.first, y = p.second;
		Map[x][y] = 'x';
		check[x][y] = true;
	}
	mineral_vec.clear();
}

void operation_mineral() {
	init();
	for (int i = 1; i <= C; i++) {
		if (Map[R][i] == 'x')
			bfs(R, i, 0);
	}
	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++) {
			if (!check[i][j] && Map[i][j] == 'x') {
				move_mineral(i, j);
			}
		}
	}
}

void solution() {
	int num;

	for (int i = 1; i <= N; i++) {
		// ->
		if (i % 2) {
			num = 1;
			while (num <= C && Map[R - info[i] + 1][num] == '.')
				num++;
			Map[R - info[i] + 1][num] = '.';
		}
		// <-
		else {
			num = C;
			while (num >= 1 && Map[R - info[i] + 1][num] == '.')
				num--;
			Map[R - info[i] + 1][num] = '.';
		}
		operation_mineral();
	}

	show_mineral();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}