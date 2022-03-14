#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> v[1001];
bool visited[1001];

void input()
{
	int from, to;

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
}

void init()
{
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}

void dfs(int x)
{
	if (visited[x])
		return;
	visited[x] = true;
	cout << x << " ";
	for (int next : v[x])
		dfs(next);
}

void bfs(int start)
{
	queue<int> Q;
	
	Q.push(start);
	visited[start] = true;
	while (!Q.empty())
	{
		int x = Q.front();
		cout << x << " ";
		Q.pop();
		for (int next : v[x])
		{
			if (!visited[next])
			{
				visited[next] = true;
				Q.push(next);
			}
		}
	}
}

void solve()
{
	for (int i = 1; i <= N; i++)
	{
		if (v[i].size()) sort(v[i].begin(), v[i].end());
	}
	dfs(V);
	cout << endl;
	init();
	bfs(V);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solve();

	return (0);
}