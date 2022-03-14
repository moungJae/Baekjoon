#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int Map[501][501];
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int result[1001];
int me_x, me_y;
bool visited[501][501];

void input()
{
	int x, y;

	cin >> N >> M;
	cin >> me_x >> me_y;
	for (int i = 1; i <= M; i++)
	{
		cin >> x >> y;
		Map[x][y] = i;
	}
}

bool is_in(int x, int y)
{
	return (x >= 1 && x <= N && y >= 1 && y <= N);
}

void solve()
{
	queue<pair<int, pair<int, int>>> Q;

	Q.push({ 0, {me_x, me_y} });
	visited[me_x][me_y] = true;
	while (!Q.empty())
	{
		int x = Q.front().second.first, y = Q.front().second.second;
		int dist = Q.front().first;
		Q.pop();
		if (Map[x][y])
			result[Map[x][y]] = dist;
		for (int i = 0; i < 8; i++)
		{
			int next_x = x + dx[i], next_y = y + dy[i];
			if (is_in(next_x, next_y) && !visited[next_x][next_y])
			{
				visited[next_x][next_y] = true;
				Q.push({ dist + 1, {next_x, next_y} });
			}
		}
	}

	for (int i = 1; i <= M; i++)
		cout << result[i] << " ";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solve();

	return (0);
}