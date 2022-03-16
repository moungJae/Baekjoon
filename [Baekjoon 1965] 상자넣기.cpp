#include <iostream>

#define ll long long

using namespace std;

int n;
int box[1001];
int dp[1001];

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> box[i];
}

void solution()
{
	int result = 1;

	// base case
	for (int i = 1; i <= n; i++)
		dp[i] = 1;

	// dynamic programming
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (box[j] < box[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		result = max(result, dp[i]);
	}
	cout << result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}