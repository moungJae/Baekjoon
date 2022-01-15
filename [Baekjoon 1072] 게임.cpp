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
#include <time.h>
#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

ll X, Y;

void input() {
	cin >> X >> Y;
}

void solution() {
	ll mid, low, high, Z, ans;
	Z = (Y * 100) / X;

	ans = INF + 1;
	// 이길 경우 (Z' > Z)
	low = 0, high = INF;
	while (low <= high) {
		mid = (low + high) / 2;
		if (((Y + mid) * 100) / (X + mid) > Z) {
			ans = min(ans, mid);
			high = mid - 1;
		}
		else low = mid + 1;
	}

	if (ans > INF) cout << -1;
	else cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}