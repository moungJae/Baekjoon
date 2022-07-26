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

vector<int> tree[500001];
int n;

void input() {
	int from, to;

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}
}

int dfs(int cur, int before, int depth) {
	if (cur == 1) {
		int ret = 0;

		for (int next : tree[cur]) {
			ret += dfs(next, cur, depth + 1);
		}
		return ret;
	}
	else {
		bool op = false;
		int ret = 0;

		for (int next : tree[cur]) {
			if (next == before) continue;
			op = true;
			ret += dfs(next, cur, depth + 1);
		}
		if (!op) return depth;
		else return ret;
	}
}

void solution() {
	int check = dfs(1, 0, 0);

	if (check % 2) cout << "Yes";
	else cout << "No";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}