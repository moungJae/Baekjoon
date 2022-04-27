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

int N, M;
char Map[1001][1001];
bool visited[1001][1001];
int parent[1000001];

void input() {
	string s;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) {
			Map[i][j] = s[j - 1];
		}
	}
}

int get_parent(int x, int parent[]) {
	if (x == parent[x])
		return x;
	return (parent[x] = get_parent(parent[x], parent));
}

void go_union(int x, int y, int parent[]) {
	x = get_parent(x, parent);
	y = get_parent(y, parent);
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

void bfs(int start_x, int start_y) {
	queue<pair<int, int>> Q;

	Q.push({ start_x, start_y });
	visited[start_x][start_y] = true;
	while (!Q.empty()) {
		int x = Q.front().first, y = Q.front().second;
		Q.pop();

		int next_x = 0, next_y = 0;
		if (Map[x][y] == 'U') {
			next_x = x - 1, next_y = y;
		}
		else if (Map[x][y] == 'D') {
			next_x = x + 1, next_y = y;
		}
		else if (Map[x][y] == 'L') {
			next_x = x, next_y = y - 1;
		}
		else if (Map[x][y] == 'R') {
			next_x = x, next_y = y + 1;
		}
		
		if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M ) {
			if (!visited[next_x][next_y]) {
				Q.push({ next_x, next_y });
				visited[next_x][next_y] = true;
			}
			if (get_parent((x - 1) * M + y, parent) != get_parent((next_x - 1) * M + next_y, parent)) {
				go_union((x - 1) * M + y, (next_x - 1) * M + next_y, parent);
			}
		}
	}
}

void solution() {
	int result = 0;

	for (int i = 1; i <= N * M; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
			}
		}
	}
	map<int, bool> check;
	for (int i = 1; i <= N * M; i++) {
		int x = get_parent(i, parent);
		if (!check[x]) {
			check[x] = true;
			result++;
		}
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