#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int Map[26][26];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void input()
{
	string s;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
			Map[i][j] = (s[j] - '0');
	}
}

bool is_in(int x, int y)
{
	return (x >= 0 && x <= N && y >= 0 && y <= N);
}

void bfs(int s_x, int s_y, vector<int>& v)
{
	queue<pair<int, int>> Q;
	int how = 0;

	Q.push({ s_x,s_y });
	Map[s_x][s_y] = 0, how++;
	while (!Q.empty())
	{
		int x = Q.front().first, y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i], next_y = y + dy[i];
			if (is_in(next_x, next_y) && Map[next_x][next_y])
			{
				Map[next_x][next_y] = 0, how++;
				Q.push({ next_x, next_y });
			}
		}
	}
	v.push_back(how);
}

void solve()
{
	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j])
				bfs(i, j, v);
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int x : v)
		cout << x << " ";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solve();

	return (0);
}