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
char MBTI[201][201];

void input() {
	string s;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) {
			MBTI[i][j] = s[j - 1];
		}
	}
}

bool is_MBTI(queue<char> Q) {
	string s = "";

	while (!Q.empty()) {
		s += Q.front();
		Q.pop();
	}

	if ((s[0] == 'E' || s[0] == 'I') && (s[1] == 'N' || s[1] == 'S') &&
		(s[2] == 'F' || s[2] == 'T') && (s[3] == 'P' || s[3] == 'J'))
		return true;
	
	reverse(s.begin(), s.end());
	if ((s[0] == 'E' || s[0] == 'I') && (s[1] == 'N' || s[1] == 'S') &&
		(s[2] == 'F' || s[2] == 'T') && (s[3] == 'P' || s[3] == 'J'))
		return true;
	
	return false;
}

bool is_MBTI(string s) {
	if ((s[0] == 'E' || s[0] == 'I') && (s[1] == 'N' || s[1] == 'S') &&
		(s[2] == 'F' || s[2] == 'T') && (s[3] == 'P' || s[3] == 'J'))
		return true;

	reverse(s.begin(), s.end());
	if ((s[0] == 'E' || s[0] == 'I') && (s[1] == 'N' || s[1] == 'S') &&
		(s[2] == 'F' || s[2] == 'T') && (s[3] == 'P' || s[3] == 'J'))
		return true;

	return false;
}


void solution() {
	int ans = 0;

	// 1. 좌우
	for (int i = 1; i <= N; i++) {
		queue<char> Q;

		for (int j = 1; j <= 3; j++) {
			Q.push(MBTI[i][j]);
		}
		for (int j = 4; j <= M; j++) {
			Q.push(MBTI[i][j]);
			ans += (is_MBTI(Q) == true ? 1 : 0);
			Q.pop();
		}
	}

	// 2. 위아래
	for (int i = 1; i <= M; i++) {
		queue<char> Q;

		for (int j = 1; j <= 3; j++) {
			Q.push(MBTI[j][i]);
		}
		for (int j = 4; j <= N; j++) {
			Q.push(MBTI[j][i]);
			ans += (is_MBTI(Q) == true ? 1 : 0);
			Q.pop();
		}
	}

	// 3. 대각선 - 1
	for (int i = 1; i <= M - 3; i++) {
		for (int j = 1; j <= N - 3; j++) {
			string s = "";

			for (int k = 0; k < 4; k++) {
				s += MBTI[j + k][i + k];
			}
			ans += (is_MBTI(s) == true ? 1 : 0);
		}
	}

	// 4. 대각선 - 2
	for (int i = 4; i <= M; i++) {
		for (int j = 1; j <= N - 3; j++) {
			string s = "";

			for (int k = 0; k < 4; k++) {
				s += MBTI[j + k][i - k];
			}
			ans += (is_MBTI(s) == true ? 1 : 0);
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