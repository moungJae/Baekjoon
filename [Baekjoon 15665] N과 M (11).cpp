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

void print_X(int chk, deque<int> DQ) {
	if (chk == M) {
		while (!DQ.empty()) {
			cout << DQ.front() << " ";
			DQ.pop_front();
		}
		cout << endl;
		return;
	}
	
	DQ.push_back(X[0]);
	print_X(chk + 1, DQ);
	DQ.pop_back();
	for (int i = 1; i < N; i++) {
		if (X[i] == X[i - 1]) continue;
		DQ.push_back(X[i]);
		print_X(chk + 1, DQ);
		DQ.pop_back();
	}
}

void solution() {
	deque<int> DQ;
	sort(X, X + N);
	print_X(0, DQ);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();
	
	return 0;
}