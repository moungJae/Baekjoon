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

int N, M;
int X[9];
bool check[9];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> X[i];
}

void print_X(int idx, int chk) {
	if (chk == M) {
		for (int i = 0; i < N; i++) {
			if (check[i]) cout << X[i] << " ";
		}
		cout << endl;
		return;
	}
	if (idx == N) return;
	check[idx] = true;
	print_X(idx + 1, chk + 1);
	check[idx] = false;
	print_X(idx + 1, chk);
}

void solution() {
	sort(X, X + N);
	print_X(0, 0);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();
	
	return 0;
}