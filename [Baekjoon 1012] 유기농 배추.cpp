#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int Map[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void init()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			Map[i][j] = 0;
}

void input()
{
	int x, y;

	cin >> M >> N >> K;
	init();
	for (int i = 0; i < K; i++)
	{
		cin >> y >> x;
		Map[x][y] = 1;
	}
}

bool is_in(int x, int y)
{
	return (x >= 0 && x <= N && y >= 0 && y <= M);
}

void bfs(int s_x, int s_y)
{
	queue<pair<int, int>> Q;
	
	Q.push({ s_x, s_y });
	Map[s_x][s_y] = 0;
	while (!Q.empty())
	{
		int x = Q.front().first, y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i], next_y = y + dy[i];
			if (is_in(next_x, next_y) && Map[next_x][next_y])
			{
				Map[next_x][next_y] = 0;
				Q.push({ next_x, next_y });
			}
		}
	}
}

int solve()
{
	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j])
			{
				ret++;
				bfs(i, j);
			}
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int test;
	cin >> test;
	while (test--)
	{
		input();
		cout << solve() << '\n';
	}

	return (0);
}