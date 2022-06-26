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

int N, M, K;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int Map[2000][2000];
int start_x = -1, start_y = -1;
int end_x = -1, end_y = -1;
bool visited[2000][2000];

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 4) {
				start_x = i;
				start_y = j;
			}
			else if (Map[i][j] == 2) {
				end_x = i;
				end_y = j;
			}
		}
	}
}

bool is_in(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

void set_mannequin() {
	queue<pair<pair<int, int>, int>> Q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 3) {
				visited[i][j] = true;
				Q.push({ {i, j}, 0 });
			}
		}
	}

	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int dist = Q.front().second;
		Q.pop();
		
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			int next_dist = dist + 1;
			if (is_in(next_x, next_y) && !visited[next_x][next_y] && next_dist <= K) {
				visited[next_x][next_y] = true;
				Q.push({ {next_x, next_y}, next_dist });
			}
		}
	}
}

void solution() {
	queue<pair<pair<int, int>, int>> Q;

	set_mannequin();
	Q.push({ {start_x, start_y}, 0 });
	visited[start_x][start_y] = true;
	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int dist = Q.front().second;
		Q.pop();

		if (x == end_x && y == end_y) {
			cout << dist;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			int next_dist = dist + 1;	
			if (is_in(next_x, next_y) && !visited[next_x][next_y] 
				&& (Map[next_x][next_y] == 0 || Map[next_x][next_y] == 2)) {
				visited[next_x][next_y] = true;
				Q.push({ {next_x, next_y}, next_dist });
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