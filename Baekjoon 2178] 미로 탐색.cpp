#include <iostream>
#include <queue>

using namespace std;

int N, M;
int Map[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void input()
{
	string s;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
			Map[i][j] = (s[j] - '0');
	}
}

bool is_in(int x, int y)
{
	return (x >= 0 && x <= N && y >= 0 && y <= M);
}

void solve()
{
	priority_queue<pair<int, pair<int, int>>> PQ;

	PQ.push({ -1, {0, 0} });
	Map[0][0] = 0;
	while (!PQ.empty())
	{
		int dist = -PQ.top().first;
		int x = PQ.top().second.first, y = PQ.top().second.second;
		PQ.pop();

		if (x == N - 1 && y == M - 1)
		{
			cout << dist;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i], next_y = y + dy[i];
			if (is_in(next_x, next_y) && Map[next_x][next_y])
			{
				Map[next_x][next_y] = 0;
				PQ.push({ -(dist + 1), {next_x, next_y} });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solve();

	return (0);
}