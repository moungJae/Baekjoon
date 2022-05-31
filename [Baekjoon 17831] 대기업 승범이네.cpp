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
vector<int> v[200001];
ll A[200001], dp[200001];

void input() {
	int parent;

	cin >> N;
	for (int child = 2; child <= N; child++) {
		cin >> parent;
		v[parent].push_back(child);
	}
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
}

ll tree_traversal(int cur) {
	vector<pair<ll, pair<ll, ll>>> info;
	ll cur_ret, next_ret, next_next_ret;
	ll ret;

	if (v[cur].size() == 0)
		return A[cur];
	for (int next : v[cur]) {
		if (v[next].size() == 0) {
			cur_ret = A[cur] * tree_traversal(next);
			info.push_back({ cur_ret, {0,0} });
		}
		else {
			cur_ret = A[cur] * A[next];
			next_ret = tree_traversal(next);
			next_next_ret = 0;
			for (int next_next : v[next]) {
				next_next_ret += dp[next_next];
			}
			info.push_back({ cur_ret, {next_ret, next_next_ret} });
		}
	}

	ret = 0;
	for (int i = 0; i < info.size(); i++) {
		ret += info[i].second.first;
	}
	dp[cur] = ret;
	for (int i = 0; i < info.size(); i++) {
		dp[cur] = max(dp[cur], ret - info[i].second.first 
			+ info[i].first + info[i].second.second);
	}
	
	return dp[cur];
}

void solution() {
	cout << tree_traversal(1) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}