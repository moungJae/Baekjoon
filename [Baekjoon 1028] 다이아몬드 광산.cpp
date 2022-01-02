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

using namespace std;

int R, C;
int Map[751][751];
int left_down1[751][751], right_down1[751][751];
int right_down2[751][751], left_down2[751][751];

void input() {
	string S;
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		cin >> S;
		for (int j = 1; j <= C; j++) {
			Map[i][j] = S[j - 1] - '0';
		}
	}
}

int solution() {
	int result;

	for (int i = R; i >= 1; i--) {
		for (int j = C; j >= 1; j--) {
			if (Map[i][j]) {
				left_down1[i][j] = left_down1[i + 1][j - 1] + 1;
				right_down1[i][j] = right_down1[i + 1][j + 1] + 1;
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (Map[i][j]) {
				right_down2[i][j] = right_down2[i - 1][j - 1] + 1;
				left_down2[i][j] = left_down2[i - 1][j + 1] + 1;
			}
		}
	}

	result = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int x = min(left_down1[i][j], right_down1[i][j]);
			for (int k = 1; k <= x; k++) {
				int t = i + (k - 1) * 2;
				if(min(left_down2[t][j], right_down2[t][j]) >= k)
					result = max(result, k);
			}
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	cout << solution();

	return 0;
}