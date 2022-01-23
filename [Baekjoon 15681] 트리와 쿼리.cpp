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

vector<int> tree[100001];
int N, R, Q;
bool visited[100001];

void input() {
	int u, v;
	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
}

void tree_traversal(int x, vector<int>& v) {
	if (tree[x].size() == 1 && x != R) {
		return;
	}
	visited[x] = true;
	for (int next : tree[x]) {
		if (!visited[next]) {
			tree_traversal(next, v);
			v[x] += v[next];
		}
	}
}

void solution() {
	vector<int> result(N + 1, 1);
	int query;

	tree_traversal(R, result);
	while (Q--) {
		cin >> query;
		cout << result[query] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}