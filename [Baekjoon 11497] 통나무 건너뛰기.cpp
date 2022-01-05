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

void test() {
	int n, x;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int gap = max(v[1] - v[0], v[v.size() - 1] - v[v.size() - 2]);
	for (int i = 2; i < n; i += 2) {
		gap = max(gap, abs(v[i] - v[i - 2]));
	}
	for (int i = 3; i < n; i += 2) {
		gap = max(gap, abs(v[i] - v[i - 2]));
	}
	cout << gap << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) test();

	return 0;
}