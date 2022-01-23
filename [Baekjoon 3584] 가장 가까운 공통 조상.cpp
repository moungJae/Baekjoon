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
int parent[10001];
bool visited[10001];

void initialize() {
	for (int i = 0; i <= 10000; i++) {
		parent[i] = 0;
		visited[i] = false;
	}
}

void input() {
	int A, B;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B;
		parent[B] = A;
	}
}

void move_parent(int cur, vector<int>& v) {
	if (!parent[cur]) {
		v.push_back(cur);
		return;
	}
	v.push_back(cur);
	move_parent(parent[cur], v);
}

void solution() {
	vector<int> v1, v2;
	int x, y;

	cin >> x >> y;
	move_parent(x, v1), move_parent(y, v2);
	for (int i = 0; i < v1.size(); i++) visited[v1[i]] = true;
	for (int i = 0; i < v2.size(); i++) {
		if (visited[v2[i]]) {
			cout << v2[i] << endl;
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		initialize();
		input();
		solution();
	}

	return 0;
}