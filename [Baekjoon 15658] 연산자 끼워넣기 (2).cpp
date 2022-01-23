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

int A[12];
int op[4]; // +, -, *, /
int N;
char operation[12];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < 4; i++) cin >> op[i];
}

void BackTracking(int idx, int op1, int op2, int op3, int op4, vector<int> &v) {
	if (idx == N - 1) {
		int result = A[0];
		for (int i = 1; i < N; i++) {
			switch (operation[i - 1]) {
				case '+': result = result + A[i];
					break;
				case '-': result = result - A[i];
					break;
				case '*': result = result * A[i];
					break;
				case '/': result = result / A[i];
					break;
			}
		}
		v.push_back(result);
		return;
	}
	
	if (op1 < op[0]) {
		operation[idx] = '+';
		BackTracking(idx + 1, op1 + 1, op2, op3, op4, v);
	}
	if (op2 < op[1]) {
		operation[idx] = '-';
		BackTracking(idx + 1, op1, op2 + 1, op3, op4, v);
	}
	if (op3 < op[2]) {
		operation[idx] = '*';
		BackTracking(idx + 1, op1, op2, op3 + 1, op4, v);
	}
	if (op4 < op[3]) {
		operation[idx] = '/';
		BackTracking(idx + 1, op1, op2, op3, op4 + 1, v);
	}
}

void solution() {
	vector<int> v;
	BackTracking(0, 0, 0, 0, 0, v);
	cout << *max_element(v.begin(), v.end()) << endl;
	cout << *min_element(v.begin(), v.end());
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}