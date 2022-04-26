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

int K;
int R, C;
int Map[201][201];
int dx[2][8] = { { -1,-2,-2,-1,1,2,2,1 }, {-1,0,1,0} };
int dy[2][8] = { { -2,-1,1,2,2,1,-1,-2 },{0,1,0,-1} };
bool visited[201][201][31];

void input() {
	cin >> K;
	cin >> C >> R;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> Map[i][j];
		}
	}
}

void solution() {
	queue<pair<pair<int, int>, pair<int,int>>> Q;
	int result = INF;

	Q.push({ {1,1}, {0,0} });
	visited[1][1][0] = true;
	while (!Q.empty()) {
		int x = Q.front().first.first, y = Q.front().first.second;
		int cnt = Q.front().second.first, t = Q.front().second.second;
		Q.pop();

		if (x == R && y == C) {
			result = min(result, t);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[1][i], nextY = y + dy[1][i];
			if (nextX >= 1 && nextX <= R && nextY >= 1 && nextY <= C) {
				if (Map[nextX][nextY] == 0 && !visited[nextX][nextY][cnt]) {
					visited[nextX][nextY][cnt] = true;
					Q.push({ {nextX,nextY},{cnt,t + 1} });
				}
			}
		}
		if (cnt < K) {
			for (int i = 0; i < 8; i++) {
				int nextX = x + dx[0][i], nextY = y + dy[0][i];
				if (nextX >= 1 && nextX <= R && nextY >= 1 && nextY <= C) {
					if (Map[nextX][nextY] == 0 && !visited[nextX][nextY][cnt + 1]) {
						visited[nextX][nextY][cnt + 1] = true;
						Q.push({ {nextX,nextY},{cnt + 1, t + 1} });
					}
				}
			}
		}
	}
	cout << (result == INF ? -1 : result);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}