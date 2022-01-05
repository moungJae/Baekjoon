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

	string A, B;
	int cnt = 0;
	getline(cin, A), getline(cin, B);
	for (int i = 0; i < A.size(); i++) {
		if (A.substr(i, B.size()) == B) {
			cnt++;
			i += B.size() - 1;
		}
	}
	cout << cnt;

	return 0;
}