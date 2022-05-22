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
string s;

void input() {
	cin >> N >> s;
}

bool f(string s) {
	for (int i = 0; i < 4; i++) {
		if (abs(s[i] - s[i + 1]) != 1)
			return false;
	}
	return true;
}

void solution() {
	for (int i = 0; i <= N - 5; i++) {
		string tmp = s.substr(i, 5);
		if (f(tmp)) {
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}