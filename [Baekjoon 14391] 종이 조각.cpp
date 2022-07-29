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
int A[4][4];
bool visited[4][4];

void input() {
	string s;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			A[i][j] = s[j] - '0';
		}
	}
}

int dfs(int x, int y) {
	int result = 0;

	if (y == M) {
		if (x == N - 1) {
			int temp, sum;

			sum = 0;
			for (int i = 0; i < N; i++) {
				temp = 0;
				for (int j = 0; j < M; j++) {
					if (!visited[i][j]) {
						sum += temp;
						temp = 0;
					}
					else {
						temp = 10 * temp + A[i][j];
					}
				}
				sum += temp;
			}

			for (int j = 0; j < M; j++) {
				temp = 0;
				for (int i = 0; i < N; i++) {
					if (visited[i][j]) {
						sum += temp;
						temp = 0;
					}
					else {
						temp = 10 * temp + A[i][j];
					}
				}
				sum += temp;
			}

			return sum;
		}
		else {
			return dfs(x + 1, 0);
		}
	}
	
	visited[x][y] = true;
	result = max(result, dfs(x, y + 1));
	
	visited[x][y] = false;
	result = max(result, dfs(x, y + 1));
	
	return result;
}

void solution() {
	cout << dfs(0, 0);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}