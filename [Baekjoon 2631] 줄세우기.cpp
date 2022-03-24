#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int N;
int order[201];
int dp[201];

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> order[i];
}

void solution()
{
	int tmp = 1;

	// 1. Base case
	for (int i = 1; i <= N; i++)
		dp[i] = 1;

	// 2. Dynamic programming
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (order[j] < order[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		tmp = max(tmp, dp[i]);
	}

	// 3. Find the solution
	cout << N - tmp;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	input();
	solution();

	return 0;
}
