#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <math.h>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N;
vector<int> v[10001];
int w[10001], dp[10001][2];
bool visited[10001];
vector<int> path;

void input() {
	int from, to;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= N - 1; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
}

void dfs(int cur) {
	dp[cur][0] = 0;
	dp[cur][1] = w[cur];

	visited[cur] = true;

	for (int next : v[cur]) {
		if (visited[next])
			continue;
		dfs(next);
		dp[cur][0] += max(dp[next][0], dp[next][1]);
		dp[cur][1] += dp[next][0];
	}
}

void find_path(int cur, int prev) {
	if (dp[cur][1] > dp[cur][0] && !visited[prev]) {
		path.push_back(cur);
		visited[cur] = true;
	}

	for (int next: v[cur]) {
		if (next == prev)
			continue;
		find_path(next, cur);
	}
}

void solution() {
	dfs(1);
	memset(visited, 0, N);
	find_path(1, 0);
	sort(path.begin(), path.end());
	cout << max(dp[1][0], dp[1][1]) << endl;
	for (int x : path) {
		cout << x << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}