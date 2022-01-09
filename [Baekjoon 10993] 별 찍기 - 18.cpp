#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <math.h>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

char Star[2100][2100];

void init_Star(int N) {
	int row = pow(2, N) - 1;
	int col = row * 2 - 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Star[i][j] = ' ';
		}
	}
}

void set_Star(int N_, int N, int x, int y) {
	if (N == 0)
		return;
	if (N % 2 == 0) {
		int gap = pow(2, N) - 1;
		for (int i = 0; i < gap; i++) {
			if (i == 0) {
				for (int j = 0; j < 2 * gap - 1; j++)
					Star[x + i][y + j] = '*';
			}
			else {
				Star[x + i][y + i] = Star[x + i][y + (2 * gap - 2 - i)] = '*';
				if (N_ == N) Star[x + i][y + (2 * gap - 1 - i)] = 'x';
			}
		}
		set_Star(N_, N - 1, x + 1, y + pow(2, N - 1));
	}
	else {
		int gap = pow(2, N) - 1;
		for (int i = 0; i < gap; i++) {
			if (i == gap - 1) {
				for (int j = 0; j < 2 * gap - 1; j++) {
					Star[x + i][y + j] = '*';
				}
			}
			else {
				Star[x + i][y + (gap - 1 - i)] = Star[x + i][y + (gap - 1 + i)] = '*';
				if (N_ == N) Star[x + i][y + (gap + i)] = 'x';
			}
		}
		set_Star(N_, N - 1, x + pow(2, N - 1) - 1, y + pow(2, N - 1));
	}
}

void show_Star(int N) {
	int row = pow(2, N) - 1;
	int col = row * 2 - 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (Star[i][j] == 'x') break;
			printf("%c", Star[i][j]);
		}
		printf("\n");
	}
}

void solution() {
	int N;
	scanf("%d", &N);
	init_Star(N);
	set_Star(N, N, 0, 0);
	show_Star(N);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	solution();

	return 0;
}