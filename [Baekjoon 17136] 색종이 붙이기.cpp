#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int Map[10][10];
int Paper[10][10];
int N;
int result;

void input() {
	N = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &Map[i][j]);
			if (Map[i][j]) N++;
		}
	}
}

bool is_okay(int x, int y, int n) {
	if (x + n > 10 || y + n > 10) return false;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (!Map[i][j]) return false;
		}
	}
	return true;
}

void set_paper() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (is_okay(i, j, 5)) Paper[i][j] = 5;
			else if (is_okay(i, j, 4)) Paper[i][j] = 4;
			else if (is_okay(i, j, 3)) Paper[i][j] = 3;
			else if (is_okay(i, j, 2)) Paper[i][j] = 2;
			else if (is_okay(i, j, 1)) Paper[i][j] = 1;
		}
	}
}

void backtracking(int x, int y, int cnt[], int total, int how) {
	if (total == 0) {
		result = min(result, how);
		return;
	}
	if (how >= result)
		return;
	if (y == 10) {
		if(x < 9) backtracking(x + 1, 0, cnt, total, how);
		return;
	}
	if (!Paper[x][y]) {
		if (x == 9 && y == 9) return;
		if (y == 9) backtracking(x + 1, 0, cnt, total, how);
		else backtracking(x, y + 1, cnt, total, how);
		return;
	}

	int cur_paper = Paper[x][y];
	int tmp[5][5];
	while (cur_paper) {
		if (cnt[cur_paper - 1]) {
			bool op = true;
			for (int i = x; i < x + cur_paper; i++) {
				for (int j = y; j < y + cur_paper; j++) {
					if (!Map[i][j]) op = false;
				}
			}
			if (op) {
				for (int i = x; i < x + cur_paper; i++) {
					for (int j = y; j < y + cur_paper; j++) {
						tmp[i - x][j - y] = Paper[i][j];
						Paper[i][j] = Map[i][j] = 0;
					}
				}
				cnt[cur_paper - 1] -= 1;
				backtracking(x, y + cur_paper, cnt, total - cur_paper * cur_paper, how + 1);
				cnt[cur_paper - 1] += 1;
				for (int i = x; i < x + cur_paper; i++) {
					for (int j = y; j < y + cur_paper; j++) {
						Paper[i][j] = tmp[i - x][j - y];
						Map[i][j] = 1;
					}
				}
			}
		}
		cur_paper--;
	}
}

void solution() {
	int cnt[5] = { 5,5,5,5,5 };
	
	result = 10000;
	set_paper();
	backtracking(0, 0, cnt, N, 0);
	if (result == 10000) printf("-1");
	else printf("%d", result);
}

int main()
{
	input();
	solution();

	return 0;
}