#include <iostream>
#include <queue>

using namespace std;

#define ll long long
#define INF 1000000000000

int N, M;
vector<pair<int, ll>> v[100001];
ll D[100001];
int visited[100001];

void input()
{
	int from, to;
	ll dist;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> visited[i];
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
		v[to].push_back({ from, dist });
	}
}

void solution()
{
	priority_queue<pair<ll, int>> PQ;
	for (int i = 1; i <= N; i++) D[i] = INF;
	PQ.push({ 0, 0 });
	D[0] = 0;
	while (!PQ.empty()) {
		int cur = PQ.top().second;
		ll dist = -PQ.top().first;
		PQ.pop();
		if (D[cur] < dist) continue;
		for (pair<int, ll> p : v[cur]) {
			int next = p.first;
			ll next_dist = dist + p.second;
			if ((next == N - 1 || !visited[next]) && next_dist < D[next]) {
				D[next] = next_dist;
				PQ.push({ -next_dist, next });
			}
		}
	}
	cout << (D[N - 1] == INF ? -1 : D[N - 1]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}