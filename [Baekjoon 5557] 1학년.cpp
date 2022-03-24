#include <iostream>
#define ll long long

using namespace std;

int N;
int arr[101];
ll dp[101][21];

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
}

void solution()
{
	// 1. Base case
	dp[1][arr[1]] = 1;

	// 2. Dynamic Programming
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j + arr[i] >= 0 && j + arr[i] <= 20)
				dp[i][j + arr[i]] += dp[i - 1][j];
			if (j - arr[i] >= 0 && j - arr[i] <= 20)
				dp[i][j - arr[i]] += dp[i - 1][j];
		}
	}

	// 3. Find the solution
	cout << dp[N - 1][arr[N]];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	input();
	solution();

	return 0;
}
