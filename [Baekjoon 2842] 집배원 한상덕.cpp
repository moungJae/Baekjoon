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

int N, curX, curY, size_K;
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
int height[51][51];
char Map[51][51];
bool visited[51][51];
vector<int> v;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < N; j++) {
			Map[i][j] = S[j];
			if (Map[i][j] == 'P')
				curX = i, curY = j;
			else if (Map[i][j] == 'K')
				size_K++;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> height[i][j];
			v.push_back(height[i][j]);
		}
	}
}

bool bfs(int startX, int startY, int l, int r) {
	queue<pair<int, int>> Q;
	int cnt = 0;

	if (v[l] <= height[startX][startY] && height[startX][startY] <= v[r]) {
		Q.push({ startX,startY });
		visited[startX][startY] = true;
	}
	while (!Q.empty()) {
		int x = Q.front().first, y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 8; i++) {
			int nextX = x + dx[i], nextY = y + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && !visited[nextX][nextY]) {
				if (v[l] <= height[nextX][nextY] && height[nextX][nextY] <= v[r]) {
					if (Map[nextX][nextY] == 'K') 
						cnt++;
					Q.push({ nextX,nextY });
					visited[nextX][nextY] = true;
				}
			}
		}
	}

	return cnt == size_K;
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

void solution() {
	int l = 0, r = 0, fatigue = INF;

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	while (l < v.size() && r < v.size()) {
		init();
		if (bfs(curX, curY, l, r)) {
			fatigue = min(fatigue, v[r] - v[l]);
			l += 1;
		}
		else {
			r += 1;
		}
	}
	cout << fatigue;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();
	
	return 0;
}