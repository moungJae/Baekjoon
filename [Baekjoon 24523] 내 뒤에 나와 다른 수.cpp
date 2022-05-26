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

int N;
int A[1000001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
}

int get_idx(int n, int idx) {
	for (int i = idx; i <= N; i++) {
		if (A[i] != n) {
			return i;
		}
	}
	return -1;
}

void solution() {
	int idx;

	idx = get_idx(A[1], 1);
	for (int i = 1; i <= N; i++) {
		if (A[i] == A[idx]) {
			idx = get_idx(A[i], i);
			cout << idx << " ";
		}
		else {
			cout << idx << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}