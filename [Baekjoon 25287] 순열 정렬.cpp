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

int T, N;
int a[50001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
}

void solution() {
	a[1] = min(a[1], N - a[1] + 1);
	for (int i = 2; i <= N; i++) {
		if (a[i - 1] <= a[i]) {
			if (a[i - 1] <= N - a[i] + 1) {
				a[i] = min(a[i], N - a[i] + 1);
			}
			continue;
		}
		a[i] = max(a[i], N - a[i] + 1);
		if (a[i - 1] > a[i]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		input();
		solution();
	}

	return 0;
}