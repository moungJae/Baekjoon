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
ll X[500001];
bool check[500001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i];
	sort(X, X + N);
	ll sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += abs(i - X[i - 1]);
	}
	cout << sum;

	return 0;
}