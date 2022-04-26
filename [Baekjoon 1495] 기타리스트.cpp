#define _CRT_SECURE_NO_WARNINGS
#include <string>
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

int N, S, M;
int volume[51];
bool dp[51][1001];

void input() {
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++)
		cin >> volume[i];
}

void solution() {
	int result = -1;

	dp[0][S] = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (dp[i - 1][j]) {
				if (j - volume[i] >= 0) dp[i][j - volume[i]] = true;
				if (j + volume[i] <= M) dp[i][j + volume[i]] = true;
			}
		}
	}
	for (int i = 0; i <= 1000; i++) {
		if (dp[N][i])
			result = max(result, i);
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