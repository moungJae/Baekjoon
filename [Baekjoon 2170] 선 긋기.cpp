#define _CRT_SECURE_NO_WARNINGS
#include <string>
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
int x[1000001][2];
int a[2000001];
vector<int> point;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x[i][0] >> x[i][1];
		point.push_back(x[i][0]), point.push_back(x[i][1]);
	}
}

bool compare1(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
	return x.first.first < y.first.first;
}

bool compare2(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
	return x.first.second < y.first.second;
}

void make_distance(vector<int> &dist) {
	int from;
	
	sort(point.begin(), point.end());
	from = point[0];
	for (int i = 1; i < point.size(); i++) {
		if (point[i] == from)
			continue;
		dist.push_back(point[i] - from);
		from = point[i];
	}
}

void coordinate_compression(vector<pair<pair<int, int>, int>> &coord) {
	int num = 0;

	for (int i = 1; i <= N; i++) {
		coord.push_back({ {x[i][0], ++num}, -1 });
		coord.push_back({ {x[i][1], ++num}, -1 });
	}
	sort(coord.begin(), coord.end(), compare1);
	num = 0;
	coord[0].second = ++num;
	for (int i = 1; i < coord.size(); i++) {
		if (coord[i].first.first == coord[i - 1].first.first) {
			coord[i].second = num;
			continue;
		}
		coord[i].second = ++num;
	}
	sort(coord.begin(), coord.end(), compare2);
}

void solution() {
	int length = 0;
	vector<pair<pair<int,int>, int>> coord;
	vector<int> dist;

	make_distance(dist);
	coordinate_compression(coord);
	for (int i = 0; i < 2 * N; i += 2) {
		a[coord[i].second] += 1;
		a[coord[i + 1].second] -= 1;
	}
	for (int i = 2; i <= 2 * N; i++) {
		a[i] += a[i - 1];
	}
	for (int i = 1; i < 2 * N; i++) {
		if (a[i]) {
			length += dist[i - 1];
		}
	}
	cout << length;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}