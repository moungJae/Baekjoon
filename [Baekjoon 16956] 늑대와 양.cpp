#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define ll long long
#define INF 100000000
#define endl '\n'

using namespace std;

int R, C;
char Map[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void input() {
	string s;

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) {
			Map[i][j] = s[j];
		}
	}
}

bool is_in(int x, int y) {
	return x >= 0 && x < R && y >= 0 && y < C;
}

void solution() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Map[i][j] == 'S') {
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];

					if (is_in(x, y) && Map[x][y] == 'W') {
						cout << 0;
						return;
					}
					else if (is_in(x, y) && Map[x][y] == '.') 
						Map[x][y] = 'D';
				}
			}
		}
	}

	cout << 1 << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << Map[i][j];
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}