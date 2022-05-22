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

int T;
string s[101][4];

void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> s[i][0] >> s[i][1] >> s[i][2] >> s[i][3];
	}
}

bool f(vector<string> v) {
	string s1, s2, s3, s4;
	
	// case 1
	s1 = v[0], s2 = v[1], s3 = v[2];
	if (s1[1] == s2[1] && s1[1] == s3[1] && s2[1] == s3[1]
		&& s1[0] + 1 == s2[0] && s2[0] + 1 == s3[0])
		return true;
	s1 = v[1], s2 = v[2], s3 = v[3];
	if (s1[1] == s2[1] && s1[1] == s3[1] && s2[1] == s3[1]
		&& s1[0] + 1 == s2[0] && s2[0] + 1 == s3[0])
		return true;
	// case 2
	s1 = v[0], s2 = v[1], s3 = v[2];
	if (s1[1] == s2[1] && s1[1] == s3[1] && s2[1] == s3[1]
		&& s1[0] == s2[0] && s1[0] == s3[0] && s2[0] == s3[0])
		return true;
	s1 = v[1], s2 = v[2], s3 = v[3];
	if (s1[1] == s2[1] && s1[1] == s3[1] && s2[1] == s3[1]
		&& s1[0] == s2[0] && s1[0] == s3[0] && s2[0] == s3[0])
		return true;
	// case 3
	s1 = v[0], s2 = v[1], s3 = v[2], s4 = v[3];
	if (s1[0] == s2[0] && s1[1] == s2[1] && s3[0] == s4[0] && s3[1] == s4[1])
		return true;
	return false;
}

void solution() {
	vector<string> v;

	for (int i = 0; i < T; i++) {
		bool op = false;

		v.clear();
		v.push_back(s[i][0]), v.push_back(s[i][1]);
		v.push_back(s[i][2]), v.push_back(s[i][3]);
		sort(v.begin(), v.end());
		do {
			if (f(v)) op = true;
		} while (next_permutation(v.begin(), v.end()));
		if (op) cout << ":)" << endl;
		else cout << ":(" << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}