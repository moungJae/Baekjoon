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
vector<int> v[400001];
vector<string> ans[400001];
vector<string> answer;
map<string, int> m;
string mm[400001];
int inDegree[400001];
int item_cnt;

void input() {
	string from, to;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> from >> to;
		if (!m[from]) {
			m[from] = ++item_cnt;
			mm[item_cnt] = from;
		}
		if (!m[to]) {
			m[to] = ++item_cnt;
			mm[item_cnt] = to;
		}
		v[m[from]].push_back(m[to]);
		inDegree[m[to]]++;
	}
}

void solution() {
	queue<string> Q;
	int cnt = 0;

	for (int i = 1; i <= item_cnt; i++) {
		if (inDegree[i] == 0)
			Q.push(mm[i]);
	}

	while (1) {
		queue<string> tmp;

		while (!Q.empty()) {
			string cur = Q.front();

			ans[cnt].push_back(cur);
			Q.pop();
			for (int next : v[m[cur]]) {
				if (--inDegree[next] == 0) {
					tmp.push(mm[next]);
				}
			}
		}

		cnt++;

		if (tmp.empty()) 
			break;
		while (!tmp.empty()) {
			string cur = tmp.front();

			Q.push(cur);
			tmp.pop();
		}
	}

	for (int i = 0; i < cnt; i++) {
		sort(ans[i].begin(), ans[i].end());
		for (string s : ans[i])
			answer.push_back(s);
	}

	if (answer.size() == item_cnt) {
		for (string s : answer) {
			cout << s << endl;
		}
	}
	else {
		cout << -1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}