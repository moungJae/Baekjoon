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

int imos[5003][5003];
int N, M;

void input() {
	cin >> N >> M;
}

void make_Imos(int A, int B, int X) {
	imos[A][B] += 1, imos[A][B + 1] += -1;
	imos[A + X + 1][B] += -1, imos[A + X + 1][B + X + 2] += 1;
	imos[A + X + 2][B + 1] += 1, imos[A + X + 2][B + X + 2] += -1;
}

void set_Imos() {
	// 1. 오른쪽으로 스위핑
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			imos[i][j] += imos[i][j - 1];
		}
	}
	// 2. 밑으로 스위핑
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			imos[j][i] += imos[j - 1][i];
		}
	}
	// 3. 대각선으로 스위핑
	for (int gap = 0; gap < N; gap++) {
		for (int i = N - gap, j = 1; i <= N; i++, j++) {
			imos[i][j] += imos[i - 1][j - 1];
		}
	}
}

int count_Imos() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (imos[i][j] > 0) ret++;
		}
	}
	return ret;
}

void solution() {
	int A, B, X;
	while (M--) {
		cin >> A >> B >> X;
		make_Imos(A, B, X);
	}
	set_Imos();
	cout << count_Imos();
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();
	
	return 0;
}