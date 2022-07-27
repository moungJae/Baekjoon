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

int H, W;
bool Map[500][500];

void input() {
	int h, i;

	cin >> H >> W;
	for (int j = 0; j < W; j++) {
		cin >> h;
		i = H - 1;
		while (h--) {
			Map[i][j] = true;
			i--;
		}
	}
}

int get_rain(int x, int y) {
	int cnt = 0;

	while (y < W) {
		if (!Map[x][y]) {
			y++;
			cnt++;
		}
		else {
			return cnt;
		}
	}
	return 0;
}

void solution() {
	int cnt = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W - 1; j++) {
			if (Map[i][j] && !Map[i][j + 1]) {
				cnt += get_rain(i, j + 1);
			}
		}
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