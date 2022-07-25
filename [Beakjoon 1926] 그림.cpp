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

int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int paint[500][500];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> paint[i][j];
}

bool is_in(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void bfs(int s_x, int s_y, int& s) {
	queue<pair<int, int>> Q;
	int cnt = 0;

	Q.push({s_x, s_y});
	paint[s_x][s_y] = 0;
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		
		cnt++;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (is_in(next_x, next_y) && paint[next_x][next_y]) {
				paint[next_x][next_y] = 0;
				Q.push({next_x, next_y});
			}
		}
	}
	s = max(cnt, s);
}

void solution() {
	int cnt = 0, s = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paint[i][j]) {
				cnt++;
				bfs(i, j, s);
			}
		}
	}

	cout << cnt << endl;
	cout << s << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}