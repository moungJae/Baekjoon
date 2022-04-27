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
char Map[51][51];
int parent[2501];
bool visited[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void input() {
	string s;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= N; j++) {
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

bool compare(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
	return x.second < y.second;
}

int trans(int x, int y) {
	return (x - 1) * N + y;
}

void init_visited(bool visited[][51]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int start_x, int start_y, vector<pair<pair<int, int>, int>>& info) {
	queue<pair<pair<int, int>, int>> Q;

	init_visited(visited);
	Q.push({ { start_x, start_y }, 0 });
	visited[start_x][start_y] = true;
	while (!Q.empty()) {
		int x = Q.front().first.first, y = Q.front().first.second;
		int dist = Q.front().second;
		Q.pop();

		if (!(start_x == x && start_y == y) && (Map[x][y] == 'S' || Map[x][y] == 'K')) {
			info.push_back({ {trans(start_x,start_y), trans(x,y)}, dist });
		}
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i], next_y = y + dy[i];
			if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N) {
				if (!visited[next_x][next_y] && Map[next_x][next_y] != '1') {
					visited[next_x][next_y] = true;
					Q.push({ { next_x,next_y }, dist + 1 });
				}
			}
		}
	}
}

void set_path(vector<pair<pair<int, int>, int>> &info) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Map[i][j] == 'S' || Map[i][j] == 'K') {
				bfs(i, j, info);
			}
		}
	}

	sort(info.begin(), info.end(), compare);
}

void solution() {
	vector<pair<pair<int, int>, int>> info;
	int connected = 0, result = 0;
	
	for (int i = 1; i <= N * N; i++) {
		parent[i] = i;
	}
	set_path(info);
	for (int i = 0; i < info.size(); i++) {
		int x = info[i].first.first, y = info[i].first.second;
		int c = info[i].second;

		if (get_parent(x, parent) != get_parent(y, parent)) {
			go_union(x, y, parent);
			connected++;
			result += c;
		}
	}
	if (connected == M) cout << result;
	else cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}