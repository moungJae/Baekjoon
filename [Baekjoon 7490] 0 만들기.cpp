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
char op[10];

void input() {
	cin >> N;
}

bool is_zero(string s) {
	int ans, idx;
	int arr[10];
	char real_op[10];

	idx = 1;
	for (int i = 0; i < s.size(); i++) {
		int n = 0;
		while (i < s.size() && (s[i] >= '0' && s[i] <= '9')) {
			n = 10 * n + (s[i++] - '0');
		}
		if (i < s.size()) real_op[idx] = s[i];
		arr[idx++] = n;
	}

	ans = arr[1];
	for (int i = 1; i < idx - 1; i++) {
		if (real_op[i] == '+')
			ans = ans + arr[i + 1];
		else
			ans = ans - arr[i + 1];
	}

	return ans == 0;
}

string operate_string(char op[]) {
	string ret = "";
	
	for (int i = 1; i < N; i++) {
		if (op[i] == ' ') {
			ret += to_string(i);
		}
		else {
			ret += to_string(i) + op[i];
		}
	}
	ret += to_string(N);

	return ret;
}

string result_string(char op[]) {
	string ret = "";

	for (int i = 1; i < N; i++) {
		ret += to_string(i) + op[i];
	}
	ret += to_string(N);

	return ret;
}

void dfs(int idx, vector<string> &v) {
	if (idx == N) {
		string s;

		s = operate_string(op);
		if (is_zero(s)) {
			v.push_back(result_string(op));
		}
		return;
	}

	op[idx] = '+';
	dfs(idx + 1, v);

	op[idx] = '-';
	dfs(idx + 1, v);
	
	op[idx] = ' ';
	dfs(idx + 1, v);
}

void solution() {
	vector<string> v;

	dfs(1, v);
	sort(v.begin(), v.end());
	for (string s : v)
		cout << s << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		input();
		solution();
		if (T != 0) cout << "\n";
	}

	return 0;
}