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

int X, N;
int a[100], b[100];

void input() {
	cin >> X;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i] >> b[i];
}

void solution() {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += a[i] * b[i];
	}
	if (sum == X)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}