#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll N, M;
	cin >> N >> M;
	if (N == 1) {
		cout << 1;
	}
	else if (N == 2) {
		if (M == 1 || M == 2) cout << 1;
		else if (M == 3 || M == 4) cout << 2;
		else if (M == 5 || M == 6) cout << 3;
		else cout << 4;
	}
	else {
		if (M <= 6) {
			if (M == 1) cout << 1;
			else if (M == 2) cout << 2;
			else if (M == 3) cout << 3;
			else cout << 4;
		}
		else {
			cout << 4 + (M - 6);
		}
	}

	return 0;
}