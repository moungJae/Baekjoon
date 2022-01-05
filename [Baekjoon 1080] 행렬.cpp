#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
int A[51][51], B[51][51];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			A[i][j] = S[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			B[i][j] = S[j] - '0';
		}
	}
}

bool check(int A[][51], int B[][51]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) return false;
		}
	}
	return true;
}

void change_A(int A[][51], int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			A[i][j] ^= 1;
		}
	}
}

int change_matrix(int A[][51], int B[][51]) {
	int cnt = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (A[i][j] != B[i][j]) {
				change_A(A, i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	if (check(A, B)) cout << 0 << endl;
	else {
		int cnt = change_matrix(A, B);
		if (check(A, B)) cout << cnt << endl;
		else cout << -1 << endl;
	}

	return 0;
}