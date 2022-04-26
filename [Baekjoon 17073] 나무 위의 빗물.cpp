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

int N, W;
vector<int> v[500001];

void input() {
	int from, to;
	cin >> N >> W;
	for (int i = 1; i <= N - 1; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
}

void tree_traversal(int x, int before, int& cnt) {
	if (v[x].size() == 1 && before != -1) {
		cnt++;
		return;
	}

	for (int next : v[x]) {
		if (next == before)
			continue;
		tree_traversal(next, x, cnt);
	}
}

void solution() {
	int cnt = 0;
	tree_traversal(1, -1, cnt);
	printf("%.6f", (double)W / (double)cnt);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}