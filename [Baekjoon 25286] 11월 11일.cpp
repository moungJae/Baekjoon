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

int T;
int y[1213], m[1213];

void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> y[i] >> m[i];
	}
}

void solution() {
	for (int i = 0; i < T; i++) {
		if (m[i] == 3) {
			if ((y[i] % 100 != 0 && y[i] % 4 == 0) || (y[i] % 400 == 0))
				cout << y[i] << " " << 2 << " " << 29 << endl;
			else
				cout << y[i] << " " << 2 << " " << 28 << endl;
		}
		else if (m[i] == 1) {
			cout << y[i] - 1 << " " << 12 << " " << 31 << endl;
		}
		else if (m[i] == 2 || m[i] == 4 || m[i] == 6 || m[i] == 8 || m[i] == 9 || m[i] == 11) {
			cout << y[i] << " " << m[i] - 1 << " " << 31 << endl;
		}
		else {
			cout << y[i] << " " << m[i] - 1 << " " << 30 << endl;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}