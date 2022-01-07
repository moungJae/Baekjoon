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

int N;
ll A[1000001];

void test() {
	ll sum, max_item, tmp, cnt;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	max_item = A[N - 1], sum = cnt = tmp = 0;
	for (int i = N - 2; i >= 0; i--) {
		if (A[i] < max_item) {
			tmp += A[i], cnt++;
		}
		else {
			sum += max_item * cnt - tmp;
			max_item = A[i], tmp = 0, cnt = 0;
		}
	}
	if (cnt) sum += max_item * cnt - tmp;
	cout << sum << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) test();

	return 0;
}