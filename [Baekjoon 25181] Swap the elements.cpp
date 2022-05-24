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
int A[5001], B[5001];
int check[100001];
bool visited[5001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
}

bool compare(pair<int, int> x, pair<int, int> y) {
	return x.first > y.first;
}

void solution() {
	vector<pair<int, int>> v;

	for (int i = 1; i <= N; i++) {
		check[A[i]]++;
	}
	for (int i = 1; i <= N; i++) {
		v.push_back({ check[A[i]], i });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 1; i <= 100000; i++) {
		if (check[i] > N / 2) {
			cout << -1;
			return;
		}
	}
	int idx = 2;
	for (int i = 0; i < N; i++) {
		int cmp = A[v[i].second];
		while (cmp == A[idx] || B[idx]) {
			idx++;
			if (idx == N + 1) idx = 1;
		}
		B[idx] = cmp;
		idx++;
		if (idx == N + 1) idx = 1;
	}
	for (int i = 1; i <= N; i++)
		cout << B[i] << " ";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}