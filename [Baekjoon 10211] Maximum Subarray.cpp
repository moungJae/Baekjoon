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

int N;
int arr[1001], dp[1001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
}

void init() {
	for (int i = 1; i <= N; i++)
		dp[i] = 0;
}

void solution() {
	int result;
	init();
	dp[1] = arr[1], result = arr[1];
	for (int i = 2; i <= N; i++) {
		if (arr[i] > dp[i - 1] + arr[i]) {
			dp[i] = arr[i];
		}
		else {
			dp[i] = dp[i - 1] + arr[i];
		}
		result = max(result, dp[i]);
	}
	cout << result << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		input();
		solution();
	}

	return 0;
}