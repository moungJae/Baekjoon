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

int N, M, K;
int X[1025][1025], table[1025][1025];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> X[i][j];
		}
	}
	cin >> K;
}

void set_table() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			table[i][j] = X[i][j] + table[i][j - 1] 
				+ table[i - 1][j] - table[i - 1][j - 1];
		}
	}
}

void solution() {
	int x1, y1, x2, y2;
	set_table();
	while (K--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << table[x2][y2] - table[x2][y1 - 1] - table[x1 - 1][y2] + table[x1 - 1][y1 - 1] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}