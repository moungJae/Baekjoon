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

int n;
double s_x, s_y, e_x, e_y;
double x[102], y[102];
double T[102];

void input() {
	cin >> s_x >> s_y;
	cin >> e_x >> e_y;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
}

double get_time(int cur, int next, bool check) {
	double t = sqrt(pow(x[cur] - x[next], 2) + pow(y[cur] - y[next], 2));

	if (check) {
		return 2.0 + abs(50.0 - t) / 5.0;
	}
	else
		return t / 5.0;
}

void dijkstra() {
	priority_queue<pair<double, int>> PQ;
	int start = 0, end = n + 1;

	for (int i = 1; i <= end; i++)
		T[i] = INF;
	PQ.push({ 0.0, start });
	while (!PQ.empty()) {
		double t = -PQ.top().first;
		int cur = PQ.top().second;

		PQ.pop();
		if (t > T[cur]) continue;
		for (int next = 0; next <= n + 1; next++) {
			if (next == cur) continue;
			double next_t = t + get_time(cur, next, cur >= 1 && cur <= n);
			if (next_t < T[next]) {
				T[next] = next_t;
				PQ.push({ -next_t, next });
			}
		}
	}
}

void solution() {
	x[0] = s_x, y[0] = s_y, x[n + 1] = e_x, y[n + 1] = e_y;
	dijkstra();
	printf("%.6lf", T[n + 1]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}