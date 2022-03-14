#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<int> v[101];
bool visited[101];

void input()
{
	int from, to;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
}

void dfs(int x, int *cnt)
{
	if (visited[x])
		return;
	visited[x] = true;
	if (x != 1) *cnt += 1;
	for (int next : v[x])
	{
		dfs(next, cnt);
	}
}

void solve()
{
	int result = 0;
	dfs(1, &result);
	cout << result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solve();

	return (0);
}