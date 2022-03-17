#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int>> v[50001];
int D[50001];

void input()
{
	int from, to, dist;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
		v[to].push_back({ from, dist });
	}
}

void solution()
{
	priority_queue<pair<int, int>> PQ;
	for (int i = 1; i <= N; i++) D[i] = 1e9;
	PQ.push({ 0, 1 });
	D[1] = 0;
	while (!PQ.empty()) {
		int cur = PQ.top().second, dist = -PQ.top().first;
		PQ.pop();
		if (D[cur] < dist) continue;
		for (pair<int, int> p : v[cur]) {
			int next = p.first, next_dist = dist + p.second;
			if (next_dist < D[next]) {
				D[next] = next_dist;
				PQ.push({ -next_dist, next });
			}
		}
	}
	cout << D[N];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}