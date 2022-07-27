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
#include <set>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int A, B, C;
bool visited[201][201][201];
set<int> ans;

void input() {
	cin >> A >> B >> C;
}

void dfs(int a, int b, int c) {
	if (visited[a][b][c])
		return;

	visited[a][b][c] = true;
	if (a == 0) ans.insert(c);
	
	if (a + b > A) dfs(A, b - (A - a), c);
	else dfs(a + b, 0, c);

	if (a + c > A) dfs(A, b, c - (A - a));
	else dfs(a + c, b, 0);

	if (a + b > B) dfs(a - (B - b), B, c);
	else dfs(0, a + b, c);

	if (a + c > C) dfs(a - (C - c), b, C);
	else dfs(0, b, a + c);

	if (b + c > B) dfs(a, B, c - (B - b));
	else dfs(a, b + c, 0);

	if (b + c > C) dfs(a, b - (C - c), C);
	else dfs(a, 0, b + c);
}

void solution() {
	dfs(0, 0, C);
	for (int x : ans) {
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