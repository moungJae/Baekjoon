#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int people[10001], dp[10001];
vector<int> v[10001];

void input()
{
	int from, to;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> people[i];
	for (int i = 1; i <= N - 1; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
}

int dfs(int cur, int before)
{
	if (v[cur].size() == 1 && before != 0) {
		dp[cur] = people[cur];
		return dp[cur];
	}

	int next_value = 0, next_next_value = people[cur];
	for (int next : v[cur]) {
		if (next == before)
			continue;
		next_value += dfs(next, cur);
		for (int next_next : v[next]) {
			if (next_next == cur)
				continue;
			next_next_value += dp[next_next];
		}
	}
	dp[cur] = max(next_value, next_next_value);
	return dp[cur];
}

void solution()
{
	int x = 0;

	for (int i = 1; i <= N; i++) {
		if (v[i].size() == 1)
			x = i;
	}
	dfs(x, 0);
	cout << dp[x];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	input();
	solution();

	return 0;
}
