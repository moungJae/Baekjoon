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

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char puyo[12][6];
bool visited[12][6];

void input() {
	string s;

	for (int i = 0; i < 12; i++) {
		cin >> s;
		for (int j = 0; j < 6; j++)
			puyo[i][j] = s[j];
	}
}

void init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = false;
		}
	}
}

bool is_in(int x, int y) {
	return (x >= 0 && x < 12 && y >= 0 && y < 6);
}

int count_bfs(int s_x, int s_y, char c) {
	queue<pair<int, int>> Q;
	int cnt = 0;

	init();
	Q.push({s_x, s_y});
	visited[s_x][s_y] = true;
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		
		cnt++;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (is_in(next_x, next_y) && !visited[next_x][next_y] && puyo[next_x][next_y] == c) {
				visited[next_x][next_y] = true;
				Q.push({ next_x, next_y });
			}
		}
	}

	return cnt;
}

void remove_bfs(int s_x, int s_y, char c) {
	queue<pair<int, int>> Q;

	init();
	Q.push({ s_x, s_y });
	visited[s_x][s_y] = true;
	puyo[s_x][s_y] = '.';
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;

		Q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (is_in(next_x, next_y) && !visited[next_x][next_y] && puyo[next_x][next_y] == c) {
				visited[next_x][next_y] = true;
				puyo[next_x][next_y] = '.';
				Q.push({ next_x, next_y });
			}
		}
	}
}

bool check() {
	bool op = false;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (puyo[i][j] != '.' && count_bfs(i, j, puyo[i][j]) >= 4) {
				op = true;
				remove_bfs(i, j, puyo[i][j]);
			}
		}
	}

	return op;
}

void down_puyo() {
	int k;

	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 0; i--) {
			if (puyo[i][j] == '.') 
				continue;
			k = i;
			while (k + 1 <= 11 && puyo[k + 1][j] == '.') {
				swap(puyo[k][j], puyo[k + 1][j]);
				k++;
			}
		}
	}
}

void solution() {
	int cnt = 0;

	while (check()) {
		cnt++;
		down_puyo();
	}
	cout << cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}