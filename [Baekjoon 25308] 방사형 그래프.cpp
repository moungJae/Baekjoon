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

vector<int> order = { 0, 1, 2, 3, 4, 5, 6, 7 };
int a[8];

void input() {
	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}
}

bool check_block(int x, int y, int z) {
	double x_d = (double)x;
	double y_d = (double)y * sqrt(2.0) / 2.0;
	double z_d = (double)z;

	if (y_d + (z_d / x_d) * y_d - z_d >= 0)
		return true;
	return false;
}

bool is_block() {
	int x, y, z;

	for (int i = 0; i < 8; i++) {
		x = a[order[i]];
		y = a[order[(i + 1) % 8]];
		z = a[order[(i + 2) % 8]];

		if (!check_block(x, y, z))
			return false;
	}

	return true;
}

void solution() {
	int ans = 0;

	do {
		if (is_block()) ans++;
	} while (next_permutation(order.begin(), order.end()));

	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}