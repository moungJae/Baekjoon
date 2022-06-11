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
bool visited[51][51];
int Map[51][51], room[51][51], group[51][51];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int ans1, ans2, ans3;
int group_idx;

void input() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Map[i][j];
		}
	}
}

bool is_in(int x, int y) {
	return (x >= 1 && x <= N && y >= 1 && y <= M);
}

void bfs(int startX, int startY) {
	queue<pair<int, int>> Q, tmp;
	int roomCnt = 0;

	Q.push({ startX, startY });
	tmp.push({ startX, startY });
	visited[startX][startY] = true;
	while (!Q.empty()) {
		int curX = Q.front().first, curY = Q.front().second;
		Q.pop();

		roomCnt++;
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];

			if (!(Map[curX][curY] & (1 << i)) && !visited[nextX][nextY]) {
				visited[nextX][nextY] = true;
				Q.push({ nextX, nextY });
				tmp.push({ nextX,nextY });
			}
		}
	}

	group_idx++;
	while (!tmp.empty()) {
		int curX = tmp.front().first, curY = tmp.front().second;
		tmp.pop();
		room[curX][curY] = roomCnt;
		group[curX][curY] = group_idx;
	}

	ans2 = max(ans2, roomCnt);
}

void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				ans1++;
			}
		}
	}
	for (int curX = 1; curX <= N; curX++) {
		for (int curY = 1; curY <= M; curY++) {
			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i], nextY = curY + dy[i];

				if (is_in(nextX, nextY)) {
					if ((Map[curX][curY] & (1 << i)) 
						&& (group[curX][curY] != group[nextX][nextY])) {
						ans3 = max(ans3, room[curX][curY] + room[nextX][nextY]);
					}
				}
			}
		}
	} 
	cout << ans1 << endl << ans2 << endl << ans3;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}