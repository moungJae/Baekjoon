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

int N, K, result;
string S[51];
vector<char> v;
bool visited[26];
int p;

void input() {
	map<char, bool> m;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		S[i] = S[i].substr(4, S[i].size());
		S[i] = S[i].substr(0, S[i].size() - 4);
	}
}

void dfs(int cur, char c) {
	if (cur == K) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			bool ok = true;
			for (int j = 0; j < S[i].size(); j++) {
				if (!visited[S[i][j] - 'a']) {
					ok = false;
					break;
				}
			}
			if (ok) cnt++;
		}
		result = max(result, cnt);
		return;
	}

	for (char t = c; t <= 'z'; t += 1) {
		if (visited[t - 'a']) continue;
		visited[t - 'a'] = true;
		dfs(cur + 1, t);
		visited[t - 'a'] = false;
	}
}

void solution() {
	if (K < 5) cout << 0;
	else if (K == 26) cout << N;
	else {
		visited[0] = visited['n' - 'a'] = visited['t' - 'a'] = visited['i' - 'a'] = visited['c' - 'a'] = true;
		K -= 5;
		dfs(0, 'b');
		cout << result;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}