#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N;
int a[10], b[10];
ll p[10], q[10];
ll result[10];
vector<pair<int, pair<ll, ll>>> v[10];
bool visited[10];

void input() {
	cin >> N;
	for (int i = 0; i < N - 1; i++)
		cin >> a[i] >> b[i] >> p[i] >> q[i];
}

void bfs(int start) {
	queue<int> Q;

	visited[start] = true;
	Q.push(start);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			ll x = v[cur][i].second.first;
			ll y = v[cur][i].second.second;

			if (!visited[next]) {
				visited[next] = true;
				if (result[cur] == 0) {
					result[cur] = x, result[next] = y;
				}
				else if (result[cur] == x) {
					result[next] = y;
				}
				else if (result[cur] != x) {
					result[next] = result[cur] * y;
					result[cur] = result[cur] * x;
					for (int t = 0; t < N; t++) {
						if (t == cur || t == next)
							continue;
						if (visited[t])
							result[t] = result[t] * x;
					}
				}
				Q.push(next);
			}				
		}
	}
}

void make_result(ll result[]) {
	ll div = 0;

	for (int i = 0; i < N; i++) {
		div = max(div, result[i]);
	}

	for (ll i = 2; i <= sqrt(div); i++) {
		bool op = true;
		for (int j = 0; j < N; j++) {
			if (result[j] % i != 0) {
				op = false;
				break;
			}
		}
		while (op) {
			for (int j = 0; j < N; j++) {
				result[j] /= i;
				if (result[j] % i != 0)
					op = false;
			}
		}
	}
}

void solution() {
	for (int i = 0; i < N - 1; i++) {
		v[a[i]].push_back({ b[i], {p[i], q[i]} });
		v[b[i]].push_back({ a[i], {q[i], p[i]} });
	}

	bfs(a[0]);
	make_result(result);
	for (int i = 0; i < N; i++)
		cout << result[i] << " ";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}