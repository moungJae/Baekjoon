#include <iostream>

using namespace std;

int N, M, K;
int cost[10001], parent[10001];
bool visited[10001];

int get_parent(int x)
{
	if (x == parent[x])
		return x;
	return (parent[x] = get_parent(parent[x]));
}

void join(int x, int y)
{
	int c;
	x = get_parent(x), y = get_parent(y);
	c = cost[x] < cost[y] ? cost[x] : cost[y];
	cost[x] = cost[y] = c;
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

void input()
{
	int v, w;

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		parent[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		cin >> v >> w;
		if (get_parent(v) != get_parent(w)) {
			join(v, w);
		}
	}
}

void solution()
{
	int c = 0;

	for (int i = 1; i <= N; i++) {
		int x = get_parent(i);
		if (!visited[x]) {
			visited[x] = true;
			c += cost[x];
		}
	}
	if (c <= K)
		cout << c;
	else
		cout << "Oh no";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	input();
	solution();

	return 0;
}
