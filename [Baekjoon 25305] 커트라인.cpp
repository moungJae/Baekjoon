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

int N, k;
int x[1000];

void input() {
	cin >> N >> k;
	for (int i = 0; i < N; i++)
		cin >> x[i];
}

bool compare(int x, int y) {
	return x > y;
}

void solution() {
	sort(x, x + N, compare);
	cout << x[k - 1];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}