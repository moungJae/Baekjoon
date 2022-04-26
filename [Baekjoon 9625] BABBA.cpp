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
ll fibo[46][2];
const int A = 0, B = 1;

void input() {
	cin >> N;
}

void solution() {
	fibo[2][A] = fibo[1][B] = fibo[2][B] = 1;
	for (int i = 3; i <= N; i++) {
		fibo[i][A] = fibo[i - 1][A] + fibo[i - 2][A];
		fibo[i][B] = fibo[i - 1][B] + fibo[i - 2][B];
	}
	cout << fibo[N][A] << " " << fibo[N][B];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}