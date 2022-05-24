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
string s1, s2;

void input() {
	cin >> N;
	cin >> s1 >> s2;
}

bool check(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void solution() {
	string ss1 = "", ss2 = "";
	map<char, int> m1, m2;

	if (s1[0] == s2[0] && s1[N - 1] == s2[N - 1]) {
		for (int i = 0; i < N; i++) {
			m1[s1[i]]++, m2[s2[i]]++;
			if (!check(s1[i])) ss1 += s1[i];
			if (!check(s2[i])) ss2 += s2[i];
		}
		for (char c = 'a'; c <= 'z'; c++) {
			if (m1[c] != m2[c]) {
				cout << "NO";
				return;
			}
		}
		if (ss1 == ss2) cout << "YES";
		else cout << "NO";
	}
	else {
		cout << "NO";
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}