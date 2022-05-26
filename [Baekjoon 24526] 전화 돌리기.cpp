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

int N, M;
vector<int> v[100001];
bool visited[100001][2], cycle[100001];

void input() {
	int U, V;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> U >> V;
		v[U].push_back(V);
	}
}

bool dfs(int x) {
	if (v[x].size() == 0) {
		visited[x][0] = true;
		visited[x][1] = false;
		return false;
	}
	if (visited[x][0]) {
		if (visited[x][1] || cycle[x]) 
			return true;
		else 
			return false;
	}
	visited[x][0] = visited[x][1] = true;
	for (int next : v[x]) {
		cycle[x] |= dfs(next);
	}
	visited[x][1] = false;
	return cycle[x];
}

void solution() {
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (visited[i][0]) continue;
		dfs(i);
	}
	for (int i = 1; i <= N; i++) {
		if (!cycle[i]) ans++;
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}