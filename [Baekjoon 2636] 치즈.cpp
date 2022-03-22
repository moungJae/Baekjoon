#include <iostream>
#include <queue>

using namespace std;

int N, M;
int Map[102][102];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[102][102];

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> Map[i][j];
}

bool check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Map[i][j])
				return true;
		}
	}
	return false;
}

void init() {
	for (int i = 0; i <= N + 1; i++)
		for (int j = 0; j <= M + 1; j++)
			visited[i][j] = false;
}

bool is_in(int x, int y) {
	return (x >= 0 && x <= N + 1 && y >= 0 && y <= M + 1);
}

void solution()
{
	int t = 0, before;
	while (check()) {
		t++;
		before = 0;
		init();
		queue<pair<int, int>> Q;
		Q.push({ 0, 0 });
		visited[0][0] = true;
		while (!Q.empty()) {
			int x = Q.front().first, y = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++) {
				int next_x = x + dx[i], next_y = y + dy[i];
				if (is_in(next_x, next_y) && !visited[next_x][next_y] && !Map[next_x][next_y]) {
					visited[next_x][next_y] = true;
					Q.push({ next_x,next_y });
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (Map[i][j]) before++;
				for (int k = 0; k < 4; k++) {
					int next_x = i + dx[k], next_y = j + dy[k];
					if (visited[next_x][next_y])
						Map[i][j] = 0;
				}
			}
		}
	}
	cout << t << endl;
	cout << before;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}