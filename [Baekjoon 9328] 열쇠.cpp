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

int h, w;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char Map[101][101];
bool key[26];
bool visited[101][101];
vector<pair<int, int>> out_v;

void input() {
	string s;

	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		cin >> s;
		for (int j = 1; j <= w; j++) {
			Map[i][j] = s[j - 1];
		}
	}
	cin >> s;
	for (int i = 0; i < 26; i++)
		key[i] = false;
	for (char c : s) 
		key[c - 'a'] = true;
}

void init() {
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			visited[i][j] = false;
		}
	}
}

int bfs() {
	queue<pair<int, int>> Q;
	vector<pair<int, int>> tmp[26];
	int cnt = 0;

	init();
	for (pair<int, int> p : out_v) {
		int x = p.first, y = p.second;
		if (Map[x][y] == '.') {
			Q.push({ x, y });
			visited[x][y] = true;
		}
		else if (Map[x][y] >= 'A' && Map[x][y] <= 'Z') {
			if (key[Map[x][y] - 'A']) {
				Q.push({ x, y });
				visited[x][y] = true;
			}
			else {
				tmp[Map[x][y] - 'A'].push_back({ x, y });
			}
		}
		else if (Map[x][y] >= 'a' && Map[x][y] <= 'z') {
			key[Map[x][y] - 'a'] = true;
			Q.push({ x, y });
			visited[x][y] = true;
		}
		else if (Map[x][y] == '$') {
			Map[x][y] = '.';
			Q.push({ x, y });
			visited[x][y] = true;
			cnt++;
		}
	}

	while (!Q.empty()) {
		int x = Q.front().first, y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i], next_y = y + dy[i];
			if (next_x >= 1 && next_x <= h && next_y >= 1 && next_y <= w && !visited[next_x][next_y]) {
				if (Map[next_x][next_y] == '.') {
					Q.push({ next_x, next_y });
					visited[next_x][next_y] = true;
				}
				else if (Map[next_x][next_y] >= 'A' && Map[next_x][next_y] <= 'Z') {
					if (key[Map[next_x][next_y] - 'A']) {
						Q.push({ next_x, next_y });
						visited[next_x][next_y] = true;
					}
					else {
						tmp[Map[next_x][next_y] - 'A'].push_back({ next_x, next_y });
					}
				}
				else if (Map[next_x][next_y] >= 'a' && Map[next_x][next_y] <= 'z') {
					key[Map[next_x][next_y] - 'a'] = true;
					Q.push({ next_x, next_y });
					visited[next_x][next_y] = true;
					for (pair<int, int> p : tmp[Map[next_x][next_y] - 'a']) {
						Q.push({ p.first, p.second });
						visited[p.first][p.second] = true;
					}
				}
				else if (Map[next_x][next_y] == '$') {
					Map[next_x][next_y] = '.';
					Q.push({ next_x, next_y });
					visited[next_x][next_y] = true;
					cnt++;
				}
			}
		}
	}

	return cnt;
}

void solution() {
	out_v.clear();
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (i == 1 || i == h || j == 1 || j == w) {
				if (Map[i][j] != '*')
					out_v.push_back({ i, j });
			}
		}
	}
	cout << bfs() << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int test;
	
	cin >> test;
	while (test--) {
		input();
		solution();
	}

	return 0;
}