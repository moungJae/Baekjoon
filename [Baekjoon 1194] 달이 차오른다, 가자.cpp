#define _CRT_SECURE_NO_WARNINGS
#include <string>
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
int dx[4] = { -1, 0,1,0 };
int dy[4] = { 0,1,0,-1 };
char Map[51][51];
int D[51][51][1 << 6];

typedef struct Info {
	int x;
	int y;
	int key_bit;
	int dist;
} info;

void input() {
	string s;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) {
			Map[i][j] = s[j - 1];
		}
	}
}

int bfs(int start_x, int start_y) {
	queue<Info> Q;
	int answer = INF;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k < 64; k++) {
				D[i][j][k] = INF;
			}
		}
	}

	Q.push({ start_x,start_y, 0 , 0 });
	D[start_x][start_y][0] = 0;
	while (!Q.empty()) {
		int x = Q.front().x, y = Q.front().y;
		int key_bit = Q.front().key_bit, dist = Q.front().dist;
		Q.pop();

		if (dist > D[x][y][key_bit])
			continue;

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i], next_y = y + dy[i];
			if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M) {
				if (Map[next_x][next_y] >= 'a' && Map[next_x][next_y] <= 'z') {
					int tmp = Map[next_x][next_y] - 'a';
					if ((key_bit & (1 << tmp)) && (dist + 1 < D[next_x][next_y][key_bit])) {
						D[next_x][next_y][key_bit] = dist + 1;
						Q.push({ next_x,next_y,key_bit,dist + 1 });
					}
					else if (!(key_bit & (1 << tmp)) && (dist + 1 < D[next_x][next_y][key_bit | (1 << tmp)])){
						D[next_x][next_y][key_bit | (1 << tmp)] = dist + 1;
						Q.push({ next_x,next_y, key_bit | (1 << tmp), dist + 1 });
					}
				}
				else if (Map[next_x][next_y] >= 'A' && Map[next_x][next_y] <= 'Z') {
					int tmp = Map[next_x][next_y] - 'A';
					if ((key_bit & (1 << tmp)) && (dist + 1 < D[next_x][next_y][key_bit])) {
						D[next_x][next_y][key_bit] = dist + 1;
						Q.push({ next_x,next_y, key_bit,dist + 1 });
					}
				}
				else if (Map[next_x][next_y] == '.') {
					if (dist + 1 < D[next_x][next_y][key_bit]) {
						D[next_x][next_y][key_bit] = dist + 1;
						Q.push({ next_x,next_y,key_bit, dist + 1 });
					}
				}
				else if (Map[next_x][next_y] == '1') {
					answer = min(answer, dist + 1);
				}
			}
		}
	}

	return (answer == INF ? -1 : answer);
}

void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Map[i][j] == '0') {
				Map[i][j] = '.';
				cout << bfs(i, j);
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}