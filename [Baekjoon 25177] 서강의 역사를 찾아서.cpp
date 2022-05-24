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
int a[1001], b[1001];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	for (int i = 1; i <= M; i++)
		cin >> b[i];
}

void solution() {
	int ans = 0;

	for (int i = 1; i <= M; i++) {
		if (b[i] > a[i]) {
			ans = max(ans, b[i] - a[i]);
		}
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}