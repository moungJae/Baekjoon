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

string S, T;
vector<int> v[26];
int idx[26];

void input() {
	cin >> S >> T;
}

void solution() {
	int cnt = 0, before;
	bool op;

	for (int i = 0; i < S.size();i++) {
		char c = S[i];
		v[c - 'a'].push_back(i);
	}
	while (1) {
		op = true;
		before = -1;
		for (char c : T) {
			if (before == -1) {
				if (idx[c - 'a'] == v[c - 'a'].size()) {
					op = false;
					break;
				}
				before = v[c - 'a'][idx[c - 'a']++];
			}
			else {
				while (idx[c - 'a'] != v[c - 'a'].size() && before > v[c - 'a'][idx[c - 'a']]) {
					idx[c - 'a']++;
				}
				if (idx[c - 'a'] == v[c - 'a'].size()) {
					op = false;
					break;
				}
				before = v[c - 'a'][idx[c - 'a']++];
			}
		}
		if (!op) break;
		cnt++;
	}
	cout << cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}