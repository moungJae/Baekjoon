#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int Map[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void input()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];
}

bool is_in(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < M);
}

bool all_tomato()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!Map[i][j])
				return false;
	return true;
}

void solve()
{
	queue<pair<int, pair<int, int>>> Q;
	int day = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Map[i][j] == 1)
				Q.push({ 0, {i,j} });
	while (!Q.empty())
	{
		int x = Q.front().second.first, y = Q.front().second.second;
		int cur_day = Q.front().first;
		Q.pop();
		
		day = max(day, cur_day);
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i], next_y = y + dy[i];
			if (is_in(next_x, next_y) && !Map[next_x][next_y])
			{
				Map[next_x][next_y] = 1;
				Q.push({ cur_day + 1, {next_x, next_y} });
			}
		}
	}
	
	if (all_tomato()) cout << day;
	else cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solve();

	return (0);
}