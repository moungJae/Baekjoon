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
char X[10];
bool check[10];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i];
}

void Backtracking(int chk, string number, vector<string>& v) {
	if (chk == N) {
		v.push_back(number);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (check[i]) continue;
		if (X[chk] == '<') {
			if ((number[chk] - '0') < i) {
				check[i] = true;
				Backtracking(chk + 1, number + to_string(i), v);
				check[i] = false;
			}
		}
		else {
			if ((number[chk] - '0') > i) {
				check[i] = true;
				Backtracking(chk + 1, number + to_string(i), v);
				check[i] = false;
			}
		}
	}
}

void solution() {
	vector<string> v;
	for (int i = 0; i <= 9; i++) {
		check[i] = true;
		Backtracking(0, to_string(i), v);
		check[i] = false;
	}

	sort(v.begin(), v.end());
	cout << v[v.size() - 1] << endl;
	cout << v[0] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();
	
	return 0;
}