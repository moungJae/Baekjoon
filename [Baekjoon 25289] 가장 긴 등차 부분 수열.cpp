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
int A[100001];
int visited[101][201];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
}

void solution() {
	int ans = 0;

	for (int d = -100; d <= 100; d++) {
		for (int i = 1; i <= N; i++) {
			if (d == 0) {
				if (!visited[A[i]][d + 100])
					visited[A[i]][d + 100] = 1;
				else {
					visited[A[i]][d + 100]++;
				}
			}
			else {
				visited[A[i]][d + 100] = max(1, visited[A[i]][d + 100]);
				if (A[i] - d >= 1 && A[i] - d <= 100) {
					if (visited[A[i] - d][d + 100]) {
						visited[A[i]][d + 100] = max(visited[A[i]][d + 100], visited[A[i] - d][d + 100] + 1);
					}
				}
			}
		}
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 200; j++) {
			ans = max(ans, visited[i][j]);
		}
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}