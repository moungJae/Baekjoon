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

int N, M, C;
int S[100001];
vector<pair<int, int>> v[100001];
int inDegree[100001];

void input() {
	int a, b, x;

	cin >> N >> M >> C;
	for (int i = 1; i <= N; i++)
		cin >> S[i];
	for (int i = 0; i < C; i++) {
		cin >> a >> b >> x;
		v[a].push_back({ b, x });
		inDegree[b]++;
	}
}

void solution() {
	queue<int> Q;

	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			Q.push(i);
	}

	while (!Q.empty()) {
		int cur = Q.front();
		
		Q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int day = v[cur][i].second;

			S[next] = max(S[next], S[cur] + day);
			if (--inDegree[next] == 0) {
				Q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << S[i] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}