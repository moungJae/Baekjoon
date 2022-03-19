#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
int parent[1001];
bool visited[1001];
vector<pair<int, pair<int, int>>> v;

void input()
{
	int x, y, dist;

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> x;
		visited[x] = true;
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> dist;
		v.push_back({ dist, {x, y} });
	}
}

int get_parent(int x, int parent[])
{
	if (x == parent[x])
		return x;
	return (parent[x] = get_parent(parent[x], parent));
}

void go_union(int x, int y, int parent[])
{
	x = get_parent(x, parent);
	y = get_parent(y, parent);
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

bool compare(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y)
{
	return x.first < y.first;
}

void solution()
{
	int total = 0;

	for (int i = 1; i <= N; i++) {
		if (visited[i]) parent[i] = 0;
		else parent[i] = i;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].second.first, y = v[i].second.second;
		int dist = v[i].first;
		if (get_parent(x, parent) != get_parent(y, parent)) {
			go_union(x, y, parent);
			total += dist;
		}
	}
	cout << total;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}