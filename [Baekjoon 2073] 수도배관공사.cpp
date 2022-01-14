#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int D, P;
int L[351], C[351];
int pre[100001], cur[100001];

void input() {
	cin >> D >> P;
	for (int i = 1; i <= P; i++) {
		cin >> L[i] >> C[i];
	}
}

void solution() {
	for (int i = 1; i <= P; i++) {
		for (int j = 1; j <= D; j++) {
			if (j < L[i]) {
				continue;
			}
			if (j == L[i]) {
				cur[j] = max(cur[j], C[i]);
			}
			else if (j > L[i] && pre[j - L[i]]) {
				cur[j] = max(cur[j], min(pre[j - L[i]], C[i]));
			}
		}
		for (int j = 1; j <= D; j++) pre[j] = cur[j];
	}
	cout << cur[D];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}