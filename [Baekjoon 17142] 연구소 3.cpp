#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N, M, result;
int Map[51][51], virus[51][51];
bool check[51][51];
vector<pair<int, int>> v;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) v.push_back({ i,j });
			virus[i][j] = INF;
		}
	}
}

void copy_virus(int src[][51], int dest[][51]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = false;
		}
	}
}

void set_virus(int startX, int startY) {
	queue<pair<pair<int, int>, int>> Q;

	init();
	Q.push({ {startX,startY},0 });
	virus[startX][startY] = 0;
	check[startX][startY] = true;
	while (!Q.empty()) {
		int x = Q.front().first.first, y = Q.front().first.second;
		int cnt = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i], nextY = y + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
				if (!check[nextX][nextY]) {
					if (Map[nextX][nextY] == 0) {
						check[nextX][nextY] = true;
						if (cnt + 1 < virus[nextX][nextY]) virus[nextX][nextY] = cnt + 1;
						Q.push({ {nextX,nextY}, virus[nextX][nextY] });
					}
					else if (Map[nextX][nextY] == 2) {
						check[nextX][nextY] = true;
						Q.push({ {nextX,nextY}, cnt + 1 });
					}
				}
			}
		}
	}
}

void solution(int idx, int cnt) {
	if (cnt == M) {
		int ret = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Map[i][j] == 0) {
					if (virus[i][j] == INF) return;
					ret = max(ret, virus[i][j]);
				}
			}
		}
		result = min(result, ret);
		return;
	}
	if (v.size() - idx + cnt < M) return;
	int tmp[51][51];


	// 바이러스 세팅
	copy_virus(virus, tmp);
	set_virus(v[idx].first, v[idx].second);
	solution(idx + 1, cnt + 1);
	copy_virus(tmp, virus);

	// 바이러스 노세팅
	solution(idx + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	result = INF;
	solution(0, 0);
	cout << (result == INF ? -1 : result);

	return 0;
}