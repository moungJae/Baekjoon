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

int N, M;
int semester[1001], inDegree[1001];
vector<int> v[1001];

void input() {
	int from, to;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		inDegree[to]++;
	}
}

void solution() {
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		semester[i] = 1;
		if (inDegree[i] == 0) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i];
			semester[next] = max(semester[next], semester[x] + 1);
			if (--inDegree[next] == 0) {
				Q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++) cout << semester[i] << " ";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}